#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3101;
const long long mn = -1e18;
long long v[N];
pair<int, long long>f[N][N], c[N];
int sz[N];
vector<int> g[N];
int n, m;
pair<int, long long> add(pair<int, long long> a, pair<int, long long> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}
pair<int, long long> getmx(pair<int, long long> a, pair<int, long long> b) {
    return a.first > b.first || (a.first == b.first && a.second > b.second) ?  a : b;
}
void dfs(int x, int fa) {
    f[x][0].first = 0;
    f[x][0].second = v[x];
    sz[x] = 1;
    for (auto u:g[x])
        if (u != fa) {
            dfs(u, x);
            int tmp = sz[x];
            sz[x] = min(sz[x] + sz[u], m);
            for (int i = 0; i <= sz[x]; i ++)
                c[i] = make_pair(0, mn);
            for (int i = 0; i <= tmp; i ++)
                for (int j = 0; j <= sz[u] && i + j <= sz[x]; j ++)
                    c[i + j] = getmx(c[i + j],add(f[x][i], f[u][j]));
            for (int i = 0; i <= sz[x]; i ++)
                f[x][i] = c[i];
        }
    for (int i = sz[x]; i >= 0; i --)
        if (f[x][i].second > 0)
            f[x][i + 1] = getmx(f[x][i + 1], make_pair(f[x][i].first + 1, 0));
        else
            f[x][i + 1] = getmx(f[x][i + 1], make_pair(f[x][i].first , 0));
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++)
            for (int j = 0; j <= m; j ++)
                f[i][j].first = 0, f[i][j].second = mn;
        for (int i = 1; i <= n; i ++) {
            scanf("%lld", &v[i]);
        }
        for (int i = 1; i <= n; i ++) {
            int x;
            scanf("%d", &x);
            v[i] = x - v[i];
        }
        for (int i = 1; i < n; i ++) {
            int x, y;
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1, 0);
        int ans = 0;
        if (f[1][m].second >= 0) ans = max(ans, f[1][m].first);
        ans = max(ans, f[1][m - 1].first + (f[1][m - 1].second > 0));
        printf("%d\n", ans);
        for (int i = 1; i <= n; i ++)
            g[i].clear();
    }
    return 0;
}