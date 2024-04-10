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
using pil = pair<int, ll>;

const ll inf = 1ll << 60;

void solve() {
    int n;
    cin >> n;
    map<int, pil> rings;
    while (n--) {
        int a, b, h;
        cin >> a >> b >> h;

        if (!rings.count(b)) {
            rings[b] = {a, h};
        } else {
            pil p = rings[b];
            rings[b] = {min(a, p.fi), p.se + h};
        }
    }

    vt<pil> v;
    for (auto p : rings) {
        int a = p.se.fi, b = p.fi;
        ll h = p.se.se, ph = 0;
        if (!v.empty() && a < v.back().fi) {
            ph = upper_bound(all(v), pil{a, inf})->se;
        }
        ll nh = ph + h;

        while (!v.empty() && v.back().se <= nh) v.pop_back();
        v.emplace_back(b, nh);
    }

    cout << v[0].se;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}