#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <tuple>
#define N 100020
#define M 320
#define S 26
using namespace std;

class Node
{
public:
    int s[S];
    int f;

    Node(void)
    {
        return;
    }
};

string a[N];
vector<int> p[N], e[N];
vector<long long> s[N];
vector<tuple<int, int, int> > b[N];
Node f[N];
int l[N], r[N];
int g[N], c;
long long o[N];

inline int Lowbit(int x)
{
    return x & -x;
}

void AddFenwick(int p, int v)
{
    for(; p <= c; p += Lowbit(p))
        g[p] += v;

    return;
}

int SumFenwick(int p)
{
    int o;

    for(o = 0; p; p -= Lowbit(p))
        o += g[p];

    return o;
}

void InsertACAM(string &x, vector<int> &k)
{
    int i, p;

    for(i = p = 0; i < (signed)x.size(); i ++)
    {
        if(!f[p].s[x[i] - 97])
            f[p].s[x[i] - 97] = c ++;
        k[i] = p = f[p].s[x[i] - 97];
    }

    return;
}

void InitACAM(void)
{
    static int q[N];
    int i, s, t, l, r;

    l = r = 0;
    for(i = 0; i < S; i ++)
        if(f[0].s[i])
            q[r ++] = f[0].s[i];

    for(; l < r; l ++)
    {
        s = q[l];
        for(i = 0; i < S; i ++)
            if(f[s].s[i])
            {
                t = f[s].s[i];
                for(f[t].f = f[s].f; f[t].f && !f[f[t].f].s[i]; f[t].f = f[f[t].f].f)
                    ;
                f[t].f = f[f[t].f].s[i];
                q[r ++] = t;
            }
            else
                f[s].s[i] = f[f[s].f].s[i];
    }

    return;
}

void DFSACAM(int x)
{
    static int k;
    int i;

    l[x] = ++ k;
    for(i = 0; i < (signed)e[x].size(); i ++)
        DFSACAM(e[x][i]);
    r[x] = k;

    return;
}

int main(void)
{
    int n, q, x, y, k;
    int i, j;

    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(i = c = 1; i <= n; i ++)
    {
        cin >> a[i];
        p[i].resize(a[i].size());
        InsertACAM(a[i], p[i]);
    }

    InitACAM();
    for(i = 1; i < c; i ++)
        e[f[i].f].push_back(i);
    DFSACAM(0);
    for(i = 1; i <= n; i ++)
        if(a[i].size() >= M)
        {
            s[i].resize(n + 1);
            for(j = 0; j < (signed)a[i].size(); j ++)
                AddFenwick(l[p[i][j]], 1);
            for(j = 1; j <= n; j ++)
                s[i][j] = s[i][j - 1] + (SumFenwick(r[p[j].back()]) - SumFenwick(l[p[j].back()] - 1));
            for(j = 0; j < (signed)a[i].size(); j ++)
                AddFenwick(l[p[i][j]], -1);
        }

    for(i = 1; i <= q; i ++)
    {
        cin >> x >> y >> k;
        if(a[k].size() >= M)
            o[i] = s[k][y] - s[k][x - 1];
        else
        {
            b[x - 1].push_back(make_tuple(k, i, -1));
            b[y].push_back(make_tuple(k, i, 1));
        }
    }
    for(i = 1; i <= n; i ++)
    {
        AddFenwick(l[p[i].back()], 1);
        AddFenwick(r[p[i].back()] + 1, -1);
        for(j = 0; j < (signed)b[i].size(); j ++)
            for(k = 0; k < (signed)a[get<0>(b[i][j])].size(); k ++)
                o[get<1>(b[i][j])] += get<2>(b[i][j]) * SumFenwick(l[p[get<0>(b[i][j])][k]]);
    }
    for(i = 1; i <= q; i ++)
        cout << o[i] << endl;

    return 0;
}