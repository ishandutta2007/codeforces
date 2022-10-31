#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define N 200020
#define M 18
using namespace std;

extern int d[N], l[N];
extern int GetLCA(int, int);

namespace Virtual
{
    class State
    {
    private:
        int Round(void)
        {
            return !d ? -1 : (d - 1) / l;
        }

    public:
        int d;
        int c;
        int l;
        int i;

        State(void)
        {
            return;
        }

        State(int _d, int _c, int _l, int _i) : d(_d), c(_c), l(_l), i(_i)
        {
            return;
        }

        bool operator<(State that)
        {
            return this -> Round() != that.Round() ? this -> Round() < that.Round() : this -> c < that.c;
        }

        bool operator>(State that) const
        {
            return that < *this;
        }
    };

    int n, m;
    int a[N], s[N], b[N];
    vector<int> v;
    vector<pair<int, int> > e[N];
    priority_queue<State, vector<State>, greater<State> > q;
    int o[N];

    bool Compare(int a, int b)
    {
        return l[a] < l[b];
    }

    void Solve(void)
    {
        int i, t;
        State w;

        for(i = 0; i < n; i ++)
            v.push_back(a[i]);
        for(i = 0; i < m; i ++)
            v.push_back(b[i]);
        sort(v.begin(), v.end(), Compare);
        for(i = 1; i < n + m; i ++)
            v.push_back(GetLCA(v[i], v[i - 1]));
        sort(v.begin(), v.end(), Compare);
        v.erase(unique(v.begin(), v.end()), v.end());
        for(i = 0; i < (signed)v.size(); i ++)
        {
            o[v[i]] = -1;
            if(i)
            {
                t = GetLCA(v[i], v[i - 1]);
                e[t].push_back(make_pair(v[i], d[v[i]] - d[t]));
                e[v[i]].push_back(make_pair(t, d[v[i]] - d[t]));
                // printf("%d -> %d : %d\n", t + 1, v[i] + 1, d[v[i]] - d[t]);
            }
        }

        for(i = 0; i < n; i ++)
            q.push(State(0, i, s[i], a[i]));
        for(; !q.empty(); q.pop())
        {
            w = q.top();
            if(o[w.i] == -1)
            {
                o[w.i] = w.c;
                for(i = 0; i < (signed)e[w.i].size(); i ++)
                    if(o[e[w.i][i].first] == -1)
                        q.push(State(w.d + e[w.i][i].second, w.c, w.l, e[w.i][i].first));
            }
        }
        for(i = 0; i < m; i ++)
            printf("%d ", o[b[i]] + 1);
        printf("\n");

        for(i = 0; i < (signed)v.size(); i ++)
            e[v[i]].clear();
        v.clear();

        return;
    }
}

vector<int> e[N];
int f[M][N], d[N], l[N];

void DFS(int x, int p)
{
    static int k;
    int i;

    l[x] = k ++;
    for(i = 1, f[0][x] = p; i < M; i ++)
        f[i][x] = f[i - 1][f[i - 1][x]];
    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x][i] != p)
        {
            d[e[x][i]] = d[x] + 1;
            DFS(e[x][i], x);
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

int main(void)
{
    int n, q, u, v;
    int i;

    scanf("%d", &n);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[-- u].push_back(-- v);
        e[   v].push_back(   u);
    }
    DFS(0, 0);

    scanf("%d", &q);
    while(q --)
    {
        scanf("%d %d", &Virtual::n, &Virtual::m);
        for(i = 0; i < Virtual::n; i ++)
        {
            scanf("%d %d", &Virtual::a[i], &Virtual::s[i]);
            Virtual::a[i] --;
        }
        for(i = 0; i < Virtual::m; i ++)
        {
            scanf("%d", &Virtual::b[i]);
            Virtual::b[i] --;
        }
        Virtual::Solve();
    }

    return 0;
}