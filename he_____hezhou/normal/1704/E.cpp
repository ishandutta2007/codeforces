#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
int n, m;
vector <int> son[1010];
int a[1010], cnt[1010], b[1010];
int dfs(int cur) {
    if (cnt[cur] != -1) return cnt[cur];
    cnt[cur] = 0;
    for (auto v : son[cur]) if ((cnt[cur] += dfs(v)) >= mod) cnt[cur] -= mod;
    return cnt[cur];
}
void rmain() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), son[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        son[x].push_back(y);
    }
    int rt = -1;
    for (int i = 1; i <= n; i++) if (son[i].size() == 0) rt = i;
    memset(cnt, -1, sizeof cnt);
    cnt[rt] = 1;
    for (int i = 1; i <= n; i++) {
        int tag = 0;
        for (int j = 1; j <= n; j++) if (a[j]) tag = 1;
        if (tag == 0) return printf("%d\n", i - 1), void();
        memset(b, 0, sizeof b);
        for (int j = 1; j <= n; j++) if (a[j]) {
            b[j]--;
            for (auto v : son[j]) b[v]++;
        }
        for (int j = 1; j <= n; j++) a[j] += b[j];
    }
    int ans = n;
    for (int i = 1; i <= n; i++) ans = (ans + 1ll * dfs(i) * a[i]) % mod;
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}