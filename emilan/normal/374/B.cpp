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

    ll ans = 1;
    int len = 1;
    for (int i = 1; i < sz(s); i++) {
        if (s[i - 1] + s[i] - '0' * 2 == 9) len++;
        else {
            if (len & 1) ans *= len / 2 + 1;
            len = 1;
        }
    }
    if (len & 1) ans *= len / 2 + 1;

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