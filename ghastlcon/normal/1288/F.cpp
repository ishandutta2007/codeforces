#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <utility>
#include <tr1/tuple>
#define N 500
#define Q 511
using namespace std;

vector<tr1::tuple<int, int, int> > d;
vector<int> e[N];
int v[N], p[N], q[Q + 2], s[N];
bool u[N];
int h[N];
pair<int, int> o;

int AugmentKarp(int s, int t)
{
    int x, o;

    for(x = t, o = INT_MAX; x != s; x = tr1::get<0>(d[p[x] ^ 1]))
        o = min(o, tr1::get<1>(d[p[x]]));
    for(x = t; x != s; x = tr1::get<0>(d[p[x] ^ 1]))
    {
        tr1::get<1>(d[p[x]    ]) -= o;
        tr1::get<1>(d[p[x] ^ 1]) += o;
    }

    return o;
}

bool AdvanceKarp(int s, int t)
{
    int l, r;
    int i, k;

    for(i = 0; i < N; i ++)
        v[i] = INT_MAX >> 2;
    v[s] = l = r = 0;
    u[s] = true;

    for(q[r ++] = s; l < r; l ++)
    {
        s = q[l & Q];
        for(i = 0; i < (signed)e[s].size(); i ++)
        {
            k = e[s][i];
            if(v[s] + tr1::get<2>(d[k]) < v[tr1::get<0>(d[k])] && tr1::get<1>(d[k]))
            {
                v[tr1::get<0>(d[k])] = v[s] + tr1::get<2>(d[k]);
                p[tr1::get<0>(d[k])] = k;
                if(!u[tr1::get<0>(d[k])])
                {
                    q[(r ++) & Q] = tr1::get<0>(d[k]);
                    u[tr1::get<0>(d[k])] = false;
                }
            }
        }
        u[s] = false;
    }

    return v[t] != INT_MAX >> 2;
}

pair<int, int> Karp(int s, int t)
{
    pair<int, int> o;
    int v;

    for(; AdvanceKarp(s, t); o = make_pair(o.first + v, o.second + v * ::v[t]))
        v = AugmentKarp(s, t);

    return o;
}

void AddEdge(int u, int v, int l, int r, int c)
{
    e[u].push_back(d.size());
    d.push_back(tr1::make_tuple(v, r - l,  c));
    e[v].push_back(d.size());
    d.push_back(tr1::make_tuple(u, 0    , -c));

    o.first  += l    ;
    o.second += l * c;
    s[u] -= l;
    s[v] += l;

    return;
}

int main(void)
{
    int n[2], m, r, b, u, v;
    int i, c;
    pair<int, int> t;

    cin >> n[0] >> n[1] >> m >> r >> b;
    for(i = 1; i <= n[0]; i ++)
    {
        while((c = getchar()) != 'R' && c != 'B' && c != 'U')
            ;
        if(c == 'R')
            AddEdge(0, i, 1, INT_MAX, 0);
        else if(c == 'B')
            AddEdge(i, n[0] + n[1] + 1, 1, INT_MAX, 0);
        else
        {
            AddEdge(0, i, 0, INT_MAX, 0);
            AddEdge(i, n[0] + n[1] + 1, 0, INT_MAX, 0);
        }
    }
    for(i = n[0] + 1; i <= n[0] + n[1]; i ++)
    {
        while((c = getchar()) != 'R' && c != 'B' && c != 'U')
            ;
        if(c == 'B')
            AddEdge(0, i, 1, INT_MAX, 0);
        else if(c == 'R')
            AddEdge(i, n[0] + n[1] + 1, 1, INT_MAX, 0);
        else
        {
            AddEdge(0, i, 0, INT_MAX, 0);
            AddEdge(i, n[0] + n[1] + 1, 0, INT_MAX, 0);
        }
    }
    AddEdge(n[0] + n[1] + 1, 0, 0, INT_MAX, 0);
    for(i = 1; i <= m; i ++)
    {
        cin >> u >> v;
        AddEdge(u, v + n[0], 0, 1, r);
        AddEdge(v + n[0], u, 0, 1, b);
        h[i] = d.size() - 1;
    }

    for(i = v = 0; i <= n[0] + n[1] + 1; i ++)
        if(s[i] > 0)
        {
            v += s[i];
            // printf("vertex %d : %d\n", i, s[i]);
            AddEdge(n[0] + n[1] + 2, i, 0,  s[i], 0);
        }
        else if(s[i] < 0)
        {
            // printf("vertex %d : %d\n", i, s[i]);
            AddEdge(i, n[0] + n[1] + 3, 0, -s[i], 0);
        }
    t = Karp(n[0] + n[1] + 2, n[0] + n[1] + 3);
    // cout<<t.first<<' '<<t.second<<' '<<v<<endl;
    if(t.first != v)
        cout << -1 << endl;
    else
    {
        cout << t.second + o.second << endl;
        for(i = 1; i <= m; i ++)
            if(tr1::get<1>(d[h[i]]))
                cout << 'B';
            else if(tr1::get<1>(d[h[i] - 2]))
                cout << 'R';
            else
                cout << 'U';
        cout << endl;
    }

    return 0;
}