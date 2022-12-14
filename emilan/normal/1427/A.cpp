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
    for (int &x : a) cin >> x;

    if (accumulate(all(a), 0)) {
        int pos = 0, neg = 0;
        for (int x : a) {
            if (x > 0) pos += x;
            else neg -= x;
        }

        if (pos > neg) sort(rall(a));
        else sort(all(a));

        cout << "YES\n";
        for (int x : a) cout << x << ' ';
        cout << '\n';
    } else cout << "NO\n";
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