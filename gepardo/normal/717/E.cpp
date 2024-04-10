#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

inline int get_int()
{
    int n;
    scanf("%d", &n);
    return n;
}

int n = get_int();
int col[200000];
vector < vector<int> > g(n);

void go_to(int e)
{
    col[e] *= -1;
    printf(" %d", e+1);
}

void dfs(int v, int p = -1)
{
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (to == p) continue;
        go_to(to);
        dfs(to, v);
        go_to(v);
    }
    if (col[v] == -1)
    {
        if (p == -1)
        {
            go_to(g[0][0]);
            go_to(v);
            go_to(g[0][0]);
        }
        else
        {
            go_to(p);
            go_to(v);
        }
    }
}

int main()
{
    for (int i = 0; i < n; i++) col[i] = get_int();
    for (int i = 1; i < n; i++)
    {
        int a = get_int() - 1, b = get_int() - 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    printf("1");
    dfs(0);
}