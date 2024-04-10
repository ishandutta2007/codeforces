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
    set<int> a;
    while (n--) {
        int x;
        cin >> x;
        a.insert(x);
    }

    vt<int> b(all(a));
    if (sz(a) > 3) cout << -1;
    else if (sz(a) == 3) {
        if (b[2] - b[1] != b[1] - b[0]) cout << -1;
        else cout << b[1] - b[0];
    } else if (sz(a) == 2) {
        if ((b[0] ^ b[1]) & 1) cout << b[1] - b[0];
        else cout << (b[1] - b[0]) / 2;
    }
    else cout << 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}