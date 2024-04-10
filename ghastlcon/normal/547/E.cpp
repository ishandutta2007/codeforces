#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#define N 500020
#define S 26
using namespace std;

namespace ACAM
{
    class Node
    {
    public:
        int s[S];
        int f;

        Node(void) : f(0)
        {
            return;
        }
    };

    Node f[N];
    int p[N], c;
    queue<int> q;

    inline int ID(char c)
    {
        return c - 97;
    }

    void InsertACAM(int x, string &a)
    {
        int i;

        for(i = p[x] = 0; i < (signed)a.size(); i ++)
        {
            if(!f[p[x]].s[ID(a[i])])
                f[p[x]].s[ID(a[i])] = c ++;
            p[x] = f[p[x]].s[ID(a[i])];
            // printf("string %d, walk to %d\n", x, p[x]);
        }

        return;
    }

    void InitACAM(void)
    {
        int i, s;

        for(i = 0; i < S; i ++)
            if(f[0].s[i])
                q.push(f[0].s[i]);

        // for(i=0;i<c;i++)
        // {
        //     // printf("at %d:\n",i);
        //     for(int j=0;j<S;j++)cout<<f[i].s[j]<<" ";
        //     puts("");
        // }

        for(; !q.empty(); q.pop())
        {
            s = q.front();
            // cout<<s<<endl;
            for(i = 0; i < S; i ++)
                if(f[s].s[i])
                {
                    f[f[s].s[i]].f = f[s].f;
                    while(f[f[s].s[i]].f && !f[f[f[s].s[i]].f].s[i])
                        f[f[s].s[i]].f = f[f[f[s].s[i]].f].f;
                    f[f[s].s[i]].f = f[f[f[s].s[i]].f].s[i];
                    // printf("%d->%d\n",s,f[s].s[i]);
                    q.push(f[s].s[i]);
                }
                else
                    f[s].s[i] = f[f[s].f].s[i];
        }

        // for(i=0;i<c;i++)cout<<f[i].f<<' ';cout<<endl;

        return;
    }
}

namespace DFS
{
    vector<int> e[N];
    int f[N], l[N], r[N];

    inline int Lowbit(int x)
    {
        return x & -x;
    }

    void AddFenwick(int p, int v)
    {
        for(; p <= ACAM::c; p += Lowbit(p))
            f[p] += v;

        return;
    }

    int SumFenwick(int p)
    {
        int o;

        for(o = 0; p; p -= Lowbit(p))
            o += f[p];

        return o;
    }

    void DFS(int x)
    {
        static int k;
        int i;

        l[x] = ++ k;
        for(i = 0; i < (signed)e[x].size(); i ++)
            DFS(e[x].at(i));
        r[x] = k;

        return;
    }
}

class Data
{
public:
    int p;
    int f;
    int i;

    Data(int _p = 0, int _f = 0, int _i = 0) : p(_p), f(_f), i(_i)
    {
        return;
    }
};

string a[N];
vector<Data> f[N];
int o[N];

int main(void)
{
    int n, q, l, r, p;
    int i, j;

    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(i = ACAM::c = 1; i <= n; i ++)
    {
        cin >> a[i];
        ACAM::InsertACAM(i, a[i]);
    }
    ACAM::InitACAM();

    for(i = 1; i < ACAM::c; i ++)
        DFS::e[ACAM::f[i].f].push_back(i);
    DFS::DFS(0);

    for(i = 1; i <= q; i ++)
    {
        cin >> l >> r >> p;
        f[l - 1].push_back(Data(p, -1, i));
        f[r].push_back(Data(p, 1, i));
    }
    for(i = 1; i <= n; i ++)
    {
        for(j = p = 0; j < (signed)a[i].size(); j ++)
        {
            p = ACAM::f[p].s[ACAM::ID(a[i][j])];
            DFS::AddFenwick(DFS::l[p], 1);
        }
        for(j = 0; j < (signed)f[i].size(); j ++)
            o[f[i].at(j).i] += f[i].at(j).f * (DFS::SumFenwick(DFS::r[ACAM::p[f[i].at(j).p]]) - DFS::SumFenwick(DFS::l[ACAM::p[f[i].at(j).p]] - 1));
    }

    for(i = 1; i <= q; i ++)
        printf("%d\n", o[i]);

    return 0;
}