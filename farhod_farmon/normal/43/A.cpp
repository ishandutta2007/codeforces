#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    int n,i,k1,k2;
    char s1[11];
    char s2[11];
    char s[11];
    
    scanf("%d",&n);
    scanf("%s",s1);
    k1 = 1;
    k2 = 0;
    for (i=2; i<=n; i++)
    {
        scanf("%s",s);
        if (strcmp(s,s1) == 0)
        {
           k1 = k1 + 1;      
        }else
        {
             strcpy(s2,s);
             k2 = k2 + 1;
        }
    }
    if (k1>k2)
    {
       puts(s1);          
    }
    else
    {
        puts(s2);    
    }
    return 0;    
}