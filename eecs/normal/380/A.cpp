#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int m, n, op[maxn], x[maxn], y[maxn], a[maxn], ans[maxn];
ll len, qx[maxn];

int main() {
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &op[i], &x[i]);
        if (op[i] == 2) scanf("%d", &y[i]);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &qx[i]);
    }
    for (int i = 1, j = 1; i <= m; i++) {
        if (op[i] == 1) {
            if (++len <= 100000) a[len] = x[i];
            for (; j <= n && qx[j] == len; j++) ans[j] = x[i];
        } else {
            ll o = len;
            for (int $ = 1; $ <= y[i] && o < 100000; $++) {
                for (int k = 1; k <= x[i]; k++) a[++o] = a[k];
            }
            o = len, len += 1LL * x[i] * y[i];
            for (; j <= n && qx[j] <= len; j++) {
                ans[j] = a[(qx[j] - o - 1) % x[i] + 1];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}