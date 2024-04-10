#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll L = 1, R = 1e9;
        while (L != R) {
            ll M = (L + R + 1) / 2;
            vector<ll> b = a;
            for (int i = n - 1; i >= 2; --i) {
                if (b[i] < M) {
                    break;
                }
                ll d = min((b[i] - M) / 3, a[i] / 3);
                b[i - 1] += d;
                b[i - 2] += 2 * d;
            }
            bool can = true;
            for (int i = 0; i < n; ++i) {
                if (b[i] < M) {
                    can = false;
                }
            }
            if (can) {
                L = M;
            } else {
                R = M - 1;
            }
        }
        cout << L << "\n";
    }
    return 0;
}