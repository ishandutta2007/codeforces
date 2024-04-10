#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, SZ = 350;
int n, K, q, a[maxn], nxt[2][maxn], lst[2][maxn];
int bel[maxn], bl[maxn], br[maxn], tag[maxn];

int main() {
    scanf("%d %d %d", &n, &K, &q), K++;
    for (int i = 1; i <= n; i++) {
        long long v; scanf("%lld", &v);
        a[i] = 1 - v % 2, br[bel[i] = (i - 1) / SZ + 1] = i;
        if (!bl[bel[i]]) bl[bel[i]] = i;
    }
    auto build = [&](int k) {
        for (int t : {0, 1}) {
            for (int i = bl[k]; i <= br[k]; i++) {
                lst[t][i] = i == bl[k] ? -1 : lst[t][i - 1];
                if (a[i] == t) lst[t][i] = i;
                nxt[t][i] = i;
                if (i - K >= bl[k] && ~lst[t][i - K]) nxt[t][i] = nxt[t][lst[t][i - K]];
            }
        }
    };
    for (int k = 1; k <= bel[n]; k++) {
        build(k);
    }
    while (q--) {
        int op, s, t;
        long long d;
        scanf("%d %d %d", &op, &s, &t);
        if (op == 1) {
            scanf("%lld", &d);
            if (!(d %= 2)) continue;
            if (bel[s] == bel[t]) {
                for (int i = s; i <= t; i++) a[i] ^= 1;
            } else {
                for (int i = s; i <= br[bel[s]]; i++) a[i] ^= 1;
                for (int i = bel[s] + 1; i < bel[t]; i++) tag[i] ^= 1;
                for (int i = bl[bel[t]]; i <= t; i++) a[i] ^= 1;
                build(bel[t]);
            }
            build(bel[s]);
        } else {
            int p = t + K;
            if (bel[s] == bel[t]) {
                for (int i = t; i >= s; i--) {
                    if (p >= i + K && a[i] == tag[bel[s]]) p = i;
                }
            } else {
                for (int i = t; i >= bl[bel[t]]; i--) {
                    if (p >= i + K && a[i] == tag[bel[t]]) p = i;
                }
                for (int i = bel[t] - 1; i > bel[s]; i--) {
                    int t = min(br[i], p - K);
                    if (t >= bl[i] && ~lst[tag[i]][t]) p = nxt[tag[i]][lst[tag[i]][t]];
                }
                for (int i = br[bel[s]]; i >= s; i--) {
                    if (p >= i + K && a[i] == tag[bel[s]]) p = i;
                }
            }
            puts(s < p ? "1" : "2");
        }
    }
    return 0;
}