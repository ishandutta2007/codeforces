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

void solve() {
    int n;
    cin >> n;
    map<pii, vt<int>> ma;
    for (int i = 0; i < n; i++) {
        int ra, rb;
        cin >> ra >> rb;
        ma[{ra, rb}].push_back(i + 1);
    }

    vt<pii> st{ma.rbegin()->fi};
    for (auto it = ++ma.rbegin(); it != ma.rend(); it++) {
        pii l = it->fi;
        if (l.fi == st.back().fi || l.se <= st.back().se) continue;

        auto check = [&]() {
            if (sz(st) < 2) return false;

            pii m = st.back(), r = st[sz(st) - 2];
            return l.fi * m.se * ll(l.se - r.se) * (r.fi - m.fi)
                    > l.se * m.fi * ll(m.se - r.se) * (r.fi - l.fi);
        };
        while (check()) st.pop_back();
        st.push_back(l);
    }

    vt<int> ans;
    for (pii &p : st) ans.insert(ans.end(), all(ma[p]));
    sort(all(ans));
    for (int x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}