#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;

int a[MAXN];
map <int, int> dp;
map <int, int> pos;
int pr[MAXN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        if (dp[a[i]] < dp[a[i] - 1] + 1) {
            dp[a[i]] = dp[a[i] - 1] + 1;
            pr[i] = pos[a[i] - 1];
            pos[a[i]] = i;
        }
    }

    int mx = 0;
    for (pair <int, int> elem : dp) mx = max(mx, elem.second);

    for (pair <int, int> elem : dp) {
        if (elem.second == mx) {
            vector <int> ans;
            int p = pos[elem.first];
            for (int i = 0; i < elem.second; ++i) {
                ans.push_back(p);
                p = pr[p];
            }
            reverse(ans.begin(), ans.end());
            cout << elem.second << '\n';
            for (int elem : ans) cout << elem + 1 << ' ';
            cout << '\n';
            return 0;
        }
    }

    return 0;
}