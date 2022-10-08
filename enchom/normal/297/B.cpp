#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct fish
{
    Int thetype,value;
};

fish fishes[200001];
Int fL=0;

bool SortFish(fish a,fish b)
{
    return (a.thetype>b.thetype);
}

int main()
{
    Int n,m,k;
    Int total=0;
    Int i;
    Int fishtype;

    scanf("%I64d %I64d %I64d",&n,&m,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&fishtype);
        fL++;
        fishes[fL].thetype=fishtype;
        fishes[fL].value=1;
    }

    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&fishtype);
        fL++;
        fishes[fL].thetype=fishtype;
        fishes[fL].value=-1;
    }

    sort(fishes+1,fishes+1+fL,SortFish);

    for (i=1;i<=fL-1;i++)
    {
        total=total+fishes[i].value;

        if (fishes[i].thetype!=fishes[i+1].thetype)
        {
            if (total>0)
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    total=total+fishes[fL].value;
    if (total>0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}