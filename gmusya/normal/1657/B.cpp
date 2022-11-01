#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll b, x, y;
        cin >> n >> b >> x >> y;
        vector<ll> a(n + 1);
        for (int i = 0; i + 1 <= n; ++i) {
            if (a[i] + x <=  b) {
                a[i + 1] = a[i] + x;
            } else {
                a[i + 1] = a[i] - y;
            }
        }
        ll ans = 0;
        for (auto& now : a) {
            ans += now;
        }
        cout << ans << '\n';
    }
    return 0;
}