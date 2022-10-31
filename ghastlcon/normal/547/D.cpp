#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <tuple>
#define N 400020
#define M 200000
using namespace std;

vector<tuple<int, int, int> > d;
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
            if(get<1>(d[k]) && !l[get<0>(d[k])])
            {
                l[get<0>(d[k])] = l[s] + 1;
                q.push(get<0>(d[k]));
            }
        }
    }

    return l[t];
}

int BlockDinic(int x, int t, int v)
{
    int f, k;

    if(x == t || !v)
        return v;

    for(f = 0; r[x] < (signed)e[x].size(); r[x] ++)
    {
        k = e[x][r[x]];
        if(get<1>(d[k]) && l[get<0>(d[k])] == l[x] + 1 && (f = BlockDinic(get<0>(d[k]), t, min(get<1>(d[k]), v))))
        {
            get<1>(d[k    ]) -= f;
            get<1>(d[k ^ 1]) += f;
            break;
        }
    }

    return f;
}

int Dinic(int s, int t)
{
    int o, f;

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
    e[u].push_back(d.size());
    d.push_back(make_tuple(v, w, i));
    e[v].push_back(d.size());
    d.push_back(make_tuple(u, 0, -1));

    return;
}

int AddInterval(int u, int v, int l, int r)
{
    AddEdge(N - 1, v, l, -1);
    AddEdge(u, N - 2, l, -1);
    AddEdge(u, v, r - l, -1);

    return l;
}

int main(void)
{
    int n, x, y;
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d %d", &x, &y);
        AddEdge(x, y + M, 1, i);
    }
    for(i = 1, x = 0; i <= M; i ++)
    {
        if(!e[i].empty())
            x += AddInterval(0, i, e[i].size() / 2, (e[i].size() + 1) / 2);
        if(!e[i + M].empty())
            x += AddInterval(i + M, M + M + 1, e[i + M].size() / 2, (e[i + M].size() + 1) / 2);
    }
    AddEdge(M + M + 1, 0, INT_MAX, -1);

    // printf("summit %d\n", x);
    if(Dinic(N - 1, N - 2) != x)
        throw;
    for(i = 0; i < (signed)d.size(); i ++)
        if(get<2>(d[i]) != -1)
            o[get<2>(d[i])] = get<1>(d[i]) ? 'b' : 'r';
    printf("%s\n", o);

    return 0;
}