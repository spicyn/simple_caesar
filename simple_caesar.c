#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define alphabet_size 26
char *Encode(char *s, int key);
char *Decode(char *s, int key);


int main(int argc, char **argv)
{

    printf("Usage:<encode/decode> <text> <shift value>\n");
    

    if(argc ==4)
    {

        if(strcmp(argv[1],"encode") == 0)

        {
             int arg2 = atoi(argv[3]);
             printf("%s\n",Encode(argv[2], arg2) );
        }
        else if(strcmp(argv[1],"decode") == 0)
        {
             int arg2 = atoi(argv[3]);
             printf("%s\n",Decode(argv[2], arg2) );
        }

    }


else
    {
        printf("Please enter atleast three arguments!");
        return -1;
    }

    return 0;
}

char *Encode(char *s, int key){
    int i = 0;
    int real_shift;
    int nowy_key;
    if(key < 0 && key % alphabet_size !=0)
    {
       real_shift = abs(key / alphabet_size);
       printf("%d",real_shift);
       nowy_key = key + real_shift *alphabet_size;
       key = nowy_key;
    }
    else if (key % alphabet_size == 0 )
    {
        key = 0;
    }
    
    
    printf("shift value => %d \n",key);
    while(s[i] != '\0')
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {

            s[i] = 'a' + ( s[i]-'a'+key)%alphabet_size;
            if(s[i] < 'a')
            {
                s[i] = 'z' + ( s[i]-'z' +abs(key)+ key)%alphabet_size;
            }
            
        }
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = 'A' + ( s[i]-'A'+key)%alphabet_size;
            if(s[i] < 'A')
            {
                s[i] = 'Z' + ( s[i]-'Z' +abs(key)+key)%alphabet_size;
            }
        }
        i++;
    }
 
    return s;
}

char *Decode(char *s, int key){
    int i = 0;
    int real_shift;
    int nowy_key;
    if(key < 0 && key % alphabet_size !=0)
    {
       real_shift = abs(key / alphabet_size);
       printf("%d",real_shift);
       nowy_key = key + real_shift *alphabet_size;
       key = nowy_key;
    }
    else if (key % alphabet_size == 0 )
    {
        key = 0;
    }
   // key = -26 - key;
    
    printf("shift value => %d \n",key);
    while(s[i] != '\0')
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {

            s[i] = 'a' + ( s[i]-'a'-key)%alphabet_size;
            if(s[i] < 'a')
            {
                if(key<0)
                {
                    s[i] = 'z' + ( s[i]-'z' -abs(key)- key)%alphabet_size;
                }
                else{
                    s[i] = 'z' + ( s[i]-'z' +abs(key)- key)%alphabet_size;
                }
            }
            
        }
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = 'A' + ( s[i]-'A'-key)%alphabet_size;
            if(s[i] < 'A')
            {
                if(key <0)
                {
                    s[i] = 'Z' + ( s[i]-'Z' -abs(key)-key)%alphabet_size;
                }
                else {
                    s[i] = 'Z' + ( s[i]-'Z' +abs(key)-key)%alphabet_size;
                }
            }
        }
        i++;
    }
 
    return s;
}
