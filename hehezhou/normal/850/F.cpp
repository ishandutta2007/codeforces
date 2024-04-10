#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
int s, n, a[2510], d[100010];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        s = (s + a[i]) % mod;
    }
    d[1] = 1ll * (s - 1) * (s - 1) % mod * power(s, mod - 2) % mod;
    d[2] = (d[1] + d[1] - 1) % mod;
    for (int i = 3; i <= 100000; i++) {
        d[i] = (2 * d[i - 1] - d[i - 2] + 1ll * (mod - s + 1) * power(s - i + 1, mod - 2)) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + d[a[i]]) % mod;
    return cout << ans << endl, 0;
}