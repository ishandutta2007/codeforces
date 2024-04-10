#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int d = __gcd(x, y);
    x /= d;
    y /= d;
    cout << min(a / x, b / y) << '\n';

    return 0;
}