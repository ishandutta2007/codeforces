#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int x;
        cin >> x;
        for (int i = 0; i < n; ++i) {
            a[i] -= x;
        }
        ll mx = -INF;
        vector<ll> sums(n + 1);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + a[i - 1];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (sums[i] - mx < 0) {
                ++res;
                mx = -INF;
                continue;
            } else {
                mx = max(sums[i - 1], mx);
            }
        }
        cout << n - res << '\n';
    }
    return 0;
}