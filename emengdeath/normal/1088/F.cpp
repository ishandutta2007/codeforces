#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6;
int fa[N][22];
int a[N];
int n;
long long ans = 0;
vector<int>g[N];
void dfs(int x) {
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u != fa[x][0]) {
            fa[u][0] = x;
            dfs(u);
        }
}
int main() {
    scanf("%d", &n);
    int x = 1;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (a[i] < a[x]) x = i;
    }
    for (int i = 1; i < n ; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(x);
    for (int i = 1; i <=n; i ++)
        if (x != i) {
            long long v = 1e18;
            for (int j = 0; j <= 20; j++){
                int y = (fa[i][j] ?fa[i][j]:x);
                v = min(v, 1ll * (j + 1) * a[y] + a[i]);
            }
            ans += v;
        }
    printf("%lld\n", ans);
    return 0;
}