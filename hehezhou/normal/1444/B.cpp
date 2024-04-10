#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
int n, a[300010];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) scanf("%d", a + i);
    sort(a + 1, a + 1 + n + n);
    int sum = 0;
    for (int i = 1; i <= n; i++) sum = (sum + mod - a[i]) % mod;
    for (int i = n + 1; i <= 2 * n; i++) sum = (sum + a[i]) % mod;
    for (int i = n + 1; i <= n + n; i++) sum = 1ll * i * sum % mod;
    for (int i = 1; i <= n; i++) sum = 1ll * power(i, mod - 2) * sum % mod;
    printf("%d\n", sum);
}