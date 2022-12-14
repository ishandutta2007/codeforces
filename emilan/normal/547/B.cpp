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
    vt<int> a(n);
    vt<pii> sa(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa[i] = {a[i], i};
    }
    sort(rall(sa));

    set<int> s;
    for (int i = -1; i <= n; i++) s.insert(s.end(), i);
    s.erase(sa[0].se);

    for (int len = 1, i = 0; len <= n; len++) {
        for (;;) {
            auto it = s.upper_bound(sa[i].se);

            if (*it - *prev(it, 1) - 1 < len) s.erase(sa[++i].se);
            else break;
        }

        cout << sa[i].fi << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}