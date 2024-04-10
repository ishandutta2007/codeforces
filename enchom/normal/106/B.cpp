#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

struct comp
{
    Int speed,ram,hdd,cost;
};

comp comps[101];

int main()
{
    Int n;
    Int i,j;
    bool outdated;
    Int mincost=999999999;
    Int mincomp=9999;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d %I64d %I64d",&comps[i].speed,&comps[i].ram,&comps[i].hdd,&comps[i].cost);
    }
    for (i=1;i<=n;i++)
    {
        outdated=false;
        for (j=1;j<=n;j++)
        {
            if (comps[i].speed<comps[j].speed && comps[i].ram<comps[j].ram && comps[i].hdd<comps[j].hdd)
            {
                outdated=true;
                break;
            }
        }
        if (!outdated)
        {
            if (mincost>comps[i].cost)
            {
                mincost=comps[i].cost;
                mincomp=i;
            }
            
        }
    }
    printf("%I64d\n",mincomp);
    return 0;
}