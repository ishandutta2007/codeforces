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
    int n, m;
    cin >> n >> m;
    vt<int> a(n);
    for (int &x : a) cin >> x;
    vt<pii> b(m);
    for (pii &p : b) cin >> p.fi >> p.se;

    vt<set<int>> req(n);
    for (int i = 0; i < m; i++) {
        req[--b[i].fi].insert(i);
        req[--b[i].se].insert(i);
    }

    vt<int> ok;
    for (int i = 0; i < n; i++) {
        if (sz(req[i]) <= a[i]) {
            ok.push_back(i);
        }
    }

    vt<int> ans;
    while (sz(ans) != m) {
        if (ok.empty()) return void(cout << "DEAD");

        int cur = ok.back();
        ok.pop_back();

        vt<int> rm(all(req[cur]));
        for (int x : rm) {
            ans.push_back(x + 1);

            req[b[x].fi].erase(x);
            if (sz(req[b[x].fi]) == a[b[x].fi]) {
                ok.push_back(b[x].fi);
            }

            req[b[x].se].erase(x);
            if (sz(req[b[x].se]) == a[b[x].se]) {
                ok.push_back(b[x].se);
            }
        }
    }

    cout << "ALIVE\n";
    reverse(all(ans));
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