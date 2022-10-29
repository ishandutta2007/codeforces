#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6;
const int M = 1 * 2 * 3 * 4 *5 *6;
int id[N], a[N], v[M];
int n, k;
bool bz[N];
int cnt = 0;
int f[M][M];
int w[M];
int fa[N], sz[N];
void dfs(int step, int x) {
    if (step == k) {
        id[x] = cnt;
        v[cnt] = x;
        cnt ++;
        return;
    }
    for (int i = 0; i < k; i ++)
        if (!bz[i]) {
            bz[i] = 1;
            dfs(step + 1, x * k + i);
            bz[i] = 0;
        }
}
int work(int x ,int y) {
    x = v[x], y = v[y];
    vector<int>a;
    for (int i = 0; i < k; i ++)
        a.push_back(x % k), x /= k;
    reverse(a.begin(), a.end());
    int out = 0;
    for (int i = k - 1; i >= 0; i --)
        out = out * k + a[y % k], y /= k;
    y = 0;
    for (int i = 0; i < k; i ++)
        y = y * k + out % k, out /= k;
    return id[y];
}
int getfa(int x){
    return fa[x] == x? x : fa[x] = getfa(fa[x]);
}
int main() {
    scanf("%d %d", &n, &k);
    dfs(0, 0);
    for (int i = 0; i < cnt; i ++)
        for (int j = 0; j < cnt; j ++)
            f[i][j] = work(i, j);
    for (int i = 1;i <=n ;i++) {
        int x = 0;
        for (int j = 0; j < k; j ++) {
            int y;
            scanf("%d", &y);
            x = x * k + (y - 1);
        }
        a[i] = id[x];
    }
    long long ans = 0;
    for (int i = 1;i <= n; i ++) {
        w[a[i]] = i;
        vector<int> b;
        for (int j = 0; j < cnt; bz[j] = 0, fa[j] = j, sz[j] = 1, j ++)
            if (w[j]) {
                b.push_back(w[j]);
            }
        sort(b.rbegin(), b.rend());
        int last = i;
        for (auto u:b)
            if (getfa(a[u]) != getfa(0)){
                ans += 1ll * (last - u) * sz[getfa(0)];
                for (int i = 0; i < cnt; i ++) {
                    int x = getfa(i), y = getfa(f[i][a[u]]);
                    if (y != x)
                        fa[y] = x,sz[x] += sz[y];
                }
                last = u;
            }
        ans += 1ll * last * sz[getfa(0)];
    }
    printf("%lld\n", ans);
    return 0;
}