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
    int y, b, r;
    cin >> y >> b >> r;
    int ans = 0;
    for (int i = 0; i < 200; ++i) {
        if (y >= i && b >= i + 1 && r >= i + 2) {
            ans = max(ans, i + i + 1 + i + 2);
        }
    }
    cout << ans << '\n';
}