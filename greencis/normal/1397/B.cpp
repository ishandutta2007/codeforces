#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int a[100100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i] - 1;
    }
    if (n <= 60) {
        sort(a, a + n);
        ld tmp;
        for (int c = 2; (tmp = pow((ld)c, n - 1) + 1e-9) <= 1e18 && abs((ll)tmp - a[n - 1]) < ans; ++c) {
            ll deg = 1;
            ld degl = 1;
            ll cur = 0;
            for (int i = 0; cur < ans && i < n && degl <= 1e18; ++i) {
                cur += abs(deg - a[i]);
                deg *= c;
                degl *= c;
            }
            ans = min(ans, cur);
        }
    }
    cout << ans;
}