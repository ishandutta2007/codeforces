#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000010, P = 1000000007;
int n, pre[maxn], mn[21][maxn], h[maxn], pw[maxn];
char s[maxn];

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    copy(s + 1, s + n + 1, s + n + 1);
    for (int i = pw[0] = 1; i <= 2 * n; i++) {
        pre[i] = mn[0][i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
        h[i] = (10007LL * h[i - 1] + s[i]) % P;
        pw[i] = 10007LL * pw[i - 1] % P;
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j + (1 << i) - 1 <= 2 * n; j++) {
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
        }
    }
    auto get = [&](int l, int r) {
        int k = __lg(r - l + 1);
        return min(mn[k][l], mn[k][r - (1 << k) + 1]);
    };
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        if (get(i, i + n - 1) - pre[i - 1] >= min(0, pre[n])) { flag = 1; break; }
    }
    assert(flag);
    auto get_hash = [&](int l, int r) {
        return (h[r] - 1LL * h[l - 1] * pw[r - l + 1] % P + P) % P;
    };
    auto comp = [&](int p, int q) {
        int l = 1, r = n, pos = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (get_hash(p, p + mid - 1) == get_hash(q, q + mid - 1)) l = (pos = mid) + 1;
            else r = mid - 1;
        }
        return s[p + pos] > s[q + pos];
    };
    int ans = 0;
    for (int i = 1; i <= n; i++) if (get(i, i + n - 1) - pre[i - 1] >= min(0, pre[n])) {
        if (!ans || comp(ans, i)) { ans = i; continue; }
    }
    if (pre[n] < 0) {
        pre[n] *= -1;
        while (pre[n]--) putchar('(');
    }
    for (int i = ans; i < ans + n; i++) {
        putchar(s[i]);
    }
    if (pre[n] > 0) {
        while (pre[n]--) putchar(')');
    }
    return 0;
}