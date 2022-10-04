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
    int n;
    cin >> n;
    ll ans = 0;
    for (int x = -n; x <= n; ++x) {
        if (abs(x) <= 1) continue;
        for (int i = 2; abs(i * x) <= n; ++i) {
            ans += abs(x);
        }
        for (int i = -2; abs(i * x) <= n; --i) {
            ans += abs(x);
        }
    }
    cout << ans << '\n';
}