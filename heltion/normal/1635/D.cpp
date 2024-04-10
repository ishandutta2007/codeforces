#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, p;
    cin >> n >> p;
    vector<LL> a(n);
    for (LL &ai : a) cin >> ai;
    ranges::sort(a);
    set<LL> s;
    for (LL ai : a) {
        if (p <= 30 and ai >= (1LL << p)) break;
        int ok = 1;
        for (LL x = ai; x and (x % 2 == 1 or x % 4 == 0); ) {
            if (x % 2 == 1) x /= 2; else x /= 4;
            if (s.contains(x)) ok = 0;
        }
        if (ok) s.insert(ai);
    }
    LL ans = 0;
    vector<LL> f(p + 1), g(p + 1);
    f[0] = f[1] = 1;
    for (int i = 2; i <= p; i += 1) f[i] = (f[i - 1] + f[i - 2]) % mod;
    for (int i = 0; i <= p; i += 1) g[i] = i ? (g[i - 1] + f[i]) % mod : 1;
    for (LL a : s) {
        int x = 0;
        for (; a; a /= 2) x += 1;
        ans = (ans + g[p - x]) % mod;
    }
    cout << ans << "\n";
}