#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;
#define int long long 

const int mod = 1e9 + 7;

int powm(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return powm(a, b - 1) * a % mod;
    int z = powm(a, b / 2);
    return z * z % mod;
}

map<array<int, 3>, int> res;

int f(int n, int m, int k) {
    if (m == 0)
        return 0;
    if (m == n)
        return k * n %mod;
    if (res.count({n, m, k}))
        return res[{n, m, k}];
    auto z1 = f(n - 1, m - 1, k);
    auto z2 = f(n - 1, m, k);
    return res[{n, m, k}] = ((z1 + (z2 - z1) * powm(2, mod - 2)) % mod + mod) % mod;
}

void solve() {
    res.clear();
    int n, m, k;
    cin >> n >> m >> k;
    cout << f(n, m, k) << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE;
}