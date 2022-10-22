#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
typedef long long ll;
typedef long double ld;
using namespace std;

const ld episode = 10.;
const int maxp = 11;
bool cmp(pair<ld, int>& a, pair<ld, int>& b)
{
    return a.first > b.first;
}
void upd(ld& a, const ld& b)
{
    a = min(a, b);
}
int n;
ld t, c;
ld how_long(ld train, ld solve)
{
    return train + (solve / (train * c + 1.));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> c >> t;
        vector<ld> coef(n + 1, 1.);
        for (int i = 0; i < n; i++) coef[i + 1] = coef[i] * 0.9;
        vector<pair<ld, int> > p(n);
        for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
        sort(p.begin(), p.end(), cmp);
        vector<vector<ld> > dp(n + 2, vector<ld>(n * maxp + 1, 1e18));
        dp[0][0] = 0.;
        for (int i = 0; i < n; i++)
        {
            for (int watched = i; watched >= 0; watched--)
            {
                for (int points = maxp * i; points >= 0; points--)
                {
                    upd(dp[watched + 1][points + p[i].second], dp[watched][points] + p[i].first / coef[watched + 1]);
                }
            }
        }
        int ans = 0;
        for (int watched = 1; watched <= n + 1; watched++)
        {
            for (int points = 0; points <= maxp * n; points++)
            {
                if (dp[watched][points] > 1e17) continue;
                ld nwt = t - (ld)(episode * watched);
                if (nwt < 0) continue;
                ld lo = 0., hi = nwt;
                for (int iter = 0; iter < 100; iter++)
                {
                    ld mid1 = (2. * lo + hi) / 3., mid2 = (lo + 2. * hi) / 3.;
                    if (how_long(mid1, dp[watched][points]) < how_long(mid2, dp[watched][points])) hi = mid2;
                    else lo = mid1;
                }
                if (how_long(lo, dp[watched][points]) <= nwt)
                    ans = max(ans, points);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}