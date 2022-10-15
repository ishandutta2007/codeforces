#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

struct edge
{
    int a, b;
    int o;
    edge() {}
    edge(int a, int b) : a(a), b(b), o(0) {}
};

int n, m;
vector <edge> e;
vector < vector <int> > g;

inline int dst(int i)
{
    return (i > 0) ? e[+i - 1].b : e[-i - 1].a;
}

inline int src(int i)
{
    return (i > 0) ? e[+i - 1].a : e[-i - 1].b;
}

inline edge& edge_link(int i)
{
    return (i > 0) ? e[+i - 1] : e[-i - 1];
}

inline void apply_orientation(int i)
{
    edge_link(i).o = (i > 0) ? 1 : -1;
}

void euler_cycle(int v)
{
    for (int i = 0; i < g[v].size(); i++)
    {
        if (edge_link(g[v][i]).o != 0) continue;
        apply_orientation(g[v][i]);
        euler_cycle(dst(g[v][i]));
    }
}

inline void push_edge(int a, int b)
{
    e.push_back(edge(a, b));
    g[a].push_back(+(int)e.size());
    g[b].push_back(-(int)e.size());
}

void testcase()
{
    cin >> n >> m;
    e.clear(); g.clear();
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--, b--;
        push_edge(a, b);
    }
    vector <int> q;
    for (int i = 0; i < n; i++)
        if (g[i].size() & 1)
            q.push_back(i);
    for (int i = 0; i < q.size(); i += 2)
        push_edge(q[i], q[i+1]);
    for (int i = 0; i < n; i++)
        euler_cycle(i);
    cout << n - q.size() << '\n';
    for (int i = 0; i < m; i++)
        if (e[i].o < 0)
            cout << e[i].a + 1 << " " << e[i].b + 1 << '\n';
        else
            cout << e[i].b + 1 << " " << e[i].a + 1 << '\n';
}

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        testcase();
    return 0;
}