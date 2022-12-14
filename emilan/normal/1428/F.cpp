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
    string s;
    cin >> n >> s;

    map<int, pii> a;
    if (s[0] == '1') a[-1] = {0, 0};
    a[0] = {s[0] == '1', 1};
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) a.rbegin()->se.se++;
        else a[i] = {s[i] == '1', 1};
    }
    if (a.rbegin()->se.fi == 1) a[n] = {0, 0};

    ll ans = 0;
    for (int i = 1; i <= n && sz(a) > 1; i++) {
        for (auto it = a.begin(); it != a.end(); it++) {
            if (it->se.fi == 1) {
                auto itp = it, itn = it;
                itp--, itn++;

                it->se.se--;
                itp->se.se++, itn->se.se++;
            }
        }

        for (auto it = a.begin(); it != a.end(); it++) {
            if (it->se.fi == 0) {
                ans += ll((it->se.se - i) * 2 - 1) * i;
            } else {
                ans += ll(it->se.se + 1) * i;
            }
        }
        ans -= ll(a.begin()->se.se - i - 1) * i;
        ans -= ll(a.rbegin()->se.se - i - 1) * i;

        for (auto it = a.begin(); it != a.end(); it++) {
            if (it->se == pii{1, 0}) {
                auto itp = it, itn = it;
                itp--, itn++;

                ans += ll(itp->se.se - i) * (itn->se.se - i) * i;
                itp->se.se += itn->se.se - i;
                a.erase(it);
                a.erase(itn);
                it = itp;
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}