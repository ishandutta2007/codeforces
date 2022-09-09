#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr  LL mod = 1'000'000'007;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string c, s;
        cin >> n >> c >> s;
        int p = n - 1;
        while (p >= 0 and s[p] != c[0]) p -= 1;
        if (count(s.begin(), s.end(), c[0]) == n) cout << "0\n";
        else if ((p + 1) * 2 > n) cout << "1\n" << p + 1 << "\n";
        else cout << "2\n" << n - 1 << " " << n << "\n";
    }
    return 0;
}