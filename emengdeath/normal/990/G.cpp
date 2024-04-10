#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
const int MAXN = 200000;
int n, tot;
bool bz[N];
vector<int>g[N], edge[N];
int e[N * 2][2], gg[N];
int sz;
long long ans[N];
void add(int x, int y) {
    e[++tot][0] = y;
    e[tot][1] = gg[x];
    gg[x] = tot;
}
void dfs(int x) {
    bz[x] = 0;
    sz ++;
    for (int i = gg[x]; i; i = e[i][1])
        if (bz[e[i][0]])
            dfs(e[i][0]);
    gg[x] = 0;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        for (int j = 1; 1ll * j * j <= x; j ++)
            if ((x % j) == 0) {
                g[j].push_back(i);
                if (j * j != x)
                    g[x / j].push_back(i);
            }
    }
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 1; i <= MAXN; i ++)
        if (g[i].size()){
            tot = 0;
            for (auto u:g[i])
                bz[u] = 1;
            for (auto u:g[i])
                for (auto v:edge[u])
                    if (bz[v])
                        add(u, v);
            for (auto u:g[i])
                if (bz[u]) {
                    sz = 0;
                    dfs(u);
                    ans[i] += 1ll * sz * (sz - 1) / 2 + sz;
                }
        }
    for (int i = MAXN; i; i --)
        for (int j = 2; 1ll * j *i <= MAXN; j ++)
            ans[i] -= ans[i * j];
    for (int i = 1; i <= MAXN; i ++)
        if (ans[i])
            printf("%d %lld\n", i, ans[i]);
    return 0;
}