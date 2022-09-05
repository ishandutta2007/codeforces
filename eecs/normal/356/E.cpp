#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 998244353;
int n, len[25], pw[maxn];
int cnt[26][maxn], chk[20][maxn], h[maxn];
long long ans, inc, cost[maxn], coef[26][maxn];
char s[maxn];

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = len[0] = 1; i <= 16; i++) {
        len[i] = len[i - 1] * 2 + 1;
    }
    for (int i = pw[0] = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[j][i] = cnt[j][i - 1] + (s[i] - 'a' == j);
        }
        pw[i] = 233LL * pw[i - 1] % P;
        h[i] = (233LL * h[i - 1] + s[i]) % P;
    }
    auto get = [&](int l, int r) {
        return (h[r] - 1LL * h[l - 1] * pw[r - l + 1] % P + P) % P;
    };
    fill(chk[0] + 1, chk[0] + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        cost[i]++, cost[i + 1]--, ans++;
    }
    for (int i = 1; len[i] <= n; i++) {
        for (int l = 1, r = len[i]; r <= n; l++, r++) {
            int m = l + len[i - 1], c = s[m] - 'a';
            chk[i][l] = chk[i - 1][l] && (get(l, m - 1) == get(m + 1, r));
            if (cnt[c][r] - cnt[c][l - 1] != 1) chk[i][l] = 0;
            if (chk[i][l]) {
                ans += 1LL * len[i] * len[i];
                cost[l] += 1LL * len[i] * len[i], cost[r + 1] -= 1LL * len[i] * len[i];
            }
        }
    }
    auto lcp = [&](int l1, int l2) {
        int l = 1, r = n - max(l1, l2) + 1, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            get(l1, l1 + mid - 1) == get(l2, l2 + mid - 1) ? l = (ans = mid) + 1 : r = mid - 1;
        }
        return ans;
    };
    auto calc = [&](int l, int k) {
        if (k == 0) {
            for (int c = 0; c < 26; c++) coef[c][l]++;
            return;
        }
        int m = l + len[k - 1], _l = m + 1;
        long long w = 1LL * len[k] * len[k];
        if (chk[k - 1][l] && get(l, m - 1) == get(_l, _l + len[k - 1] - 1)) {
            for (int c = 0; c < 26; c++) {
                if (cnt[c][l - 1] == cnt[c][m - 1]) coef[c][m] += w;
            }
            return;
        }
        int p = lcp(l, _l);
        int m1 = l + p, m2 = _l + p;
        if (m1 + 1 + lcp(m1 + 1, m2 + 1) < m) return;
        if (chk[k - 1][l] && cnt[s[m] - 'a'][l - 1] == cnt[s[m] - 'a'][m - 1]) coef[s[m1] - 'a'][m2] += w;
        if (chk[k - 1][_l] && cnt[s[m] - 'a'][m] == cnt[s[m] - 'a'][_l + len[k - 1] - 1]) coef[s[m2] - 'a'][m1] += w;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 0; i + len[j] - 1 <= n; j++) calc(i, j);
    }
    for (int i = 1; i <= n; i++) {
        cost[i] += cost[i - 1];
        for (int c = 0; c < 26; c++) {
            inc = max(inc, coef[c][i] - cost[i]);
        }
    }
    printf("%lld\n", ans + inc);
    return 0;
}