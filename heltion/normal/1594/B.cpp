#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr  LL mod = 1'000'000'007;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, k, ans = 0;
        cin >> n >> k;
        for(LL p = 1; k; k >>= 1, p = p * n % mod)
            if (k & 1) ans = (ans + p) % mod;
        cout << ans << "\n";
    }
    return 0;
}