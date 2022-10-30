#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <set>
#include <utility>
#include <tuple>
#include <functional>
#define N 200020
#define M 19
using namespace std;

class Fenwick
{
private:
    int f[N];

    inline int Lowbit(int x)
    {
        return x & -x;
    }

public:
    Fenwick(void)
    {
        return;
    }

    void ClearFenwick(void)
    {
        fill(f, f + N, INT_MIN);

        return;
    }

    void SetFenwick(int p, int v, int n)
    {
        for(; p <= n; p += Lowbit(p))
            f[p] = max(f[p], v);

        return;
    }

    int MaxFenwick(int p)
    {
        int o;

        for(o = INT_MIN; p; p -= Lowbit(p))
            o = max(o, f[p]);

        return o;
    }
};

class SolverA
{
private:
    pair<int, int> b[N];
    int q[M][N];

public:
    SolverA(void)
    {
        return;
    }

    void InitSolver(int *a, int n)
    {
        static Fenwick f;
        static int l[N], r[N];
        int i, j, p;
        vector<int> v;

        for(i = 1; i <= n; i ++)
            v.push_back(a[i]);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        f.ClearFenwick();
        for(i = 1; i <= n; i ++)
        {
            p = (int)(lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1);
            // printf("%d%c",p," \n"[i==n]);
            l[i] = f.MaxFenwick(p - 1);
            f.SetFenwick(p, i, (int)v.size());
        }
        f.ClearFenwick();
        for(i = n; i >= 1; i --)
        {
            p = (int)(lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1);
            r[i] = f.MaxFenwick(p - 1);
            f.SetFenwick(p, -i, (int)v.size());
        }

        for(i = 1; i <= n; i ++)
        {
            q[0][i] = i;
            b[i] = make_pair(INT_MAX, INT_MAX);
        }
        for(i = 1; i <= n; i ++)
            if(l[i] != INT_MIN && r[i] != INT_MIN)
                b[l[i]] = min(b[l[i]], make_pair(-r[i], i));
        for(i = 1; i < M; i ++)
            for(j = 1; j + (1 << i) - 1 <= n; j ++)
                q[i][j] = b[q[i - 1][j]] < b[q[i - 1][j + (1 << (i - 1))]] ? q[i - 1][j] : q[i - 1][j + (1 << (i - 1))];

        return;
    }

    bool QuerySolver(int l, int r)
    {
        int t, o;

        t = 31 - __builtin_clz(r - l + 1);
        o = b[q[t][l]] < b[q[t][r - (1 << t) + 1]] ? q[t][l] : q[t][r - (1 << t) + 1];
        if(b[o].first <= r)
        {
            printf("3\n%d %d %d\n", o, b[o].second, b[o].first);

            return true;
        }

        return false;
    }
};

class SolverB
{
private:
    tuple<int, int, int> b[N];
    int q[M][N], c[N];

public:
    SolverB(void)
    {
        return;
    }

    void InitSolver(int *a, int n)
    {
        int i, j, x, y;
        vector<int> l[2], r[2];
        set<int> f;
        set<int>::iterator t;

        for(i = 1; i <= n; i ++)
        {
            q[0][i] = i;
            b[i] = make_tuple(INT_MAX, INT_MAX, INT_MAX);
        }
        for(i = 1; i <= n; i ++)
        {
            for(; !l[0].empty() && l[0].back() < a[i]; l[0].pop_back(), l[1].pop_back())
                if(c[l[1].back()] ++)
                    f.insert(l[1].back());
            for(; !r[0].empty() && r[0].back() > a[i]; r[0].pop_back(), r[1].pop_back())
                if(c[r[1].back()] ++)
                    f.insert(r[1].back());

            x = (int)(lower_bound(l[0].begin(), l[0].end(), a[i], greater<int>()) - l[0].begin()) - 1;
            y = (int)(lower_bound(r[0].begin(), r[0].end(), a[i]                ) - r[0].begin()) - 1;
            // printf("%d : %d(%d), %d(%d)\n", i, x, l.size(), y, r.size());
            // for(pair<int, int>v:l)printf("[%d,%d] ",v.first,v.second);puts("");
            // for(pair<int, int>v:r)printf("[%d,%d] ",v.first,v.second);puts("");
            if(x >= 0 && y >= 0)
            {
                x = l[1][x];
                y = r[1][y];
                t = f.lower_bound(min(x, y));
                if(t != f.begin())
                {
                    -- t;
                    // printf("CHECKC %d\n", *t);
                    x = *lower_bound(l[1].begin(), l[1].end(), *t);
                    y = *lower_bound(r[1].begin(), r[1].end(), *t);
                    b[*t] = min(b[*t], make_tuple(i, min(x, y), max(x, y)));
                }
            }
            l[0].push_back(a[i]);
            r[0].push_back(a[i]);
            l[1].push_back(  i );
            r[1].push_back(  i );
        }
        for(i = 1; i < M; i ++)
            for(j = 1; j + (1 << i) - 1 <= n; j ++)
                q[i][j] = b[q[i - 1][j]] < b[q[i - 1][j + (1 << (i - 1))]] ? q[i - 1][j] : q[i - 1][j + (1 << (i - 1))];

        return;
    }

    bool QuerySolver(int l, int r)
    {
        int t, o;

        t = 31 - __builtin_clz(r - l + 1);
        o = b[q[t][l]] < b[q[t][r - (1 << t) + 1]] ? q[t][l] : q[t][r - (1 << t) + 1];
        if(get<0>(b[o]) <= r)
        {
            printf("4\n%d %d %d %d\n", o, get<1>(b[o]), get<2>(b[o]), get<0>(b[o]));

            return true;
        }

        return false;
    }
};

int a[N];
SolverA f[2];
SolverB g;

int main(void)
{
    int n, q, l, r;
    int i;

    scanf("%d %d", &n, &q);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    f[0].InitSolver(a, n);
    g.InitSolver(a, n);
    for(i = 1; i <= n; i ++)
        a[i] = INT_MAX - a[i];
    f[1].InitSolver(a, n);

    while(q --)
    {
        scanf("%d %d", &l, &r);
        if(!(g.QuerySolver(l, r) || f[0].QuerySolver(l, r) || f[1].QuerySolver(l, r)))
            printf("0\n");
    }

    return 0;
}