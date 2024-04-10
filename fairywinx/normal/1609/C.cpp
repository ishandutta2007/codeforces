#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 1e6 + 228;
int p[N];

void solve() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> pr(e, vector<int> (1, 0));
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (c == 1)
            pr[i % e].push_back(pr[i % e].back());
        else if (!p[c]) {
            pr[i % e].push_back(pr[i % e].back() + 1);
        } else {
            pr[i % e].push_back(pr[i % e].back() + 2);
        }
    }
    long long ans = 0;
    for (int i = 0; i < e; ++i) {
        for (int j = 0; j < (int) pr[i].size(); ++j) {
            int ind = lower_bound(all(pr[i]), pr[i][j] + 2) - pr[i].begin();
            int ind1 = lower_bound(all(pr[i]), pr[i][j] + 1) - pr[i].begin();
            --ind;
            --ind1;
            ind1 = max(ind1, j + 1);
            if (pr[i][ind] - pr[i][j] == 1) {
                ans += max(0, ind - ind1);
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    for (int i = 2; i < N; ++i) {
        if (!p[i]) {
            for (int j = 2 * i; j < N; j += i)
                p[j] = 1;
        }
    }

    SOLVE
    // solve();
}