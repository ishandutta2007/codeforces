#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n,m,k,x,y,z,a[55],d[55][55];
ll ans,dp[21][300005];
vector< pii > v;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
    while (k--) {
        scanf("%d%d%d",&x,&y,&z);
        x--; y--;
        d[x][y] = z;
    }

    for (int i = (1 << n) - 1; i >= 0; --i) {
        int qqq = i, cnt = 0;
        while (qqq) cnt += qqq & 1, qqq >>= 1;
        if (cnt <= m) v.push_back(make_pair(cnt, i));
    }

    sort(v.begin(), v.end());

    int i = 0;
    for (; i < v.size() && v[i].first < m; ++i) {
        if (v[i].second == 0) {
            for (int j = 0; j < n; ++j)
                dp[j][1 << j] = a[j];
            continue;
        }
        for (int j = 0; j < n; ++j) {
            int mask = v[i].second;
            if (!((mask >> j) & 1)) continue;
            for (z = 0; z < n; ++z) {
                if ((mask >> z) & 1) continue;
                ll newp = dp[j][mask] + (ll)d[j][z] + (ll)a[z];
                int newmask = mask | (1 << z);
                dp[z][newmask] = max(dp[z][newmask], newp);
            }
        }
    }

    for (; i < v.size(); ++i) {
        for (int j = 0; j < n; ++j) ans = max(ans, dp[j][v[i].second]);
    }
    cout << ans;

    return 0;
}