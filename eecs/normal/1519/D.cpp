#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n, a[maxn], b[maxn];
long long ans, pre[maxn], suf[maxn], sum[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + 1LL * a[i] * b[i];
    }
    for (int i = n; i; i--) {
        suf[i] = suf[i + 1] + 1LL * a[i] * b[i];
    }
    ans = pre[n];
    for (int i = 2; i <= 2 * n; i++) {
        for (int j = 1; j <= min(n, i); j++) {
            sum[j] = sum[j - 1] + 1LL * a[j] * b[i - j];
        }
        for (int j = 1; j <= n; j++) {
            int k = i - j;
            if (k < j || k > n) continue;
            ans = max(ans, pre[j - 1] + suf[k + 1] + sum[k] - sum[j - 1]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}