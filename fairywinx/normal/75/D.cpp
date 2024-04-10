#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<array<long long, 3>> a(n);
    vector<vector<long long>> who(n);
    vector<long long> z(n);
    const long long inf = 1e18;
    vector<long long> mx(n, -inf);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        who[i].resize(c);
        for (int j = 0; j < (int) who[i].size(); ++j) {
            cin >> who[i][j];
        }
        long long tmp = 0;
        // for (int j : who[i])
        //     cout << j << ' ';
        // cout << '\n';
        for (int j : who[i]) {
            tmp += j;
            if (tmp < 0)
                tmp = 0;
            z[i] = max(z[i], tmp);
            mx[i] = max(mx[i], 1ll * j);
            // cout << tmp << '\n';
            // ans = max(ans, tmp);
            a[i][0] += j;
        }
        long long now = 0;
        for (int j : who[i]) {
            now += j;
            a[i][1] = max(now, a[i][1]);
        }
        reverse(all(who[i]));
        now = 0;
        for (int j : who[i]) {
            now += j;
            a[i][2] = max(now, a[i][2]);
        }
    }
    long long tmpans = -inf;
    long long now = 0;
    for (int j = 0; j < m; ++j) {
        int ind;
        cin >> ind;
        --ind;
        tmpans = max(tmpans, mx[ind]);
        ans = max(ans, z[ind]);
        // cout << z[ind] << '\n';
        ans = max(ans, now + a[ind][1]);
        now = max(now + a[ind][0], a[ind][2]);
        // cout << now << '\n';
        // now += a[ind][0];
        now = max(now, 0ll);
    }
    if (tmpans < 0)
        cout << tmpans << '\n';
    else
        cout << ans << '\n';
}