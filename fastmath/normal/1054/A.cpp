#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;

    int ans1 = t2 * abs(x - y) + t2 * abs(x - z) + t3 * 3;
    int ans2 = t1 * abs(x - y);

    if (ans1 <= ans2) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}