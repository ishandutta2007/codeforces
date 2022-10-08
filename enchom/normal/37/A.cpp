#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int Blocks[1001];
Int n;

int main()
{
    Int i;
    Int k;
    Int ctr=0;
    Int maxh=0;

    memset(Blocks,0,sizeof(Blocks));

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&k);

        if (Blocks[k]==0)
        {
            ctr++;
        }

        Blocks[k]++;

        if (Blocks[k]>maxh)
        maxh=Blocks[k];
    }

    printf("%I64d %I64d\n",maxh,ctr);

    return 0;
}