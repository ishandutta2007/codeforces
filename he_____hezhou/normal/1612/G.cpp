#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
int n, a[500010], b[500010];
ll cur[500010];
ll _cnt[2000010], *cnt = _cnt + 1000005;
int fac[500010];
inline int calc(int a) {
    const int inv6 = (mod + 1) / 6;
    return 1ll * a * (a + 1) % mod * (2 * a + 1) % mod * inv6 % mod;
}
int main() {
    scanf("%d", &n);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        cnt[a[i] - 1]++;
        cnt[-a[i] - 1]--;
    }
    const int m = 1000000;
    for (int i = m; i >= -m; i--) cnt[i - 2] += cnt[i];
    int ans2 = 1;
    int ans = 0, sum = 0;
    for (int i = m; i >= -m; i--) if (cnt[i]) {
        ans2 = 1ll * ans2 * fac[cnt[i]] % mod;
        int cur = i < 0 ? i + mod : i;
        ans = (ans + 1ll * cnt[i] * sum + 1ll * cur * calc(cnt[i])) % mod;
        sum = (sum + 1ll * cur * cnt[i]) % mod;
    }
    cout << ans << ' ' << ans2 << endl;
}