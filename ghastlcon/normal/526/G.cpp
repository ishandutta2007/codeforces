#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>
#define N 100020
#define M 17
using namespace std;

extern vector<pair<int, int> > e[N];

namespace Diameter
{
    int s[N];

    void DFS(int x, int p)
    {
        int i;

        for(i = 0; i < (signed)e[x].size(); i ++)
            if(e[x][i].first != p)
            {
                s[e[x][i].first] = s[x] + e[x][i].second;
                DFS(e[x][i].first, x);
            }

        return;
    }
    pair<int, int> Diameter(int n)
    {
        int p;

        s[1] = 0;
        DFS(1, 1);
        p = (int)(max_element(s + 1, s + n + 1) - s);
        s[p] = 0;
        DFS(p, p);

        return make_pair(p, (int)(max_element(s + 1, s + n + 1) - s));
    }
}

class Solver
{
private:
    int d[N], v[N], l[N];
    int p[M][N], t[N], h[N];
    vector<int> q, c[N];
    int s[N], g[N];

    void DFSA(int x, int p)
    {
        int i;

        for(i = 1, this -> p[0][x] = p; i < M; i ++)
            this -> p[i][x] = this -> p[i - 1][this -> p[i - 1][x]];

        v[x] = d[x];
        h[x] = -1;
        for(i = 0; i < (signed)e[x].size(); i ++)
            if(e[x][i].first != p)
            {
                d[e[x][i].first] = d[x] + e[x][i].second;
                DFSA(e[x][i].first, x);

                v[x] = max(v[x], v[e[x][i].first]);
                if(h[x] == -1 || v[h[x]] < v[e[x][i].first])
                    h[x] = e[x][i].first;
            }

        return;
    }

    void DFSB(int x, int p, int t)
    {
        int i;

        this -> t[x] = t;
        c[t].push_back(x);
        if(x == t)
            l[x] = v[x] - d[p];
        if(h[x] != -1)
            DFSB(h[x], x, t);

        for(i = 0; i < (signed)e[x].size(); i ++)
            if(e[x][i].first != p && e[x][i].first != h[x])
                DFSB(e[x][i].first, x, e[x][i].first);

        return;
    }

public:
    Solver(void)
    {
        return;
    }

    void InitSolver(int x, int n)
    {
        int i, j;

        DFSA(x, 0);
        DFSB(x, 0, x);
        // printf("center %d: ",x);for(i=1;i<=n;i++)cout<<d[i]<<' ';cout<<endl;
        // for(i=1;i<=n;i++)if(l[i])printf("%d:%d  ",i,l[i]);puts("");
        for(i = 1; i <= n; i ++)
            if(l[i])
                q.push_back(i);
        sort(q.begin(), q.end(), [&](int a, int b) -> bool { return l[a] > l[b]; });
        for(i = 0; i < (signed)q.size(); i ++)
        {
            s[i] = (i ? s[i - 1] : 0) + l[q[i]];
            for(j = 0; j < (signed)c[q[i]].size(); j ++)
                g[c[q[i]][j]] = i;
        }
        g[0] = -1;
        // for(i=1;i<=n;i++)printf("%d ",g[i]);puts("");

        return;
    }

    int Chain(int x, int y, int *d)
    {
        int i, o;

        o = s[y - 1] + v[x];
        for(i = M - 1; i > -1; i --)
            if(g[p[i][x]] >= y)
                x = p[i][x];
        x = p[0][x];

        return o - d[x];
    }

    int Solve(int x, int y)
    {
        y = y * 2 - 1;
        if(!y)
            return 0;

        // printf("sel %d, tot %llu\n", y, q.size());
        if(y >= (signed)q.size())
            return s[(int)q.size() - 1];
        if(g[x] < y)
            return s[y - 1];

        return max(Chain(x, y - 1, d), Chain(x, y, v));
    }
};

vector<pair<int, int> > e[N];
Solver f, g;

int main(void)
{
    int n, q, u, v, w;
    int i, o;

    scanf("%d %d", &n, &q);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d %d", &u, &v, &w);
        e[u].push_back(make_pair(v, w));
        e[v].push_back(make_pair(u, w));
    }

    tie(u, v) = Diameter::Diameter(n);
    f.InitSolver(u, n);
    g.InitSolver(v, n);
    // printf("%d-%d\n", u, v);

    for(o = 0; q --; )
    {
        scanf("%d %d", &i, &w);
        i = (i + o - 1) % n + 1;
        w = (w + o - 1) % n + 1;
        // printf("solve %d-%d\n", i, w);
        printf("%d\n", o = max(f.Solve(i, w), g.Solve(i, w)));
    }

    return 0;
}