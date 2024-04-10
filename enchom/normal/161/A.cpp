#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

struct cloth
{
    Int size,orgind;
};
struct chose
{
    Int soldier,clothe;
};
cloth clothes[100011];
cloth soldiers[100011];
chose chosen[100011];
Int cL=0;

bool SortEm(cloth a,cloth b)
{
    return (a.size<b.size);
}

int main()
{
    Int n,m,x,y;
    Int i,j;
    Int uk;
    
    scanf("%I64d %I64d %I64d %I64d",&n,&m,&x,&y);
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&soldiers[i].size);
        soldiers[i].orgind=i;
    }
    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&clothes[i].size);
        clothes[i].orgind=i;
    }
    sort(clothes+1,clothes+1+m,SortEm);
    sort(soldiers+1,soldiers+1+n,SortEm);
    uk=1;
    for (i=1;i<=n;i++)
    {
        while( soldiers[i].size-x>clothes[uk].size && uk<=m )
        uk++;
        
        if (uk>m)
        break;
        
        if (soldiers[i].size+y>=clothes[uk].size)
        {
            cL++;
            chosen[cL].soldier=soldiers[i].orgind;
            chosen[cL].clothe=clothes[uk].orgind;
            uk++;
        }
    }
    printf("%I64d\n",cL);
    for (i=1;i<=cL;i++)
    {
        printf("%I64d %I64d\n",chosen[i].soldier,chosen[i].clothe);
    }
    return 0;
}