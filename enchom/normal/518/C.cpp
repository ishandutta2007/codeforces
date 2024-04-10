#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int n,m,k;
int screen[110001];

int pos[110001];

void Fix(int icon)
{
    if (pos[icon]==1)
    return;

    int preceding=screen[ pos[icon]-1 ];
    int d;

    d=screen[ pos[icon] ];
    screen[ pos[icon] ]=screen[ pos[icon]-1 ];
    screen[ pos[icon]-1 ]=d;

    pos[icon]--;
    pos[preceding]++;

    return;
}

Int GetCost(int icon)
{
    return (Int)((pos[icon]-1)/k+1);
}

int main()
{
    int i;
    Int cost=0;
    int icon;

    scanf("%d %d %d",&n,&m,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&screen[i]);

        pos[ screen[i] ]=i;
    }

    for (i=1;i<=m;i++)
    {
        scanf("%d",&icon);
        cost+=GetCost(icon);
        Fix(icon);
    }

    printf("%lld\n",cost);

    return 0;
}