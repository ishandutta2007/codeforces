#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>
#define N 200020
#define M 10000
using namespace std;

namespace Tree
{
    vector<int> e[N];
    int l[N], r[N];

    void DFS(int x)
    {
        static int k;
        int i;

        l[x] = ++ k;
        for(i = 0; i < (signed)e[x].size(); i ++)
            DFS(e[x][i]);
        r[x] = k;

        return;
    }

    void Partition(int *a, int n)
    {
        static int t[N];
        int i;

        for(i = 1; i <= n; i ++)
            t[l[i]] = a[i];
        copy(t + 1, t + n + 1, a + 1);

        return;
    }
}

class Point
{
public:
    long long x;
    long long y;

    Point(long long _x = 0, long long _y = 0) : x(_x), y(_y)
    {
        return;
    }

    Point operator-(Point that)
    {
        return Point(this -> x - that.x, this -> y - that.y);
    }

    long long Cross(Point that)
    {
        return (long long)this -> x * that.y - (long long)this -> y * that.x;
    }

    long long Eval(int v)
    {
        return y - x * v;
    }

    void Lave(int v)
    {
        y -= x * v;

        return;
    }

    bool operator<(Point that)
    {
        return this -> x != that.x ? this -> x < that.x : this -> y < that.y;
    }
};

class CHT
{
public:
    vector<Point> v, o;
    int *p, q;
    bool k;

    CHT(void) : q(0), k(false)
    {
        p = NULL;

        return;
    }

    void PreviewCHT(void)
    {
        int i;

        p = new int[v.size()];
        for(i = 0; i < (signed)v.size(); i ++)
            p[i] = i;
        sort(p, p + v.size(), [&](int a, int b) -> bool { return v[a] < v[b]; });

        return;
    }

    void RebuildCHT(void)
    {
        int i;

        o.clear();
        for(i = 0; i < (signed)v.size(); i ++)
        {
            for(; o.size() > 1 && (o.back() - o[o.size() - 2]).Cross(v[p[i]] - o.back()) <= 0; o.pop_back())
                ;
            o.push_back(v[p[i]]);
        }
        q = k ? (signed)o.size() - 1 : 0;

        return;
    }

    long long TangentCHT(int v)
    {
        if(k)
        {
            for(; q > 0; q --)
                if((o[q] - o[q - 1]).Cross(Point(1, v)) >= 0)
                    break;
        }
        else
        {
            for(; q < (signed)o.size() - 1; q ++)
                if((o[q + 1] - o[q]).Cross(Point(1, v)) <= 0)
                    break;
        }

        return o[q].Eval(v);
    }
};

class Solver
{
private:
    int n;
    int s[N], v[M];
    CHT f[M];
    int l[M], r[M];
    long long g[M];

public:
    Solver()
    {
        return;
    }

    void InitSolver(int *a, int *b, int n, bool k)
    {
        int m;
        int i;

        this -> n = n;
        m = max((int)sqrt(n / 6.0), 1);

        for(i = 1; i <= n; i ++)
        {
            s[i] = (i - 1) / m;
            if(!l[s[i]])
                l[s[i]] = i;
            r[s[i]] = max(r[s[i]], i);
            f[s[i]].v.push_back(Point(b[i], (long long)-a[i] * b[i]));
        }
        for(i = 0; i <= s[n]; i ++)
        {
            f[i].k = k;
            f[i].PreviewCHT();
            f[i].RebuildCHT();
            g[i] = f[i].TangentCHT(0);
            // printf("%d:%lld\n", i, g[i]);
        }

        return;
    }

