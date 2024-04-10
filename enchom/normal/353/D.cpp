#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char inp[1000001];
Int L;

int main()
{
    Int i;
    Int cur=1;
    Int ans=0;
    Int waiting=0;
    Int total;

    scanf("%s",inp+1);
    L=strlen(inp+1);

    for (i=1;i<=L;i++)
    {
        if (inp[i]=='F')
        {
            total=waiting+i-cur;

            if (ans<total)
            ans=total;

            cur++;

            if (total!=0)
            {
                waiting++;
            }
        }
        else
        {
            waiting--;
            if (waiting<0)
            waiting=0;
        }
    }

    printf("%I64d\n",ans);

    return 0;
}