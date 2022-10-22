#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll inf = 1e18, target = 2;
vector<vector<ll> > c(81, vector<ll>(81));
int n, k;
inline void upd(ll& a, const ll& b)
{
    a = min(a, b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<vector<int> > pp((k / 2), vector<int>(n, 0));
    for (int j = 1; j <= k / 2; j++)
    {
        for (int i = max(1, n - j); i < n; i++) pp[j - 1][i] = 1;
    }
    int odd_cnt = (k / 2) + 1;
    vector<vector<vector<pair<ll, int>>>>best(n, vector<vector<pair<ll, int>>>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int vr = 0; vr < n; vr++)
            {
                best[i][j].push_back({ c[i][vr] + c[vr][j], vr });
            }
            sort(best[i][j].begin(), best[i][j].end());
        }
    }
    vector<vector<ll> > dp(k + 1, vector<ll>(n + 1, inf)), dist(n, vector<ll>(n, inf));
    ll ans = inf;
    for (vector<int>& p : pp)
    {
        do
        {
            if (!p[0]) continue;
            vector<int> odd;
            for (int i = 0; i < n; i++) if (p[i]) odd.push_back(i);
            for (int i = 0; i < k + 1; i++) for (int j : odd) dp[i][j] = inf;
            for (int i : odd) for (int j : odd) dist[i][j] = inf;
            for (int i : odd)
            {
                for (int j : odd)
                {
                    int pick = 0;
                    while (p[best[i][j][pick].second]) pick++;
                    dist[i][j] = best[i][j][pick].first;
                }
            }
            dp[0][0] = 0;
            for (int i = 0; i < odd_cnt - 1; i++)
            {
                for (int last : odd)
                {
                    for (int nw : odd)
                    {
                        upd(dp[i + 1][nw], dp[i][last] + dist[last][nw]);
                    }
                }
            }
            ans = min(ans, dp[odd_cnt - 1][0]);
        } while (next_permutation(p.begin(), p.end()));
    }
    cout << ans << "\n";
    return 0;
}