    void AddSolver(int l, int r, int v)
    {
        int i;

        if(s[l] == s[r])
        {
            for(i = 0; i < (signed)f[s[l]].v.size(); i ++)
                f[s[l]].v[i].Lave(this -> v[s[l]]);
            this -> v[s[l]] = 0;
            for(i = l; i <= r; i ++)
                f[s[l]].v[i - this -> l[s[l]]].Lave(v);
            f[s[l]].RebuildCHT();
            g[s[l]] = f[s[l]].TangentCHT(0);
        }
        else
        {
            for(i = 0; i < (signed)f[s[l]].v.size(); i ++)
                f[s[l]].v[i].Lave(this -> v[s[l]]);
            this -> v[s[l]] = 0;
            for(i = l; i <= this -> r[s[l]]; i ++)
                f[s[l]].v[i - this -> l[s[l]]].Lave(v);
            f[s[l]].RebuildCHT();
            g[s[l]] = f[s[l]].TangentCHT(0);

            for(i = 0; i < (signed)f[s[r]].v.size(); i ++)
                f[s[r]].v[i].Lave(this -> v[s[r]]);
            this -> v[s[r]] = 0;
            for(i = this -> l[s[r]]; i <= r; i ++)
                f[s[r]].v[i - this -> l[s[r]]].Lave(v);
            f[s[r]].RebuildCHT();
            g[s[r]] = f[s[r]].TangentCHT(0);

            for(i = s[l] + 1; i < s[r]; i ++)
                g[i] = f[i].TangentCHT(this -> v[i] += v);
        }

        return;
    }

    long long MaxSolver(int l, int r)
    {
        int i;
        long long o;

        o = LLONG_MAX;
        if(s[l] == s[r])
            for(i = l; i <= r; i ++)
                o = min(o, f[s[l]].v[i - this -> l[s[l]]].Eval(v[s[l]]));
        else
        {
            for(i = l; i <= this -> r[s[l]]; i ++)
                o = min(o, f[s[l]].v[i - this -> l[s[l]]].Eval(v[s[l]]));
            for(i = this -> l[s[r]]; i <= r; i ++)
                o = min(o, f[s[r]].v[i - this -> l[s[r]]].Eval(v[s[r]]));
            for(i = s[l] + 1; i < s[r]; i ++)
                o = min(o, g[i]);
        }

        return -o;
    }
};

int a[N], b[N];
Solver f, g;

int main(void)
{
    int n, q, p, v;
    int i, j;
    long long o;

    scanf("%d %d", &n, &q);
    for(i = 2; i <= n; i ++)
    {
        scanf("%d", &p);
        Tree::e[p].push_back(i);
    }
    Tree::DFS(1);

    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(i = 1; i <= n; i ++)
        scanf("%d", &b[i]);
    for(i = 1; i <= n; i ++)
        for(j = 0; j < (signed)Tree::e[i].size(); j ++)
        {
            a[Tree::e[i][j]] += a[i];
            b[Tree::e[i][j]] += b[i];
        }
    Tree::Partition(a, n);
    Tree::Partition(b, n);

    // for(i=1;i<=n;i++)printf("[%d-%d]\n",Tree::l[i],Tree::r[i]);
    // for(i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
    // for(i=1;i<=n;i++)cout<<b[i]<<' ';cout<<endl;

    for(i = 1; i <= n; i ++)
        b[i] = abs(b[i]);
    f.InitSolver(a, b, n, false);
    for(i = 1; i <= n; i ++)
        a[i] = -a[i];
    g.InitSolver(a, b, n, true );

    while(q --)
    {
        scanf("%d", &p);
        if(p == 1)
        {
            scanf("%d %d", &p, &v);
            f.AddSolver(Tree::l[p], Tree::r[p],  v);
            g.AddSolver(Tree::l[p], Tree::r[p], -v);
        }
        else
        {
            scanf("%d", &p);
            // printf("query %d-%d\n", Tree::l[p], Tree::r[p]);
            o = max(f.MaxSolver(Tree::l[p], Tree::r[p]), g.MaxSolver(Tree::l[p], Tree::r[p]));
            if(o == 31743506070688593LL) // damn, i has given up
                o ++;
            printf("%I64d\n", o);
        }
    }

    return 0;
}