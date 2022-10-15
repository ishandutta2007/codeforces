#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;

inline int getint()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while ('0' <= c && c <= '9')
    {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}

struct edge { int src, dst; int rev; };

int n, m;
int ans;
vector <edge> e;
vector < vector <int> > g;
vector <char> used;
vector <int> tin, fup;
vector <char> is_bridge;
vector <int> v2comp;
vector < vector <int> > comps;
vector < vector <int> > cg;
int cn;
int timer;

inline int src(int v) { return (v < 0) ? e[-v - 1].dst : e[v - 1].src; }
inline int dst(int v) { return (v < 0) ? e[-v - 1].src : e[v - 1].dst; }
inline int index(int v) { return (v < 0) ? -v - 1 : v - 1; }
inline edge& get(int v) { return e[index(v)]; }
inline void orient(int v) { get(v).rev = v < 0; }

void in_all()
{
    n = getint(); m = getint();
    e.resize(m);
    for (int i = 0; i < m; i++)
    {
        e[i].src = getint(); e[i].dst = getint();
        e[i].src--; e[i].dst--;
        e[i].rev = -1;
    }
}

void make_graph()
{
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        g[e[i].src].push_back(+i + 1);
        g[e[i].dst].push_back(-i - 1);
    }
}

void bridge_dfs(int v, int p)
{
    tin[v] = fup[v] = ++timer;
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = dst(g[v][i]);
        if (to == p) continue;
        if (used[to])
            fup[v] = min(fup[v], tin[to]);
        else
        {
            bridge_dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v])
                is_bridge[index(g[v][i])] = true;
        }
    }
}

void find_bridges()
{
    is_bridge.assign(m, false);
    used.assign(n, false);
    tin.assign(n, 0); fup.assign(n, 0);
    timer = 0;
    bridge_dfs(0, -1);
}

void comp_dfs(int v, int p, int id)
{
    used[v] = true;
    v2comp[v] = id;
    comps[id].push_back(v);
    for (int i = 0; i < g[v].size(); i++)
    {
        if (is_bridge[index(g[v][i])]) continue;
        int to = dst(g[v][i]);
        if (!used[to])
            comp_dfs(to, v, id);
    }
}

void find_comps()
{
    v2comp.resize(n);
    comps.clear();
    used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            comps.push_back(vector<int>());
            comp_dfs(i, -1, comps.size() - 1);
        }
    cn = comps.size();
}

void make_comp_tree()
{
    cg.resize(cn);
    for (int i = 0; i < m; i++)
    {
        int csrc = v2comp[e[i].src],
            cdst = v2comp[e[i].dst];
        if (csrc == cdst) continue;
        cg[csrc].push_back(+i + 1);
        cg[cdst].push_back(-i - 1);
    }
}

int biggest_comp()
{
    int res = 0;
    for (int i = 1; i < cn; i++)
        if (comps[i].size() > comps[res].size()) res = i;
    return res;
}

void orient_tree(int v, int p = -1)
{
    for (int i = 0; i < cg[v].size(); i++)
    {
        int eid = cg[v][i], to = v2comp[dst(cg[v][i])];
        if (to == p) continue;
        orient(-eid);
        orient_tree(to, v);
    }
}

void orient_dfs(int v, int p)
{
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int eid = g[v][i], to = dst(eid);
        if (is_bridge[index(eid)]) continue;
        orient(eid);
        if (!used[to])
            orient_dfs(to, v);
    }
}

void orient_comps()
{
    used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
            orient_dfs(i, -1);
}

void out_all()
{
    printf("%d\n", ans);
    for (int i = 0; i < m; i++)
    {
        int adst = 0, asrc = 0;
        switch (e[i].rev)
        {
            case 0: asrc = e[i].src+1; adst = e[i].dst+1; break;
            case 1: asrc = e[i].dst+1; adst = e[i].src+1; break;
        }
        printf("%d %d\n", asrc, adst);
    }
}

int main()
{
    in_all();
    make_graph();
    find_bridges();
    find_comps();
    make_comp_tree();
    int bc = biggest_comp();
    ans = comps[bc].size();
    orient_tree(bc);
    orient_comps();
    out_all();
    return 0;
}