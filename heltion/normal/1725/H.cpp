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
    int n, m = 0;
    cin >> n;
    vector<int> a(n);
    for (int& ai : a) {
        cin >> ai;
        m += ai % 3 == 0;
    }
    if (m <= n / 2) {
        cout << "0\n";
        for (int i = 0, j = n / 2; i < n; i += 1) {
            if (a[i] % 3 == 0) cout << 0;
            else if (j) cout << 1, j --;
            else cout << 0;
        }
    }
    else {
        cout << "2\n";
        for (int i = 0, j = n / 2; i < n; i += 1) {
            if (a[i] % 3 != 0) cout << 0;
            else if (j) cout << 1, j --;
            else cout << 0;
        }
    }
}