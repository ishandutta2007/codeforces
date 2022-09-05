#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, ans, a[maxn], b[maxn], s[maxn], d[maxn], q[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n + 1; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }
    d[0] = d[n + 1] = ans = 1e9, b[n] = n + 1;
    for (int i = 2; i <= n; i++) {
        int j = i - 1;
        while ((s[i] - s[a[j]]) / 2 > d[j]) j = a[j];
        a[i] = j;
    }
    for (int i = n - 1; i; i--) {
        int j = i + 1;
        while ((s[b[j]] - s[i]) / 2 > d[j]) j = b[j];
        b[i] = j;
    }
    for (int i = 0; i <= n + 1; i++) {
        a[i] = s[a[i]] + d[i] * 2, b[i] = s[b[i]] - d[i] * 2;
    }
    for (int i = 1, t = 0; i <= n + 1; i++) {
        if (a[i - 1] > s[i - 1]) {
            while (t && a[q[t]] < a[i - 1]) t--;
            q[++t] = i - 1;
        }
        if (b[i] < s[i]) {
            int l = 1, r = t, m = (l + r + 1) / 2;
            while (l < r) {
                if (b[i] <= a[q[m]]) l = m;
                else r = m - 1;
                m = (l + r + 1) / 2;
            }
            ans = min(ans, s[i] - s[q[m]]);
            l = 1, r = t, m = (l + r + 1) / 2;
            while (l < r) {
                if (s[i] <= a[q[m]]) l = m;
                else r = m - 1;
                m = (l + r + 1) / 2;
            }
            if (b[i] <= s[q[m]] && (i != n + 1 || q[m])) puts("0"), exit(0);
        }
    }
    printf("%.1f\n", ans / 2.0);
    return 0;
}