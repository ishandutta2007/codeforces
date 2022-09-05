#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, a[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int mn = *min_element(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((a[i] - mn) % K) puts("-1"), exit(0);
        ans += (a[i] - mn) / K;
    }
    printf("%lld\n", ans);
    return 0;
}