#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define N 100020
#define M 17
#define K 42
using namespace std;

extern vector<pair<int, int> > e[N];

class Dijkstra
{
public:
    long long d[N];
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;

    Dijkstra(void)
    {
        return;
    }

    void Calc(int n, int s)
    {
        int i;
        pair<long long, int> t;

        for(i = 0; i < n; i ++)
            d[i] = LLONG_MAX >> 2;
        d[s] = 0;

        for(q.push(make_pair(0, s)); !q.empty(); )
        {
            t = q.top();
            q.pop();
            if(d[t.second] == t.first)
                for(i = 0; i < (signed)e[t.second].size(); i ++)
                    if(d[e[t.second].at(i).first] > t.first + e[t.second].at(i).second)
                    {
                        d[e[t.second].at(i).first] = t.first + e[t.second].at(i).second;
                        q.push(make_pair(d[e[t.second].at(i).first], e[t.second].at(i).first));
                    }
        }

        return;
    }
};

vector<pair<int, int> > e[N];
vector<int> g;
bool u[N];
int f[M][N], d[N];
long long s[N];
Dijkstra h[K];

void DFS(int x, int p)
{
    int i;

    for(i = 1, f[0][x] = p; i < M; i ++)
        f[i][x] = f[i - 1][f[i - 1][x]];
    u[x] = true;

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x].at(i).first != p)
        {
            if(u[e[x].at(i).first])
            {
                g.push_back(x);
                g.push_back(e[x].at(i).first);
            }
            else
            {
                d[e[x].at(i).first] = d[x] + 1;
                s[e[x].at(i).first] = s[x] + e[x].at(i).second;
                DFS(e[x].at(i).first, x);
            }
        }

    return;
}

int GetLCA(int u, int v)
{
    int i, t;

    if(d[u] < d[v])
        swap(u, v);
    t = d[u] - d[v];

    for(i = 0; i < M; i ++)
        if(t & (1 << i))
            u = f[i][u];
    if(u == v)
        return u;

    for(i = M - 1; i > -1; i --)
        if(f[i][u] != f[i][v])
        {
            u = f[i][u];
            v = f[i][v];
        }

    return f[0][u];
}

inline long long SumChain(int u, int v)
{
    return s[u] + s[v] - (s[GetLCA(u, v)] << 1);
}

int main(void)
{
    int n, m, u, v, w;
    int i;
    long long o;

    scanf("%d %d", &n, &m);
    while(m --)
    {
        scanf("%d %d %d", &u, &v, &w);
        e[-- u].push_back(make_pair(-- v, w));
        e[   v].push_back(make_pair(   u, w));
    }
    DFS(0, 0);
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    // for(int x:g)cout<<x<<' ';cout<<endl;
    for(i = 0; i < (signed)g.size(); i ++)
        h[i].Calc(n, g.at(i));

    scanf("%d", &m);
    while(m --)
    {
        scanf("%d %d", &u, &v);
        o = SumChain(-- u, -- v);
        for(i = 0; i < (signed)g.size(); i ++)
            o = min(o, h[i].d[u] + h[i].d[v]);
        printf("%lld\n", o);
    }

    return 0;
}