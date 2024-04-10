#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, x;
long long ans, a[maxn], pre[maxn], suf[maxn];

int main() {
    scanf("%d %d %d", &n, &K, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), pre[i] = pre[i - 1] | a[i];
    }
    for (int i = n; i; i--) {
        suf[i] = suf[i + 1] | a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) a[i] *= x;
        ans = max(ans, pre[i - 1] | a[i] | suf[i + 1]);
    }
    printf("%lld\n", ans);
    return 0;
}