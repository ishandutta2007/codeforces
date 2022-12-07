#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int n, c;
int f[700005], rf[700005];

const int MOD = 1000003;

int binPow(LL x, int p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * x % MOD;
        p >>= 1;
        if (p) x = x * x % MOD;
    }
    return (int)res;
}

int C(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

int main() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < 700005; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
        rf[i] = binPow(f[i], MOD - 2);
    }
    cin >> n >> c;
    int ans = C(n + c, n);
    --ans;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}