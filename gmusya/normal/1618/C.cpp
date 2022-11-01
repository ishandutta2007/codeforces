#include <algorithm>
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
        ll g1 = 0;
        for (int i = 0; i < n; i += 2) {
            g1 = __gcd(a[i], g1);
        }
        bool flag = true;
        for (int i = 1; i < n; i += 2) {
            if (a[i] % g1 == 0) {
                flag = false;
            }
        }
        if (flag) {
            cout << g1 << '\n';
            continue;
        }
        ll g2 = 0;
        for (int i = 1; i < n; i += 2) {
            g2 = __gcd(a[i], g2);
        }
        flag = true;
        for (int i = 0; i < n; i += 2) {
            if (a[i] % g2 == 0) {
                flag = false;
            }
        }
        if (flag) {
            cout << g2 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}