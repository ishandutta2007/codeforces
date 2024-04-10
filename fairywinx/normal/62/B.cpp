#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<string> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    array<vector<int>, 26> a;
    for (int j = 0; j < (int) s.size(); ++j) {
        a[s[j] - 'a'].push_back(j);
    }


    for (int i = 0; i < n; ++i) {
        long long ans = 0;
        for (int j = 0; j < (int) b[i].size(); ++j) {
            int d = (int) 1e6 + 228;
            int c = (b[i][j] - 'a');
            auto it = lower_bound(all(a[c]), j);
            if (it != a[c].end()) {
                d = min(d, abs(*it - j));
            }
            if (it != a[c].begin()) {
                --it;
                d = min(d, abs(*it - j));
            }
            if (d == (int) 1e6 + 228)
                d = b[i].size();
            ans += d;
        }
        cout << ans << '\n';
    }
}