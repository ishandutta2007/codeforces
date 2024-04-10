#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n), b(n + 1);
        for (int& ai : a) cin >> ai;
        b[0] = a[0];
        b.back() = a.back();
        for (int i = 1; i < n; i += 1)
            b[i] = lcm(a[i - 1], a[i]);
        int ok = 1;
        for (int i = 0; i < n; i += 1)
            if (gcd(b[i], b[i + 1]) != a[i])
                ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }
}