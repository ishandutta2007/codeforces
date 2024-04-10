#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

double getTime() {
    return 1.0 * clock() / CLOCKS_PER_SEC;
}

const int C = 2e7 + 228;

int cnt[C];
long long dp[C];
int used[C];

signed main() {
    #ifdef DEBUG
        // freopen("in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    // cout << "Meow\n";
    int n;
    cin >> n;
    int mx = 0;
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    sort(rall(b));
    vector<vector<int>> _d(n);
    for (int j = 0; j < n; ++j) {
        int a = b[j];
        mx = max(mx, a);
        for (int i = 1; i * i <= a; ++i) {
            if (a % i == 0) {
                cnt[i]++;
                _d[j].push_back(i);
                if (i * i != a) {
                    ++cnt[a / i];
                    _d[j].push_back(a / i);
                }
            }
        }
        sort(rall(_d[j]));
    }
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        // if (getTime() > 3.8) {
        //     cout << ans << '\n';
        //     return 0;
        // }
        if (used[b[i]])
            continue;
        auto d = _d[i];
        for (int j = 0; j < (int) d.size(); ++j) {
            int c1 = d[j];
            dp[c1] = 1ll * c1 * cnt[c1];
            used[c1] = 1;
            for (int k = 0; k < j; ++k) {
                int c2 = d[k];
                if (c2 % c1 == 0) {
                    dp[c1] = max(dp[c1], dp[c2] + 1ll * c1 * (cnt[c1] - cnt[c2]));
                }
            }
            ans = max(ans, dp[c1]);
        }
    }
    cout << ans << '\n';
}