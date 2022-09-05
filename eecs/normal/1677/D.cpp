#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 998244353;
int T, n, K, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (i + K > n && a[i] > 0) flag = 0;
        }
        int ans = 1;
        for (int i = 1; i <= K; i++) {
            ans = 1LL * ans * i % P;
        }
        for (int i = 1; i + K <= n; i++) {
            if (!~a[i]) ans = 1LL * ans * (i + K) % P;
            else if (!a[i]) ans = 1LL * ans * (K + 1) % P;
            else if (a[i] + K >= i + K) flag = 0;
        }
        if (!flag) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}