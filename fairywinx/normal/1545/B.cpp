#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

const int mod = 998244353;
const int N = 1e5 + 228;

int powm(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return 1ll * a * powm(a, b - 1) % mod;
    int z = powm(a, b / 2);
    return 1ll * z * z % mod;
}

int fact[N];
int _fact[N];

int C(int n, int k) {
    if (k > n)
        return 0;
    if (k < 0)
        return 0;
    return (((1ll * fact[n] * _fact[n - k]) % mod) * 1ll * _fact[k]) % mod;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = 0;
    int z = 0;
    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            int len = 0;
            while (i < n && s[i] == '1') {
                ++z;
                ++i;
                ++len;
            }
            // cout << len << ' ';
            if (len % 2 == 1)
                ++k;
            // if (len % 2 == 1)
            //     ans = ans * ((len + 1) / 2) % mod, ++k;
        }
    }
    // cout << '\n';
    z -= k;
    z /= 2;
    // cout << ans << ',' << n << ' ' << k << ' ' << z << ':';
    ans = ans * (C(n - z - k, z)) % mod;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = 1ll * fact[i - 1] * i % mod;
    for (int i = 0; i < N; ++i)
        _fact[i] = powm(fact[i], mod - 2);

    SOLVE
}