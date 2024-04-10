#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int odd = 0, even = 0;
    ll sum = 0;
    for (int x : a) {
        if (x & 1) odd++;
        else even++;
        sum += x;
    }

    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 0) {
            sum += ll(even) * x;
            if (x & 1) {
                odd += even;
                even = 0;
            }
        } else {
            sum += ll(odd) * x;
            if (x & 1) {
                even += odd;
                odd = 0;
            }
        }

        cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}