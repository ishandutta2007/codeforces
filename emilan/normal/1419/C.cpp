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
    int n, x;
    cin >> n >> x;
    vt<int> a(n);
    for (int &y : a) cin >> y;

    int eq_cnt = count(all(a), x);
    if (eq_cnt == n) cout << "0\n";
    else if (eq_cnt) cout << "1\n";
    else {
        if (accumulate(all(a), 0) == x * n) cout << "1\n";
        else cout << "2\n";
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