#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        ll x;
        cin >> x;
        for (int i = 0; i < n; ++i) {
            v[i] -= x;
        }
        int ans = 0;
        ll sum = 0;
        int len = 0;
        ll minpref = 1e18;
        for (int i = 0; i < n; ++i) {
            if (minpref + v[i] >= 0) {
                ++ans;
                sum += v[i];
                ++len;
                minpref = min(minpref + v[i], v[i]);
            } else {
                sum = 0;
                len = 0;
                minpref = 1e18;
            }
        }
        cout << ans << '\n';
    }
}