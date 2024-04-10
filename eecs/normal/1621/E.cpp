#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, m, a[maxn], id[maxn], ans[maxn], pre[maxn], suf[maxn];
int pre2[maxn], pre3[maxn];
long long s[maxn];
vector<array<int, 2>> V[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1, greater<>());
        reverse(a + 1, a + m + 1);
        int tot = 0;
        for (int i = 1, k; i <= m; i++) {
            scanf("%d", &k);
            s[i] = 0, V[i].clear();
            while (k--) {
                int b;
                scanf("%d", &b), s[i] += b;
                V[i].push_back({b, ++tot});
            }
            s[i] = (s[i] + V[i].size() - 1) / V[i].size();
        }
        iota(id + 1, id + m + 1, 1);
        sort(id + 1, id + m + 1, [&](int i, int j) { return s[i] < s[j]; });
        for (int i = 1; i <= m; i++) {
            pre[i] = pre[i - 1] + (s[id[i]] > a[i]);
        }
        for (int i = 2; i <= m; i++) {
            pre2[i] = pre2[i - 1] + (s[id[i]] > a[i - 1]);
        }
        for (int i = 1; i < m; i++) {
            pre3[i] = pre3[i - 1] + (s[id[i]] > a[i + 1]);
        }
        suf[m + 1] = 0;
        for (int i = m; i; i--) {
            suf[i] = suf[i + 1] + (s[id[i]] > a[i]);
        }
        for (int i = 1; i <= m; i++) {
            long long s = 0;
            for (auto &p : V[id[i]]) s += p[0];
            for (auto &p : V[id[i]]) {
                int ns = (s - p[0] + V[id[i]].size() - 2) / (V[id[i]].size() - 1);
                int j = lower_bound(a + 1, a + m + 1, ns) - a;
                if (j > m) { ans[p[1]] = 0; continue; }
                if (j >= i) {
                    ans[p[1]] = !pre[i - 1] && !suf[j + 1] && !(pre2[j] - pre2[i]);
                } else {
                    ans[p[1]] = !pre[j - 1] && !suf[i + 1] && !(pre3[i - 1] - pre3[j - 1]);
                }
            }
        }
        for (int i = 1; i <= tot; i++) {
            putchar(ans[i] + '0');
        }
        putchar('\n');
    }
    return 0;
}