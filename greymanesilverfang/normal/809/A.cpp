#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
ll pwr2[300005], x[300005];

int main() {
    int n;
    scanf("%d", &n);
    pwr2[0] = 1;
    for (int i = 1; i < n; ++i)
        (pwr2[i] = pwr2[i - 1] * 2) %= MOD;
    for (int i = 0; i < n; ++i)
        scanf("%I64d", &x[i]);
    sort(x, x + n);
    ll ans = 0;
    for (int i = 0, j = n - 1; i < j; ++i, --j)
        (ans += (x[j] - x[i]) * (pwr2[i] * (pwr2[j - i] - 1) % MOD)) %= MOD;
    printf("%I64d", ans);
    return 0;
}