#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
constexpr int maxn = 100000 + 1;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
LL g[maxn], f[maxn];
LL F[maxn], G[maxn];
LL S[maxn];
LL C(LL n, LL m) {
    return F[n] * G[m] % mod * G[n - m] % mod;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i <= n; i += 1) G[i] = power(F[i] = i ? F[i - 1] * i % mod : 1, mod - 2);
    for (int i = 0, a; i < n; i += 1) {
        cin >> a;
        mp[a] += 1;
    }
    for (int i = 0; i < n; i += 1) 
        g[i] = i ? (i * g[i - 1] % mod * (k - 1) + (LL)n * k) % mod * power(n - i, mod - 2) % mod : k;
    for (int i = n - 1; i >= 0; i -= 1)
        f[i] = (g[i] + f[i + 1]) % mod;
    map<int, int> count;
    count[0] = k;
    for (auto [x, y] : mp) if (x != -1) {
        count[y] += 1;
        count[0] -= 1;
    }
    int r = mp[-1];
    for (auto [x, y] : count) {
        //cout << x << " " << y << "\n";
        for (int i = 0; i <= r; i += 1) S[i] = (S[i] + y * f[x + i]) % mod;
    }
    LL ans = 0;
    for (int i = 0; i <= r; i += 1) {
        LL p = C(r, i) * power(k - 1, r - i) % mod * power(power(k, mod - 2), r) % mod;
        ans = (ans + p * S[i]) % mod;
    }
    cout << (ans + mod - f[0] * (k - 1) % mod) % mod * power(k, mod - 2) % mod;
    return 0;
}