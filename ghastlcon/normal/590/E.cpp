#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <bitset>
#include <utility>
#define N 770
#define M 10000020
using namespace std;

namespace ACAM
{
    class Node
    {
    public:
        int s[2];
        int f;
        int g;

        Node(void)
        {
            return;
        }
    };

    Node f[M];
    int c;

    void InsertACAM(string &s, int k)
    {
        int i, p;

        for(i = p = 0; i < (signed)s.size(); i ++)
        {
            if(!f[p].s[s[i] - 97])
                f[p].s[s[i] - 97] = c ++;
            p = f[p].s[s[i] - 97];
        }
        f[p].g = k;

        return;
    }

    void InitACAM(void)
    {
        static int q[M];
        int i, s, t;
        int l, r;

        l = r = 0;
        if(f[0].s[0])
            q[r ++] = f[0].s[0];
        if(f[0].s[1])
            q[r ++] = f[0].s[1];

        for(; l < r; l ++)
        {
            s = q[l];
            for(i = 0; i < 2; i ++)
            {
                t = f[s].s[i];
                if(t)
                {
                    f[t].f = f[f[s].f].s[i];
                    q[r ++] = t;
                }
                else
                    f[s].s[i] = f[f[s].f].s[i];
            }
            if(!f[s].g)
                f[s].g = f[f[s].f].g;
        }

        return;
    }
}

namespace Dinic
{
    vector<pair<int, int> > d;
    vector<int> e[N << 1];
    int l[N << 1], r[N << 1];

    bool LevelDinic(int s, int t)
    {
        static int q[M];
        int i, k;
        int l, r;

        memset(Dinic::l, 0, sizeof(Dinic::l));
        Dinic::l[s] = 1;
        for(q[l = 0] = s, r = 1; l < r; l ++)
        {
            s = q[l];
            for(i = 0; i < (signed)e[s].size(); i ++)
            {
                k = e[s][i];
                if(d[k].second && !Dinic::l[d[k].first])
                {
                    Dinic::l[d[k].first] = Dinic::l[s] + 1;
                    q[r ++] = d[k].first;
                }
            }
        }

        return Dinic::l[t];
    }

    int BlockDinic(int x, int t, int v)
    {
        int k, f;

        if(x == t || !v)
            return v;

        for(f = 0; r[x] < (signed)e[x].size(); r[x] ++)
        {
            k = e[x][r[x]];
            if(d[k].second && l[d[k].first] == l[x] + 1 && (f = BlockDinic(d[k].first, t, min(v, d[k].second))))
            {
                d[k    ].second -= f;
                d[k ^ 1].second += f;
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
        e[u].push_back((int)d.size());
        d.push_back(make_pair(v, w));
        e[v].push_back((int)d.size());
        d.push_back(make_pair(u, 0));

        return;
    }
}

string a[N];
bool e[N][N];

int main(void)
{
    int n;
    int i, j, k, p;

    ios::sync_with_stdio(false);
    cin >> n;
    for(i = ACAM::c = 1; i <= n; i ++)
    {
        cin >> a[i];
        ACAM::InsertACAM(a[i], i);
    }
    ACAM::InitACAM();
    // for(i=0;i<ACAM::c;i++)cout<<ACAM::f[i].f<<' ';cout<<endl;

    for(i = 1; i <= n; i ++)
    {
        for(j = p = 0; j < (signed)a[i].size(); j ++)
        {
            if(ACAM::f[p].g)
                e[i][ACAM::f[p].g] = true;
            p = ACAM::f[p].s[a[i][j] - 97];
        }
        if(ACAM::f[ACAM::f[p].f].g)
            e[i][ACAM::f[ACAM::f[p].f].g] = true;
    }
    for(k = 1; k <= n; k ++)
        for(i = 1; i <= n; i ++)
            for(j = 1; j <= n; j ++)
                e[i][j] |= e[i][k] & e[k][j];

    for(i = 1; i <= n; i ++)
        for(j = 1; j <= n; j ++)
            if(e[i][j])
                Dinic::AddEdge(i, j + n, 1);
    for(i = 1; i <= n; i ++)
    {
        Dinic::AddEdge(n + n + 1, i, 1);
        Dinic::AddEdge(i + n, n + n + 2, 1);
    }
    cout << n - Dinic::Dinic(n + n + 1, n + n + 2) << endl;
    for(i = 1; i <= n; i ++)
        if(Dinic::l[i] && !Dinic::l[i + n])
            cout << i << ' ';
    cout << endl;

    return 0;
}