#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#define N 2000020
using namespace std;

class Edge
{
public:
    int v;
    int w;

    Edge(int _v = 0, int _w = 0) : v(_v), w(_w)
    {
        return;
    }
};

char a[N];
int n, m;
vector<Edge> d;
vector<int> e[N];
int l[N], r[N];
queue<int> q;

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

void AddEdge(int u, int v, int w)
{
    e[u].push_back(d.size());
    d.push_back(Edge(v, w));
    e[v].push_back(d.size());
    d.push_back(Edge(u, 0));

    return;
}

inline int Convert(int x, int y, bool k)
{
    return (x * m + y) * 2 + k;
}

int main(void)
{
    int i, j;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
    {
        scanf("%s", a);
        for(j = 0; j < m; j ++)
        {
            if((i == 0 && j == 0) || (i == n - 1 && j == m - 1))
                AddEdge(Convert(i, j, false), Convert(i, j, true), INT_MAX);
            else if(a[j] == '.')
                AddEdge(Convert(i, j, false), Convert(i, j, true), 1);

            if(i + 1 < n)
                AddEdge(Convert(i, j, true), Convert(i + 1, j, false), INT_MAX);
            if(j + 1 < m)
                AddEdge(Convert(i, j, true), Convert(i, j + 1, false), INT_MAX);
        }
    }
    printf("%d\n", Dinic(0, n * m * 2 - 1));

    return 0;
}