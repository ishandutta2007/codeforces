#include <bits/stdc++.h>
using namespace std;
using LL = long long;
bool check(LL m, LL a, LL b) {
    if (m < 0) return false;
    if (a + b * 2 < m) return false;
    if (a) return true;
    if (m % 2) return false;
    return true;
};
bool check(LL m, LL a, LL b, LL c) {
    LL d = min(c, m / 3);
    for (int i = 0; i < 6 and i <= d; i += 1)
        if (check(m - 3 * (d - i), a, b)) return true;
    return false;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        LL a, b, c;
        cin >> a >> b >> c;
        LL m = (a + b * 2 + c * 3) / 2;
        while (not check(m, a, b, c))
            m -= 1;
        cout << abs(a + b * 2 + c * 3 - 2 * m) << "\n";
    }
    return 0;
}