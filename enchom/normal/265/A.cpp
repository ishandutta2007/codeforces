#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char s[51];
char t[51];
Int sL,tL;

int main()
{
    Int i;
    Int uk=0;
    
    scanf("%s",s);
    sL=strlen(s);
    scanf("%s",t);
    tL=strlen(t);
    
    for (i=0;i<tL;i++)
    {
        if (t[i]==s[uk])
        {
            uk++;
        }
    }
    printf("%I64d\n",uk+1);
    return 0;
}