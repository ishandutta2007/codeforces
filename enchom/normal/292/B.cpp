#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

vector<Int> Graph[100001];

int main()
{
    Int n,m;
    Int a,b;
    Int has1=0,has2=0;
    bool visitedcenter=false;
    Int i;

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (i=1;i<=n;i++)
    {
        if (Graph[i].size()==1)
        {
            has1++;
        }
        else if (Graph[i].size()==2)
        {
            has2++;
        }
    }

    if (has1==2 && has2==n-2)
    {
        printf("bus topology\n");
        return 0;
    }

    if (has1==0 && has2==n)
    {
        printf("ring topology\n");
        return 0;
    }

    for (i=1;i<=n;i++)
    {
        if (Graph[i].size()>1)
        {
            if (visitedcenter)
            {
                printf("unknown topology\n");
                return 0;
            }
            else
            {
                visitedcenter=true;
            }
        }
    }

    printf("star topology\n");

    return 0;
}