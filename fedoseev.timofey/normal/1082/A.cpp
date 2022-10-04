#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, x, y, d;
        cin >> n >> x >> y >> d;
        int k = abs(x - y);
        if (!(k % d)) {
            cout << k / d << '\n';
            continue;
        }
        int nd1 = 2e9 + 228, nd2 = 2e9 + 228;
        if (!((n - y) % d)) {
            nd1 = (n - x + d - 1) / d + (n - y) / d;
        }
        if (!((y - 1) % d)) {
            nd2 = (x - 1 + d - 1) / d + (y - 1) / d;
        }
        if (min(nd1, nd2) < (int)2e9) {
            cout << min(nd1, nd2) << '\n';
        }
        else {
            cout << "-1\n";
        }
    }
}