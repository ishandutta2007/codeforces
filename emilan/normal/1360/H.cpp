#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    set<string> strings;
    int rm = 0;
    while (n--) {
        string s;
        cin >> s;

        strings.insert(s);
        if (s[0] == '0') rm--;
        else rm++;
    }

    ll cur = 1ll << m - 1;
    if (rm < 0) {
        for (int cnt = (-rm + 1) / 2; cnt; cur++) {
            string s(m, '\0');
            for (int i = 0; i < m; i++) {
                s[i] = '0' + (cur >> m - i - 1 & 1);
            }

            if (!strings.count(s) && !--cnt) cout << s << '\n';
        }
    } else {
        cur--;
        for (int cnt = rm / 2 + 1; cnt; cur--) {
            string s(m, '\0');
            for (int i = 0; i < m; i++) {
                s[i] = '0' + (cur >> m - i - 1 & 1);
            }

            if (!strings.count(s) && !--cnt) cout << s << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve(tc);
    }
}