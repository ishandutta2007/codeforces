#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
ll dp[5005][5], p[5005][5];
ll a[5005], sum[5005];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = sum[i];
        p[i][1] = 0;
    }
    for (int z = 2; z <= 4; ++z) {
        for (int i = 1; i <= n; ++i) {
            dp[i][z] = z % 2 == 0 ? 9e18 : -9e18;
            for (int j = 0; j <= i; ++j) {
                ll cur = sum[i] - sum[j] - dp[j][z - 1];
                if (z % 2 == 0 && cur < dp[i][z] || z % 2 != 0 && cur > dp[i][z]) {
                    dp[i][z] = cur;
                    p[i][z] = j;
                }
            }
        }
    }

    int cur = n, curz = 4;
    vector<int> ans;
    while (curz > 1) {
        ans.push_back(p[cur][curz]);
        cur = p[cur][curz--];
    }
    cout << ans[2] << " " << ans[1] << " " << ans[0] << endl;

    return 0;
}