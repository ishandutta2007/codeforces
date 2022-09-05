#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, q, a[maxn], b[maxn], c[maxn];
long long s[maxn], st[20][maxn], _st[20][maxn];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        c[i] = b[i] - a[i];
        st[0][i] = _st[0][i] = s[i] = s[i - 1] + c[i];
    }
    for (int i = 1; 1 << i <= n; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            _st[i][j] = min(_st[i - 1][j], _st[i - 1][j + (1 << (i - 1))]);
        }
    }
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (s[l - 1] != s[r]) { puts("-1"); continue; }
        int k = log2(r - l + 1);
        long long mn = min(_st[k][l], _st[k][r - (1 << k) + 1]) - s[l - 1];
        if (mn < 0) { puts("-1"); continue; }
        printf("%lld\n", max(st[k][l], st[k][r - (1 << k) + 1]) - s[l - 1]);
    }
    return 0;
}