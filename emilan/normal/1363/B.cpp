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
    vt<int> cnt1(n + 1);
    for (int i = 0; i < n; i++) {
        cnt1[i + 1] = cnt1[i] + (s[i] == '1');
    }

    int ans = n;
    for (int i = 0; i <= n; i++) {
        ans = min({
            ans,
            cnt1[n] - cnt1[i] + i - cnt1[i],
            (n - i) - (cnt1[n] - cnt1[i]) + cnt1[i]
        });
    }
    cout << ans << '\n';
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