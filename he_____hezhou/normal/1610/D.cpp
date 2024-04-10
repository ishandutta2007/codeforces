#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
int n;
int a[200010], cnt[32];
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int cur = 0;
        for (int tmp = a[i]; tmp % 2 == 0; tmp >>= 1, cur++);
        cnt[cur]++;
    }
    int ans = power(2, n) - 1;
    for (int i = 1; i < 30; i++) if (cnt[i]) {
        int cur = power(2, cnt[i] - 1);
        for (int j = i + 1; j < 30; j++) cur = 1ll * cur * power(2, cnt[j]) % mod;
        ans = (ans + mod - cur) % mod;
    }
    cout << ans << endl;
}