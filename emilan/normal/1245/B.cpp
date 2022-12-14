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
    int n, a, b, c;
    string s;
    cin >> n >> a >> b >> c >> s;

    string ans(n, '\0');

    for (int i = 0; i < n && a; i++) {
        if (s[i] == 'S') {
            ans[i] = 'R';
            a--;
        }
    }
    for (int i = 0; i < n && b; i++) {
        if (s[i] == 'R') {
            ans[i] = 'P';
            b--;
        }
    }
    for (int i = 0; i < n && c; i++) {
        if (s[i] == 'P') {
            ans[i] = 'S';
            c--;
        }
    }

    if (count(all(ans), '\0') > n / 2) cout << "NO\n";
    else {
        for (int i = 0; i < n; i++) {
            if (ans[i] == '\0') {
                if (a) ans[i] = 'R', a--;
                else if (b) ans[i] = 'P', b--;
                else if (c) ans[i] = 'S', c--;
            }
        }
        cout << "YES\n";
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}