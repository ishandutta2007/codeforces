#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        if (n & 1)
            cout << power(power(2, n - 1) + 1, k) << "\n";
        else {
            LL res = 0, p = 1;
            LL x = power(2, n - 1) - 1;
            for (int i = 1; i <= k; i += 1) {
                res = (res + p * power(2, (LL)(k - i) * n)) % mod;
                p = p * x % mod;
            }
            cout << (res + p) % mod << "\n";
        }
    }
    return 0;
}