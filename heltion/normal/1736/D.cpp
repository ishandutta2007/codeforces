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
        string s;
        cin >> n >> s;
        int one = ranges::count(s, '1'), zero = n - one;
        if (one % 2) {
            cout << "-1\n";
            continue;
        }
        vector<int> b;
        for (int i = 0, j = 0; i < 2 * n; i += 2)
            if (s[i] != s[i + 1]) {
                if (s[i] - '0' == j) b.push_back(i);
                else b.push_back(i + 1);
                j ^= 1;
            }
        cout << b.size() << " ";
        for (int bi : b) cout << bi + 1 << " ";
        cout << "\n";
        for (int i = 1; i <= 2 * n; i += 2)
            cout << i << " ";
        cout << "\n";
    }
}