#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, a[16][10050], dist[16][16], cross[16][16];
int dp[16][16][1 << 16];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    if (n == 1) {
        int ans = 2e9;
        for (int z = 0; z + 1 < m; ++z)
            ans = min(ans, abs(a[0][z] - a[0][z + 1]));
        cout << ans;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int mx = 2e9;
            for (int z = 0; z < m; ++z)
                mx = min(mx, abs(a[i][z] - a[j][z]));
            dist[i][j] = mx;
            mx = 2e9;
            for (int z = 0; z + 1 < m; ++z)
                mx = min(mx, abs(a[i][z] - a[j][z + 1]));
            cross[i][j] = mx;
        }
    }
    priority_queue<pii> q;
    for (int i = 0; i < n; ++i)
        q.push({(int)2e9, (i << 20) | (i << 16) | (1 << i)});
    while (q.size()) {
        int curd = q.top().first;
        int first = q.top().second >> 20;
        int last = (q.top().second >> 16) & 15;
        int mask = q.top().second & 0xFFFF;
        q.pop();
        if (dp[first][last][mask] >= curd)
            continue;
        dp[first][last][mask] = curd;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1)
                continue;
            int nxtmask = mask | (1 << i);
            int nxtd = min(curd, dist[last][i]);
            if (nxtmask + 1 == (1 << n))
                nxtd = min(nxtd, cross[i][first]);
            if (nxtd > dp[first][i][nxtmask]) {
                dp[first][i][nxtmask] = nxtd - 1;
                q.push({nxtd, (first << 20) ^ (i << 16) ^ nxtmask});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j)
                ans = max(ans, dp[i][j][(1 << n) - 1]);
    cout << ans;
}