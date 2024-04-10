#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define N 200020
#define M 18
using namespace std;

extern vector<pair<int, int> > e[N];

namespace Dijkstra
{
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
    vector<int> k[2][N];
    long long d[N];

    void Dijkstra(int s)
    {
        int i;
        pair<long long, int> t;

        for(i = 0; i < N; i ++)
            d[i] = LLONG_MAX >> 2;
        d[s] = 0;

        for(q.push(make_pair(0, s)); !q.empty(); q.pop())
        {
            t = q.top();
            if(t.first != d[t.second])
                continue;

            for(i = 0; i < (signed)e[t.second].size(); i ++)
                if(d[e[t.second].at(i).first] > t.first + e[t.second].at(i).second)
                {
                    d[e[t.second].at(i).first] = t.first + e[t.second].at(i).second;
                    k[1][e[t.second].at(i).first].clear();
                    k[1][e[t.second].at(i).first].push_back(t.second);
                    q.push(make_pair(d[e[t.second].at(i).first], e[t.second].at(i).first));
                }
                else if(d[e[t.second].at(i).first] == t.first + e[t.second].at(i).second)
                    k[1][e[t.second].at(i).first].push_back(t.second);
        }

        return;
    }
}

namespace DAG
{
    int f[M][N], d[N], s[N];
    bool u[N];
    vector<int> e[N], v;

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

    void DFS(int x)
    {
        int i;

        if(u[x])
            return;
        u[x] = true;

        for(i = 0; i < (signed)Dijkstra::k[0][x].size(); i ++)
            DFS(Dijkstra::k[0][x].at(i));
        v.push_back(x);

        return;
    }

    void Tree(int x)
    {
        int i;

        for(i = 0, s[x] = 1; i < (signed)e[x].size(); i ++)
        {
            Tree(e[x].at(i));
            s[x] += s[e[x].at(i)];
        }

        return;
    }

    int Solve(int s)
    {
        int i, j, x, k;

        DFS(s);
        for(i = (signed)v.size() - 1; i > -1; i --)
        {
            x = v.at(i);
            if(x == s)
                for(j = 0; j < M; j ++)
                    f[j][x] = x;
            else
            {
                k = Dijkstra::k[1][x].front();
                for(j = 1; j < (signed)Dijkstra::k[1][x].size(); j ++)
                    k = GetLCA(k, Dijkstra::k[1][x].at(j));
                e[k].push_back(x);
                d[x] = d[k] + 1;

                // printf("vertex %d, father %d\n", x + 1, k + 1);

                for(j = 1, f[0][x] = k; j < M; j ++)
                    f[j][x] = f[j - 1][f[j - 1][x]];
            }
        }

        Tree(s);
        for(i = (signed)v.size() - 2, k = 0; i > -1; i --)
            k = max(k, DAG::s[v.at(i)]);

        return k;
    }
}

vector<pair<int, int> > e[N];

int main(void)
{
    int n, m, s, u, v, w;
    int i, j;

    scanf("%d %d %d", &n, &m, &s);
    while(m --)
    {
        scanf("%d %d %d", &u, &v, &w);
        e[-- u].push_back(make_pair(-- v, w));
        e[   v].push_back(make_pair(   u, w));
    }
    Dijkstra::Dijkstra(-- s);

    for(i = 0; i < n; i ++)
        for(j = 0; j < (signed)Dijkstra::k[1][i].size(); j ++)
        {
            // printf("%d->%d\n",Dijkstra::k[1][i][j]+1,i+1);
            Dijkstra::k[0][Dijkstra::k[1][i].at(j)].push_back(i);
        }
    printf("%d\n", DAG::Solve(s));

    return 0;
}