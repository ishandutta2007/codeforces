#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char str[101];

int main()
{
    Int i,j;
    Int n;
    Int L;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%s",str);
        L=strlen(str);
        
        if (L>10)
        {
            printf("%c%I64d%c",str[0],L-2,str[L-1]);
        }
        else
        {
            for (j=0;j<L;j++)
            {
                printf("%c",str[j]);
            }
        }
        printf("\n");
    }
    return 0;
}