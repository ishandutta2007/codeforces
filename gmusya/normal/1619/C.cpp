#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll a, s;
        cin >> a >> s;
        bool can = true;
        vector<ll> b;
        while (a || s) {
            ll last_a = a % 10;
            ll last_s = s % 10;
            if (last_a <= last_s) {
                b.push_back(last_s - last_a);
                a /= 10;
                s /= 10;
                continue;
            }
            ll last_2s = s / 10 % 10;
            if (last_2s != 1) {
                can = false;
                break;
            }
            b.push_back(10 + last_s - last_a);
            a /= 10;
            s /= 100;
        }
        if (!can) {
            cout << -1 << '\n';
            continue;
        }
        while (!b.empty() && b.back() == 0) {
            b.pop_back();
        }
        if (b.empty()) {
            b.push_back(0);
        }
        reverse(b.begin(), b.end());
        for (ll x : b) {
            cout << x;
        }
        cout << '\n';
    }
    return 0;
}