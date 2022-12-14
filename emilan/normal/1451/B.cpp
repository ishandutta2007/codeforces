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
    int n, q;
    string s;
    cin >> n >> q >> s;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        bool ok = false;

        for (int i = l - 1; ~i && !ok; i--) {
            if (s[i] == s[l]) ok = true;
        }

        for (int i = r + 1; i < n && !ok; i++) {
            if (s[i] == s[r]) ok = true;
        }

        cout << (ok ? "yes\n" : "no\n");
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