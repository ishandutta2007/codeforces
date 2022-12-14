#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

#define win return void(cout << "sjfnb")
#define lose return void(cout << "cslnb")

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    map<int, int> m;
    for (int x : a) m[x]++;
    
    if (sz(m) < n - 1) lose;
    else if (sz(m) == n - 1) {
        for (pii p : m) {
            if (p.se == 2) {
                if (p.fi == 0
                        || m.count(p.fi - 1)) lose;
            }
        }
    }

    ll mv = accumulate(all(a), 0ll);
    mv -= n * ll(n - 1) / 2;

    if (mv & 1) win;
    else lose;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}