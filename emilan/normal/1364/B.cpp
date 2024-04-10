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
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    vt<int> ans{0};
    for (int i = 1; i < n - 1; i++) {
        if ((a[i] - a[i - 1] ^ a[i + 1] - a[i]) >> 31) {
            ans.push_back(i);
        }
    }
    ans.push_back(n - 1);

    cout << sz(ans) << '\n';
    for (int i : ans) cout << a[i] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case #" << tc << ": ";
        solve(tc);
    }
}