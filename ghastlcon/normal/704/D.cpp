#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <map>
#define N 200020
using namespace std;

class Edge
{
public:
    int v;
    int w;
    int i;

    Edge(int _v = 0, int _w = 0, int _i = -1) : v(_v), w(_w), i(_i)
    {
        return;
    }
};

vector<Edge> d;
vector<int> e[N];
map<int, int> f[2], g[2], h[2];
int l[N], r[N], s;
queue<int> q;
bool o[N];

bool LevelDinic(int s, int t)
{
    int i, j;

    memset(l, 0, sizeof(l));
    l[s] = 1;

    for(q.push(s); !q.empty(); q.pop())
    {
        s = q.front();
        for(i = 0; i < (signed)e[s].size(); i ++)
        {
            j = e[s].at(i);
            if(d.at(j).w && !l[d.at(j).v])
            {
                l[d.at(j).v] = l[s] + 1;
                q.push(d.at(j).v);
            }
        }
    }

    return l[t];
}

int BlockDinic(int x, int t, int v)
{
    int i, f;

    if(x == t || !v)
        return v;

    for(f = 0; r[x] < (signed)e[x].size(); r[x] ++)
    {
        i = e[x].at(r[x]);
        if(d.at(i).w && l[d.at(i).v] == l[x] + 1 && (f = BlockDinic(d.at(i).v, t, min(v, d.at(i).w))))
        {
            d.at(i    ).w -= f;
            d.at(i ^ 1).w += f;
            break;
        }
    }

    return f;
}

int Dinic(int s, int t)
{
    int f, o;

    for(o = 0; LevelDinic(s, t); )
    {
        memset(r, 0, sizeof(r));
        while((f = BlockDinic(s, t, INT_MAX)))
            o += f;
    }

    return o;
}

void AddEdge(int u, int v, int w, int i)
{
    // printf("%d->%d : %d\n", u, v, w);
    e[u].push_back(d.size());
    d.push_back(Edge(v, w, i));
    e[v].push_back(d.size());
    d.push_back(Edge(u, 0, -1));

    return;
}

void AddChunk(int u, int v, int l, int r)
{
    // printf("%d->%d : [%d, %d]\n", u, v, l, r);
    if(l > r)
    {
        printf("-1\n");

        exit(0);
    }
    AddEdge(0, v, l, -1);
    AddEdge(u, 1, l, -1);
    AddEdge(u, v, r - l, -1);
    s += l;

    return;
}

int main(void)
{
    int n, m, a, b, x, y, z;
    int i, c;
    map<int, int>::iterator t;

    scanf("%d %d %d %d", &n, &m, &a, &b);
    for(i = 0, c = 4; i < n; i ++)
    {
        scanf("%d %d", &x, &y);
        if(!f[0].count(x))
            f[0][x] = c ++;
        if(!f[1].count(y))
            f[1][y] = c ++;
        // printf("%d->%d\n",f[0][x],f[1][y]);

        g[0][x] ++;
        g[1][y] ++;
        AddEdge(f[0][x], f[1][y], 1, i);
    }

    while(m --)
    {
        scanf("%d %d %d", &z, &x, &y);
        if(!h[-- z].count(x))
            h[z][x] = y;
        h[z][x] = min(h[z][x], y);
    }
    for(t = h[0].begin(); t != h[0].end(); ++ t)
    {
        AddChunk(2, f[0][t -> first], max(0, (int)ceil((double)(g[0][t -> first] - t -> second) / 2)), min(g[0][t -> first], (int)floor((double)(g[0][t -> first] + t -> second) / 2)));
        f[0].erase(t -> first);
    }
    for(t = h[1].begin(); t != h[1].end(); ++ t)
    {
        AddChunk(f[1][t -> first], 3, max(0, (int)ceil((double)(g[1][t -> first] - t -> second) / 2)), min(g[1][t -> first], (int)floor((double)(g[1][t -> first] + t -> second) / 2)));
        f[1].erase(t -> first);
    }
    for(t = f[0].begin(); t != f[0].end(); ++ t)
        AddEdge(2, t -> second, g[0][t -> first], -1);
    for(t = f[1].begin(); t != f[1].end(); ++ t)
        AddEdge(t -> second, 3, g[1][t -> first], -1);
    AddEdge(3, 2, INT_MAX, -1);

    // cout<<s<<endl;
    if(Dinic(0, 1) != s)
        printf("-1\n");
    else
    {
        // e[0].clear();
        // e[1].clear();
        e[2].pop_back();
        e[3].pop_back();
        d.pop_back();
        d.pop_back();
        Dinic(2, 3);

        for(i = s = 0; i < (signed)d.size(); i ++)
            if(d.at(i).i != -1)
            {
                o[d.at(i).i] = !d.at(i).w;
                s += o[d.at(i).i];
            }
        printf("%I64d\n", (long long)min(a, b) * s + (long long)max(a, b) * (n - s));
        for(i = 0; i < n; i ++)
            printf("%c", o[i] ? a <= b ? 'r' : 'b' : a <= b ? 'b' : 'r');
        printf("\n");
    }

    return 0;
}