#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        if (n & 1) cout << "0\n";
        else {
            LL ans = 1;
            for (int i = 1; i <= n / 2; i += 1)
                ans = ans * i % mod;
            cout << ans * ans % mod << "\n";
        }
    }
    return 0;
}