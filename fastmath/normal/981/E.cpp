#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 7;

vector <pair <int, int> > a[MAXN];
int dp[MAXN];
bool ch[MAXN];

signed main()
{
    //freopen("1.txt", "r", stdin);
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l; --r;
        a[l].push_back({r, x});
    }

    for (int i = 0; i < MAXN; ++i) dp[i] = -1;

    dp[0] = n - 1;
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < a[l].size(); ++i) {
            for (int sum = n; sum >= a[l][i].second; --sum) {
                dp[sum] = max(dp[sum], min(dp[sum - a[l][i].second], a[l][i].first));
            }
        }

        for (int sum = 1; sum <= n; ++sum) {
            ch[sum] |= (l <= dp[sum]);
        }
    }


    vector <int> ans;
    for (int i = 1; i <= n; ++i) if (ch[i]) ans.push_back(i);

    cout << ans.size() << '\n';
    for (int elem : ans) cout << elem << ' ';
    cout << '\n';

    return 0;
}