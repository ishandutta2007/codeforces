#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define N 100020
using namespace std;

class Node
{
public:
    Node *s[2];
    Node *p;
    Node *q;

    Node(void)
    {
        s[0] = s[1] = p = q = NULL;

        return;
    }

    bool Relation(void)
    {
        return this == p -> s[1];
    }
};

int n;
Node a[N];
vector<pair<int, int> > e[N];
vector<pair<long long, long long> > b[N];
long long c[N], d[N];
int l[N], r[N], p[N], f[N << 1];

void SetSegwin(int p, int v)
{
    for(f[p += n] = v; p >>= 1; )
        f[p] = max(f[p << 1], f[p << 1 | 1]);

    return;
}

int MaxSegwin(int l, int r)
{
    int o;

    for(o = 0, l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
            o = max(o, f[l ++]);
        if(r & 1)
            o = max(o, f[-- r]);
    }

    return o;
}

void RotateLCT(Node *x)
{
    Node *p;
    int k;

    p = x -> p;
    k = x -> Relation();

    x -> q = p -> q;
    p -> q = NULL;

    x -> p = p -> p;
    if(x -> p)
        x -> p -> s[p -> Relation()] = x;

    p -> s[k] = x -> s[!k];
    if(p -> s[k])
        p -> s[k] -> p = p;

    x -> s[!k] = p;
    p -> p = x;

    return;
}

void SplayLCT(Node *x)
{
    while(x -> p)
        if(x -> p -> p)
        {
            if(x -> Relation() == x -> p -> Relation())
                RotateLCT(x -> p);
            else
                RotateLCT(x);
            RotateLCT(x);
        }
        else
            RotateLCT(x);

    return;
}

void ExposeLCT(Node *x)
{
    SplayLCT(x);
    if(x -> s[1])
    {
        x -> s[1] -> q = x;
        x -> s[1] -> p = NULL;
        x -> s[1] = NULL;
    }

    return;
}

bool SpliceLCT(Node *x, int w)
{
    int p, t;

    SplayLCT(x);
    if(!x -> q)
        return false;

    p = (int)(x -> q - a);
    t = MaxSegwin(l[p], r[p]);
    b[p].push_back(make_pair(!t ? 1 : t + d[p] + 1, w + d[p]));

    ExposeLCT(x -> q);
    x -> q -> s[1] = x;
    x -> p = x -> q;
    x -> q = NULL;

    return true;
}

void AccessLCT(Node *x, int w)
{
    while(SpliceLCT(x, w))
        ;

    return;
}

void DFS(int x)
{
    static int k;
    int i, v;

    l[x] = k ++;
    for(i = 0; i < (signed)e[x].size(); i ++)
    {
        v = e[x][i].first;
        d[v] = d[x] + e[x][i].second;
        p[v] = x;
        if(i == (signed)e[x].size() - 1)
        {
            a[v].p = &a[x];
            a[x].s[1] = &a[v];
        }
        else
            a[v].q = &a[x];
        DFS(v);
    }
    r[x] = k - 1;

    return;
}

int main(void)
{
    int m, u, v, w;
    int i, j;
    long long t;
    vector<pair<long long, long long> > s;
    priority_queue<long long> r;
    priority_queue<long long, vector<long long>, greater<long long> > q;

    scanf("%d %d", &n, &m);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d %d", &u, &v, &w);
        e[u].push_back(make_pair(v, w));
    }

    DFS(1);
    while(m --)
    {
        scanf("%d %d", &u, &w);
        AccessLCT(&a[u], w);
        if(u != 1)
            SetSegwin(l[p[u]], w);
    }
    // for(i=1;i<=n;i++){for(pair<long long,long long>x:b[i])printf("[%lld,%lld] ",x.first,x.second);puts("");}

    for(i = 1; i <= n; i ++)
        for(j = 0; j < (signed)b[i].size(); j ++)
            s.push_back(b[i][j]);
    sort(s.begin(), s.end());

    for(t = 1, i = j = 0; i < (signed)s.size() || !q.empty(); )
    {
        for(; i < (signed)s.size() && s[i].first == t; i ++)
            q.push(s[i].second);

        if(!q.empty())
        {
            if(q.top() < t)
            {
                for(; !r.empty() && r.top() >= q.top(); r.pop())
                    j --;
                printf("%lld %d\n", q.top(), j);

                return 0;
            }
            j ++;
            r.push(q.top());
            q.pop();
        }

        if(q.empty())
        {
            if(i == (signed)s.size())
                break;
            t = s[i].first;
        }
        else
            t ++;
    }
    printf("-1 %d\n", (int)s.size());

    return 0;
}