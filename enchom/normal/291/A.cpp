#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int ID[1001];

int main()
{
    Int n;
    Int ctr=0;
    Int uk;
    Int i;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&ID[i]);
    }

    sort(ID+1,ID+1+n);

    uk=2;

    while(uk<=n)
    {
        if (ID[uk]==0)
        {
            uk++;
            continue;
        }
        if (ID[uk]==ID[uk-1])
        {
            if (ID[uk+1]!=ID[uk] || uk==n)
            {
                ctr++;
                uk+=2;
            }
            else
            {
                printf("-1\n");
                return 0;
            }
        }
        else
        {
            uk++;
        }
    }

    printf("%I64d\n",ctr);

    return 0;
}