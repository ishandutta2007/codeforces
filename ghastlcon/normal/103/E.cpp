#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <tuple>
#define N 620
using namespace std;

vector<pair<int, long long> > d;
vector<int> e[N];
int l[N], r[N];
char o[N];

bool LevelDinic(int s, int t)
{
    int i, k;
    queue<int> q;

    memset(l, 0, sizeof(l));
    l[s] = 1;

    for(q.push(s); !q.empty(); q.pop())
    {
        s = q.front();
        for(i = 0; i < (signed)e[s].size(); i ++)
        {
            k = e[s][i];
            if(d[k].second && !l[d[k].first])
            {
                l[d[k].first] = l[s] + 1;
                q.push(d[k].first);
            }
        }
    }

    return l[t];
}

long long BlockDinic(int x, int t, long long v)
{
    int k;
    long long f;

    if(x == t || !v)
        return v;

    for(f = 0; r[x] < (signed)e[x].size(); r[x] ++)
    {
        k = e[x][r[x]];
        if(d[k].second && l[d[k].first] == l[x] + 1 && (f = BlockDinic(d[k].first, t, min(d[k].second, v))))
        {
            d[k    ].second -= f;
            d[k ^ 1].second += f;
            break;
        }
    }

    return f;
}

long long Dinic(int s, int t)
{
    long long o, f;

    for(o = 0; LevelDinic(s, t); )
    {
        memset(r, 0, sizeof(r));
        while((f = BlockDinic(s, t, LLONG_MAX)))
            o += f;
    }

    return o;
}

void AddEdge(int u, int v, long long w)
{
    // printf("%d->%d(%lld)\n", u, v, w);
    e[u].push_back(d.size());
    d.push_back(make_pair(v, w));
    e[v].push_back(d.size());
    d.push_back(make_pair(u, 0));

    return;
}

int main(void)
{
    int n, m, x;
    int i;
    long long s;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &m);
        while(m --)
        {
            scanf("%d", &x);
            AddEdge(i, x + n, LLONG_MAX);
        }
        AddEdge(i + n, n + n + 1, INT_MAX);
    }

    for(i = 1, s = 0; i <= n; i ++)
    {
        scanf("%d", &x);
        AddEdge(0, i, (long long)INT_MAX - x);
        s += (long long)INT_MAX - x;
    }
    printf("%lld\n", Dinic(0, n + n + 1) - s);

    return 0;
}