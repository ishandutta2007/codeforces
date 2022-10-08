#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char commands[1000001];
Int L;
Int pos[1000001];

int main()
{
    Int i;
    Int uk1,uk2,reach=1;
    
    scanf("%s",commands);
    L=strlen(commands);
    
    uk2=L;
    uk1=1;
    
    for (i=0;i<L;i++)
    {
        if (commands[i]=='l')
        {
            pos[uk2]=reach;
            reach++;
            uk2--;
        }
        else
        {
            pos[uk1]=reach;
            reach++;
            uk1++;
        }
    }
    
    for (i=1;i<=L;i++)
    {
        printf("%I64d\n",pos[i]);
    }
    return 0;
}