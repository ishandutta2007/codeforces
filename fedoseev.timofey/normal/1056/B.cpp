#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if ((i * i + j * j) % m == 0) {
                int c1 = (n / m) + ((n % m) >= i);
                int c2 = (n / m) + ((n % m) >= j);
                ans += (ll)c1 * c2;
            }
        }
    }
    cout << ans << '\n';
}