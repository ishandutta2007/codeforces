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
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            while (v[i] % 2 == 0) {
                v[i] /= 2;
                ++cnt;
            }
        }
        sort(all(v));
        v.back() <<= (ll)cnt;
        ll ans = accumulate(all(v), 0LL);
        cout << ans << endl;
    }
}