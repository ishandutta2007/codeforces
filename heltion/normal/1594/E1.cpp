#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr  LL mod = 1'000'000'007;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    cout << 6 * power(4, (1LL << n) - 2) % mod;
    return 0;
}