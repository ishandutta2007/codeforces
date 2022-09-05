#include <bits/stdc++.h>
using namespace std;

const int maxn = 7010;
int n, m, lg[1000000], l[maxn], r[maxn];
int lev[maxn], lb[maxn], rb[maxn], val[maxn], vis[1000010];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < 1000000; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1, op; i <= m; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %d %d", &lev[i], &lb[i], &rb[i], &val[i]);
        } else {
            int t, v, ans = 0;
            scanf("%d %d", &t, &v);
            l[t] = r[t] = v;
            for (int j = t + 1; j <= n; j++) {
                l[j] = l[j - 1] + lg[l[j - 1] - 1];
                r[j] = r[j - 1] + lg[r[j - 1]];
            }
            for (int j = 1; j < i; j++) if (lev[j]) {
                if (lev[j] >= t && max(lb[j], l[lev[j]]) <= min(rb[j], r[lev[j]])) {
                    if (vis[val[j]] ^ i) vis[val[j]] = i, ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}