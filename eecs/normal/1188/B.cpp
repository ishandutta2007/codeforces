#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, P, K, a[maxn];
long long ans;

int main() {
    scanf("%d %d %d", &n, &P, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = (1LL * a[i] * a[i] % P * a[i] % P * a[i] - 1LL * a[i] * K % P + P) % P;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1, j; i <= n; i = j) {
        for (j = i; j <= n && a[i] == a[j]; j++);
        ans += 1LL * (j - i) * (j - i - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}