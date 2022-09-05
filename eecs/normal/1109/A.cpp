#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, a[2][1 << 20];
long long ans;

int main() {
    scanf("%d", &n);
    int cur = 0;
    a[0][0]++;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x), cur ^= x;
        ans += a[i & 1][cur]++;
    }
    printf("%lld\n", ans);
    return 0;
}