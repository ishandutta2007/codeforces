#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e6 + 10;
int n, T;
vector<int>g[N];
int dfn[N], low[N], stack[N], tot, instack[N];
vector<int>ans;
void dfs(int x) {
    low[x] = dfn[x] = ++tot;
    instack[stack[++stack[0]] = x] = 0;
    for (auto u:g[x])
        if (!dfn[u]) {
            dfs(u);
            low[x] = min(low[x], low[u]);
        }else
            low[x] = min(low[x], dfn[u]);
    if (dfn[x] == low[x]) {
        vector<int>d;
        do{
            d.push_back(stack[stack[0]]);
            instack[stack[stack[0]--]] = 0;
        } while (stack[stack[0] + 1] != x);
        if (d.size() >= 2) ans = d;
    }
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
        {
            int x;
            scanf("%d", &x);
            int y = i - x;
            g[i + n].push_back(y);
            g[i].push_back(i + n);
        }
        tot = 0;
        for (int i = 1; i <= n + n ; i++)
            if (!dfn[i])
                dfs(i);
        for (int i = 1; i <= n + n ; i ++)
            g[i].clear(), dfn[i] = low[i] = 0;
        printf("%d\n", ans.size() / 2);
        for (auto u:ans)
            if (u <= n)
                printf("%d ", u);
        printf("\n");
    }
    return 0;
}