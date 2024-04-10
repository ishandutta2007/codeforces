#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn], f[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        f[n] = f[n + 1] = a[n + 1] = 0;
        for (int i = n - 1; i; i--) {
            f[i] = f[i + 1] + (a[i] == a[i + 1]);
        }
        int ans = 0;
        for (int i = 1, v = (int)1e9; i < n; i++) {
            if (a[i] == a[i + 1] && f[i + 2] + (a[i + 1] == a[i + 2]) > 0) a[i + 1] = a[i + 2] = ++v, ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}