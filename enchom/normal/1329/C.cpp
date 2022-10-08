#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long llong;

int t;
int h, g;
int n, m;

int heap[1200111];

vector<int> ans;

void f(int ver)
{
    int lc = 2*ver, rc = 2*ver+1;

    if (lc > n)
    {
        heap[ver] = 0;
        return;
    }

    if (heap[lc] == 0 && heap[rc] == 0)
    {
        heap[ver] = 0;
        return;
    }

    if (heap[lc] > heap[rc])
    {
        heap[ver] = heap[lc];
        f(lc);
    }
    else
    {
        heap[ver] = heap[rc];
        f(rc);
    }
}

int testF(int ver, int d)
{
    int lc = 2*ver, rc = 2*ver+1;

    if (lc > n)
    {
        return d;
    }

    if (heap[lc] == 0 && heap[rc] == 0)
    {
        return d;
    }

    if (heap[lc] > heap[rc])
    {
        return testF(lc, d+1);
    }
    else
    {
        return testF(rc, d+1);
    }
}

void solve(int ver, int depth)
{
    if (depth > g)
    {
        while(heap[ver] != 0)
        {
            f(ver);
            ans.push_back(ver);
        }
    }
    else
    {
        while(testF(ver, depth) > g)
        {
            f(ver);
            ans.push_back(ver);
        }

        solve(2*ver, depth+1);
        solve(2*ver+1, depth+1);
    }
}

int main()
{
    int i,j;
    int test;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d",&h,&g);

        n = (1<<h) - 1;
        m = (1<<g) - 1;

        for (i=1;i<=n;i++)
        {
            scanf("%d",&heap[i]);
        }

        ans.clear();
        solve(1, 1);

        llong sum = 0;

        for (i=1;i<=m;i++)
        {
            sum += (llong)heap[i];
        }

        printf("%lld\n",sum);

        for (i=0;i<ans.size();i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }

    return 0;
}