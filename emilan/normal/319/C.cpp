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
using pll = pair<ll, ll>;

double intersect_x(pll &a, pll &b) {
    return double(a.se - b.se) / (b.fi - a.fi);
}

void solve() {
    int n;
    cin >> n;
    vt<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    
    deque<pll> q{{b[0], b[0]}};
    for (int i = 1; i < n; i++) {
        while (sz(q) > 1 &&
                intersect_x(q[0], q[1]) <= a[i] - 1) {
            q.pop_front();
        }
        pll new_line = {
            b[i],
            b[i] + q[0].fi * ll(a[i] - 1) + q[0].se
        };
        while (sz(q) > 1 &&
                intersect_x(q[sz(q) - 2], q.back()) >=
                intersect_x(q[sz(q) - 2], new_line)) {
            q.pop_back();
        }
        q.push_back(new_line);
    }

    cout << q.back().se;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}