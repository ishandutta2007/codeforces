#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    while(1)
    {
         scanf("%c",&c);
         if(c=='\n') break;
         c = tolower(c);
         
         if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
         else printf(".%c",c);
         
    }
    return 0;
}