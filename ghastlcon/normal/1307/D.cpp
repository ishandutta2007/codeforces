#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <utility>
#define N 200020
using namespace std;

class Node
{
public:
    Node *s[2];
    int v;

    Node(void) : v(INT_MIN >> 2)
    {
        s[0] = s[1] = NULL;

        return;
    }
};

int a[N];
vector<int> e[N];
int f[N], g[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
Node *r;

void Dijkstra(int n, int s, int *d)
{
    int i;

    for(i = 1; i <= n; i ++)
        d[i] = INT_MAX >> 2;
    d[s] = 0;

    for(q.push(make_pair(0, s)); !q.empty(); q.pop())
        if(d[s = q.top().second] == q.top().first)
            for(i = 0; i < (signed)e[s].size(); i ++)
                if(d[e[s][i]] > d[s] + 1)
                {
                    d[e[s][i]] = d[s] + 1;
                    q.push(make_pair(d[e[s][i]], e[s][i]));
                }

    return;
}

void SetSegment(Node *&x, int l, int r, int p, int v)
{
    int m;

    if(l > p || r < p)
        return;
    if(!x)
        x = new Node();
    if(l == r)
    {
        x -> v = max(x -> v, v);

        return;
    }

    m = (l + r) >> 1;
    SetSegment(x -> s[0], l    , m, p, v);
    SetSegment(x -> s[1], m + 1, r, p, v);
    x -> v = max(x -> s[0] ? x -> s[0] -> v : INT_MIN, x -> s[1] ? x -> s[1] -> v : INT_MIN);

    return;
}

int MaxSegment(Node *x, int l, int r, int s, int t)
{
    int m;

    if(!x || l > t || r < s)
        return INT_MIN >> 2;
    if(l >= s && r <= t)
        return x -> v;

    m = (l + r) >> 1;

    return max(MaxSegment(x -> s[0], l, m, s, t), MaxSegment(x -> s[1], m + 1, r, s, t));
}

int Solve(int n, int x, int y)
{
    int l, m, r;

    for(l = min(x, y), r = n + n + 1; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if(MaxSegment(::r, 0, n, max(0, m - y), n) >= m - x)
            l = m;
        else
            r = m;
    }

    return l;
}

int main(void)
{
    int n, m, k, u, v;
    int i, o;

    scanf("%d %d %d", &n, &m, &k);
    for(i = 1; i <= k; i ++)
        scanf("%d", &a[i]);
    while(m --)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    Dijkstra(n, 1, f);
    Dijkstra(n, n, g);

    for(i = 1, o = 0; i <= k; i ++)
    {
        if(i > 1)
            o = max(o, Solve(n, f[a[i]], g[a[i]]) + 1);
        SetSegment(r, 0, n, f[a[i]], g[a[i]]);
        // for(j = i + 1; j <= k; j ++)
        //     o = max(o, min(f[a[i]] + g[a[j]], f[a[j]] + g[a[i]]) + 1);
    }
    printf("%d\n", min(o, f[n]));

    return 0;
}