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
        int n, ans = 0;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& ai : a) cin >> ai;
        for (int& bi : b) cin >> bi;
        for (int i = 0; i < n; i += 1)
            ans += a[i] != b[i];
        cout << min(ans, 1 + (int)abs(ranges::count(a, 1) - ranges::count(b, 1))) << "\n";
    }
}