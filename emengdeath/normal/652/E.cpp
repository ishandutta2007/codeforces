#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6;
vector<int>g[N], e[N];
bool bz[N];
int dfn[N], low[N], stack[N], instack[N];
int belong[N];
int cnt, n, m;
int tot;
int deep[N], fa[N];
vector<pair<int, int> >  w;
void dfs(int x, int fa) {
    low[x] = dfn[x] = ++tot;
    instack[stack[++stack[0]] = x] = 1;
    for (auto u:g[x])
        if (u!=fa) {
            if (!dfn[u]) {
                dfs(u, x);
                low[x] = min(low[x], low[u]);
            } else if (instack[u])
                low[x] = min(low[x], dfn[u]);
        }
    if (dfn[x] == low[x]) {
        vector<int>d;
        ++ cnt;
        do{
            belong[stack[stack[0]]] = cnt;
            instack[stack[stack[0]--]] = 0;
        } while (stack[stack[0] + 1] != x);

    }
}
void dfs1(int x) {
    bz[x] = 1;
    deep[x ] ++;
    for (auto u:e[x])
        if (!bz[u])
        {
            deep[u] = deep[x];
            fa[u] = x;
            dfs1(u);
        }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(y);
        g[y].push_back(x);
        if (z)
            w.push_back({x, y});
    }
    dfs(1, 0);
    for (int i= 1; i <= n; i ++)
        for (auto u:g[i])
            if (belong[i] != belong[u])
                e[belong[i]].push_back(belong[u]);
    dfs1(1);
    int x, y;
    scanf("%d %d", &x, &y);
    x = belong[x];
    y = belong[y];
    for (int i = 1; i <= tot; i ++) bz[i] = 0;
    while (x!=y) {
        if (deep[x] < deep[y]) swap(x, y);
        bz[x] = 1;
        x = fa[x];
    }
    bz[x] = 1;
    bool ans = 0;
    for (auto u:w)
        ans |= (bz[belong[u.first]] && bz[belong[u.second]]);
    ans?puts("YES"):puts("NO");
    return 0;
}