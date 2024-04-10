#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
vector<int>g[N], gg[N], ggg[N];
int dfn[N], low[N], stack[N], tot, instack[N];
int belong[N];
int cnt;
int o[N], sum[N], du[N];
void dfs(int x) {
    low[x] = dfn[x] = ++tot;
    instack[stack[++stack[0]] = x] = 1;
    for (auto u:g[x])
        if (!dfn[u]) {
            dfs(u);
            low[x] = min(low[x], low[u]);
        }else
        if (instack[u])
            low[x] = min(low[x], dfn[u]);
    if (dfn[x] == low[x]) {
        ++cnt;
        do{
            belong[stack[stack[0]]] = cnt;
            instack[stack[stack[0]--]] = 0;
        } while (stack[stack[0] + 1] != x);
    }
}
int n, m;
void dfs1(int x) {
    stack[++stack[0]] = x;
    if (!gg[x].size()) {
        g[x].push_back(stack[max(stack[0] - m, 1)]);
    } else {
        for (auto u:gg[x])
            dfs1(u);
    }
    stack[0] --;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        g[x].push_back(i);
        gg[x].push_back(i);
    }
    dfs1(1);
    dfs(1);
    for (int i = 1; i <= n; i ++) {
        if (!gg[i].size())
            o[belong[i]] ++;
        for (auto u:g[i])
            if (belong[u] != belong[i]) {
                ggg[belong[i]].push_back(belong[u]);
                du[belong[u]] ++;
            }
    }
    for (int i = 1; i <= cnt; i ++)
        if (!du[i]) {
            stack[++stack[0]] = i;
        }
    int ans = 0;
    for (int i = 1; i <= stack[0]; i ++) {
        sum[stack[i]] += o[stack[i]];
        ans = max(ans, sum[stack[i]]);
        for (auto u:ggg[stack[i]]) {
            sum[u] = max(sum[u], sum[stack[i]]);
            if (!(--du[u]))
                stack[++stack[0]] = u;
        }
    }
    printf("%d\n", ans);
    return 0;
}