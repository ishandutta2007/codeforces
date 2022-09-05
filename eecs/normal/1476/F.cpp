#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int T, n, p[maxn], f[maxn], pre[maxn], st[20][maxn];
char s[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]), st[0][i] = i + p[i];
        }
        for (int k = 1; 1 << k <= n; k++) {
            for (int i = 1; i + (1 << k) - 1 <= n; i++) {
                st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
        auto qmax = [&](int l, int r) {
            if (l > r) return 0;
            int k = __lg(r - l + 1);
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        };
        for (int i = 1; i <= n; i++) {
            if (f[i - 1] < i) f[i] = f[i - 1];
            else f[i] = max(f[i - 1], i + p[i]), pre[i] = i;
            int j = lower_bound(f, f + i, i - p[i] - 1) - f;
            if (i == j) continue;
            int v = max({i - 1, f[j], qmax(j + 1, i - 1)});
            if (f[i] < v) f[i] = v, pre[i] = j;
        }
        if (f[n] < n) { puts("NO"); continue; }
        puts("YES");
        int cur = n;
        while (cur) {
            if (cur == pre[cur]) s[cur] = 'R', cur--;
            else s[cur] = 'L', fill(s + pre[cur] + 1, s + cur, 'R'), cur = pre[cur];
        }
        for (int i = 1; i <= n; i++) putchar(s[i]);
        putchar('\n');
    }
    return 0;
}