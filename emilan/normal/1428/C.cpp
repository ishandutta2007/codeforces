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
    string s;
    cin >> s;

    int n = sz(s);
    int ans = n, b = 0;
    for (int i = n - 1; ~i; i--) {
        if (s[i] == 'B') b++;
        else if (b) b--, ans -= 2;
    }

    cout << ans - b / 2 * 2 << '\n';
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