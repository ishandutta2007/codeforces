#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 400020
using namespace std;

int n;
vector<int> e[N];
vector<vector<int> > b;
vector<pair<int, int> > d[N];
bool u[N], w[N];
int v[N];

void Tarjan(int x)
{
    static int d[N], l[N];
    static int k;
    static vector<int> t;
    int i, v, w;

    if(d[x])
        return;

    d[x] = l[x] = ++ k;
    t.push_back(x);
    for(i = 0; i < (signed)e[x].size(); i ++)
        if(!d[v = e[x][i]])
        {
            Tarjan(v);
            l[x] = min(l[x], l[v]);
            if(l[v] == d[x])
            {
                b.push_back(vector<int>());
                do
                {
                    w = t.back();
                    ::v[w] = b.size() + n;
                    b.back().push_back(w);
                    t.pop_back();
                }
                while(w != v);
                ::v[b.size() + n] = x;
                b.back().push_back(x);
            }
        }
        else
            l[x] = min(l[x], d[v]);

    return;
}

bool DFS(int x, int p, vector<int> &g)
{
    int i;

    if(p && w[x])
    {
        g.push_back(x);

        return true;
    }
    if(u[x])
        return false;
    u[x] = true;

    g.push_back(x);
    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x][i] != p && DFS(e[x][i], x, g))
            return true;
    g.pop_back();

    return false;
}

bool Solve(vector<int> &s, int k)
{
    int i, x;
    vector<int> f, g, h;

    if(s.size() >= d[k].size())
        return false;
    for(i = 0; i < (signed)d[k].size(); i ++)
    {
        // printf("%d-%d\n", d[k][i].first, d[k][i].second);
        // if(find(s.begin(), s.end(), d[k][i].first) == s.end())
        //     puts("WF");
        // if(find(s.begin(), s.end(), d[k][i].second) == s.end())
        //     puts("WF");
        e[d[k][i].first].push_back(d[k][i].second);
        e[d[k][i].second].push_back(d[k][i].first);
    }
    // printf("total edge %d\n", c);
    // for(i = 1; i <= 20; i ++) cout << 
    // if(s.size() >= c / 2)
    //     return false;

    for(x = 0; x < (signed)s.size(); x ++)
        if(e[s[x]].size() > 2)
            break;
    if(x == (signed)s.size())
        return false;
    x = s[x];

    // printf("bcc "); for(int xx : s) cout << xx << ' '; cout << endl;
    // printf("fetch center %d\n", x);
    w[x] = true;
    if(!DFS(x, 0, f))
        throw;
    w[x] = false;

    // printf("find loop\n"); for(int xx : f) cout << xx << ' '; cout << endl;
    f.pop_back();
    if(f.size() <= 2)
        throw;

    for(i = 0; i < (signed)s.size(); i ++)
        u[s[i]] = false;
    for(i = 1; i < (signed)f.size(); i ++)
        w[f[i]] = true;

    u[x] = true;
    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x][i] != f[1] && e[x][i] != f.back())
        {
            g.clear();
            if(DFS(e[x][i], x, g))
                break;
        }

    if(i < (signed)e[x].size())
    {
        printf("YES\n");
        printf("%d %d ", (int)g.size() + 1, x);
        for(i = 0; i < (signed)g.size(); i ++)
            printf("%d ", g[i]);

        for(i = 0; i < (signed)f.size() && f[i] != g.back(); i ++)
            h.push_back(f[i]);
        h.push_back(g.back());
        printf("\n%d ", (int)h.size());
        for(i = 0; i < (signed)h.size(); i ++)
            printf("%d ", h[i]);

        h.clear();
        for(i = (signed)f.size() - 1; i > -1 && f[i] != g.back(); i --)
            h.push_back(f[i]);
        h.push_back(g.back());
        printf("\n%d %d ", (int)h.size() + 1, x);
        for(i = 0; i < (signed)h.size(); i ++)
            printf("%d ", h[i]);
        printf("\n");
        // for(int xx : g) cout << xx << ' '; cout << endl;

        return true;
    }

    return false;
}

int main(void)
{
    int m, u, v;
    int i, j;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i ++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for(i = 1; i <= n; i ++)
        Tarjan(i);
    // printf("total %d\n", b.size());
    // for(i = 0; i < b.size(); i ++) {for(int xx : b[i]) cout << xx << ' '; cout << endl;}

    for(i = 1; i <= n; i ++)
    {
        for(j = 0; j < (signed)e[i].size(); j ++)
            if(i < e[i][j])
            {
                v = ::v[i] == ::v[e[i][j]] ? ::v[i] : ::v[::v[i]] == e[i][j] ? ::v[i] : ::v[e[i][j]];
                // printf("checking %d-%d : %d\n", i, e[i][j], v);
                d[v - n - 1].push_back(make_pair(i, e[i][j]));
            }
        e[i].clear();
    }

    for(i = 0; i < (signed)b.size(); i ++)
    {
        if(Solve(b[i], i))
            break;
        for(j = 0; j < (signed)b[i].size(); j ++)
        {
            e[b[i][j]].clear();
            ::u[b[i][j]] = w[b[i][j]] = false;
        }
    }
    if(i == (signed)b.size())
        printf("NO\n");

    return 0;
}