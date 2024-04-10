#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
int n, m;
vector<int>g[N], g1[N];
bool ans[N];
int ans1 = 0;
int du[N];
bool bz[N], bz1[N];
void dfs(int x) {
    if (bz[x]) return;
    bz[x] = 1;
    for (auto u:g[x])
        dfs(u);
}
void dfs1(int x) {
    if (bz1[x]) return;
    bz1[x] = 1;
    for (auto u:g1[x])
        dfs1(u);
}
bool bfs() {
    vector<int> d;
    for (int u = 1; u <= n; u ++) {
        if (!du[u])
            d.push_back(u);
    }
    for (int i = 0; i < d.size(); i ++) {
        for (auto u:g[d[i]]) {
            if (!(--du[u]))
                d.push_back(u);
        }
    }
    return d.size() == n;
}
int main() {
    scanf("%d %d", &n, &m);
    while (m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g1[y].push_back(x);
        du[y] ++;
    }
    if (!bfs()) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; i ++) {
        if (!bz[i] && !bz1[i]) {
            ans1++;
            ans[i] = 1;
        }
        dfs(i);
        dfs1(i);
    }
    printf("%d\n", ans1);
    for (int i = 1; i <= n; i ++)
        if (ans[i])
            printf("A");
        else
            printf("E");
    return 0;
}