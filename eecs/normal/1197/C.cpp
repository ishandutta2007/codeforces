#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, k, b[maxn], c[maxn];
long long ans;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 2; i <= n; i++) {
        c[i] = b[i] - b[i - 1];
    }
    sort(c + 2, c + n + 1, greater<int>());
    ans = b[n] - b[1];
    for (int i = 2; i <= k; i++) {
        ans -= c[i];
    }
    printf("%lld\n", ans);
    return 0;
}