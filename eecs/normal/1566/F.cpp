#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, m, a[maxn], pos[maxn], l[maxn], r[maxn], bel[maxn];
long long f[maxn];
pair<int, int> p[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        long long ans = 0;
        int sz = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &l[i], &r[i]);
            int pos = lower_bound(a + 1, a + n + 1, l[i]) - a;
            if (pos <= n && a[pos] <= r[i]) continue;
            p[++sz] = make_pair(l[i], r[i]);
        }
        sort(p + 1, p + sz + 1);
        vector<pair<int, int>> seg;
        for (int i = 1; i <= n; i++) {
            pos[i] = lower_bound(p + 1, p + sz + 1, make_pair(a[i], 0)) - p;
        }
        for (int i = 1, j; i <= n; i = j) {
            for (j = i; j <= n && pos[i] == pos[j]; j++);
            seg.emplace_back(i, j - 1);
        }
        for (int i = 1; i <= sz; i++) {
            bel[i] = lower_bound(a + 1, a + n + 1, p[i].first) - a;
        }
        fill(f + 1, f + sz + 1, 1e18);
        for (auto &q : seg) {
            int pos = lower_bound(p + 1, p + sz + 1, make_pair(a[q.first], 0)) - p;
            if (q.first < q.second) {
                long long mn = 1e18;
                int cur = a[q.first];
                for (int i = pos - 1; ~i; i--) {
                    mn = min(mn, f[i] + a[q.first] - cur);
                    cur = min(cur, p[i].second);
                    if (bel[i] != bel[pos - 1]) break;
                }
                f[pos - 1] = min(f[pos - 1], mn);
                for (int i = pos; i <= sz; i++) {
                    f[i] = min(f[i], mn + p[i].first - a[q.second]);
                    if (bel[i] != bel[pos]) break;
                }
            } else {
                long long mn = 1e18;
                int cur = a[q.first];
                for (int i = pos - 1; ~i; i--) {
                    mn = min(mn, f[i] + 2LL * (a[q.first] - cur));
                    cur = min(cur, p[i].second);
                    if (bel[i] != bel[pos - 1]) break;
                }
                f[pos - 1] = min(f[pos - 1], mn);
                for (int i = pos; i <= sz; i++) {
                    f[i] = min(f[i], mn + p[i].first - a[q.second]);
                    if (bel[i] != bel[pos]) break;
                }
                mn = 1e18, cur = a[q.first];
                for (int i = pos - 1; ~i; i--) {
                    mn = min(mn, f[i] + a[q.first] - cur);
                    cur = min(cur, p[i].second);
                    if (bel[i] != bel[pos - 1]) break;
                }
                f[pos - 1] = min(f[pos - 1], mn);
                for (int i = pos; i <= sz; i++) {
                    f[i] = min(f[i], mn + 2LL * (p[i].first - a[q.second]));
                    if (bel[i] != bel[pos]) break;
                }
            }
        }
        printf("%lld\n", f[sz]);
    }
    return 0;
}