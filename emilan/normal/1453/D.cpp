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
    ll k;
    cin >> k;
    if (k & 1) return void(cout << "-1\n");

    vt<int> ans{1};
    for (int i = 58; ~i; i--) {
        while (k >= (4ll << i) - 2) {
            ans.insert(ans.end(), i, 0);
            ans.push_back(1);
            k -= (4ll << i) - 2;
        }
    }
    ans.pop_back();

    if (sz(ans) > 2000) cout << "-1\n";
    else {
        cout << sz(ans) << '\n';
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}