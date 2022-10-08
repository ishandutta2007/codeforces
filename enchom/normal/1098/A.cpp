#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

llong a[100111];
llong s[100111];
int n;
vector<int> Graph[100111];

bool DFS(int ver,int dad,int depth)
{
    int i;

    if (depth%2 == 1)
    {
        a[ver] = s[ver] - s[dad];

        if (a[ver] < 0)
            return false;
    }
    else
    {
        llong minsum = 100000000000LL;
        for (i=0;i<Graph[ver].size();i++)
        {
            if (Graph[ver][i] == dad)
                continue;

            if (s[ Graph[ver][i] ] < minsum)
                minsum = s[ Graph[ver][i] ];
        }

        if (minsum == 100000000000LL)
        {
            a[ver] = 0;
            s[ver] = s[dad];

            return true;
        }

        s[ver] = minsum;
        a[ver] = s[ver] - s[dad];

        if (a[ver] < 0)
            return false;
    }

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i] == dad)
            continue;

        if (!DFS(Graph[ver][i],ver,depth+1))
            return false;
    }

    return true;
}

int main()
{
    int i;

    scanf("%d",&n);

    for (i=2;i<=n;i++)
    {
        int p;

        scanf("%d",&p);

        Graph[p].push_back(i);
        Graph[i].push_back(p);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&s[i]);
    }

    if (!DFS(1,0,1))
    {
        printf("-1\n");
        return 0;
    }

    llong sum = 0;

    for (i=1;i<=n;i++)
    {
        sum += (llong)a[i];
    }

    printf("%lld\n",sum);

    return 0;
}