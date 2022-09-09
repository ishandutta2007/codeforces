#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int a, b, c, m;
        cin >> a >> b >> c >> m;
        int L = max(2 * max({a, b, c}) - a - b - c - 1, 0), R = a + b + c - 3;
        cout << (L <= m and m <= R ? "YES" : "NO") << "\n";
    }
    return 0;
}