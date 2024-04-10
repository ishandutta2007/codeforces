#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long llong;
typedef unsigned long long ullong;

llong B1 = 127LL;
llong MOD = 1000000009LL;

ullong B2 = 71LL;

llong gcd(llong a, llong b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    llong r;

    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int n, m;
vector<int> Graph[500111];
llong val[500111];

struct node
{
    pair<llong, ullong> h;
    llong v;

    bool operator<(const node &other) const
    {
        return h < other.h;
    }
};

node nodes[500111];

int main()
{
    int i,j,in;
    int t,test;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d",&n,&m);

        for (i=1;i<=n;i++)
        {
            scanf("%lld",&val[i]);
            Graph[i].clear();
        }

        for (i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            Graph[b].push_back(a);
        }

        for (i=1;i<=n;i++)
        {
            if (Graph[i].empty())
            {
                nodes[i].h = make_pair(0, 0);
                nodes[i].v = 0;
                continue;
            }

            sort(Graph[i].begin(), Graph[i].end());
            pair<llong, ullong> h = make_pair(0, 0);
            for (j=0;j<Graph[i].size();j++)
            {
                h.first = (h.first * B1 + (llong)Graph[i][j]) % MOD;
                h.second = h.second * B2 + (ullong)Graph[i][j];
            }
            nodes[i].h = h;
            nodes[i].v = val[i];
        }

        sort(nodes+1,nodes+1+n);

        llong ans = 0;
        pair<llong, ullong> cur = nodes[1].h;
        llong sum = nodes[1].v;
        for (i=2;i<=n;i++)
        {
            if (cur == nodes[i].h)
            {
                sum += nodes[i].v;
            }
            else
            {
                ans = gcd(ans, sum);

                sum = nodes[i].v;
                cur = nodes[i].h;
            }
        }

        ans = gcd(ans, sum);

        printf("%lld\n",ans);
    }

    return 0;
}