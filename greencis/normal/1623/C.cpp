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
        auto check = [&](int x) {
            vector<ll> addon(n);
            for (int i = n - 1; i >= 0; --i) {
                if (v[i] + addon[i] < x)
                    return false;
                if (i >= 2) {
                    ll nxt = min(v[i], v[i] + addon[i] - x) / 3;
                    addon[i - 1] += nxt;
                    addon[i - 2] += 2 * nxt;
                }
            }
            return true;
        };

        int L = 0, R = 1e9;
        while (L < R) {
            int mid = (L + R + 1) >> 1;
            if (check(mid))
                L = mid;
            else
                R = mid - 1;
        }
        cout << L << '\n';
    }
}