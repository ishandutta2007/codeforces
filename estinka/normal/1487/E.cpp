#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <chrono>
#include <random>
#include <map>
#include <bitset>
#include <array>
typedef long long ll;
using namespace std;

const int inf = 1e9 + 79;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<int, 4>n;
    for (int i = 0; i < 4; i++) cin >> n[i];
    vector<vector<int> > pr(4), dp(4);
    vector<vector<pair<int, int> > > best(4);
    vector<vector<set<int> > > bad(4);
    for (int i = 0; i < 4; i++)
    {
        pr[i].resize(n[i]);
        dp[i].resize(n[i], inf);
        bad[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) cin >> pr[i][j];
    }
    for (int i = 0; i < 3; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int x, y;
            cin >> x >> y;
            x--; y--;
            bad[i + 1][y].insert(x);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n[i]; j++)
        {
            if (!i) dp[i][j] = pr[i][j];
            else
            {
                for (int k = 0; k < best[i - 1].size(); k++)
                {
                    if (bad[i][j].count(best[i - 1][k].second)) continue;
                    dp[i][j] = pr[i][j] + best[i - 1][k].first;
                    break;
                }
            }
            best[i].push_back({ dp[i][j], j });
        }
        sort(best[i].begin(), best[i].end());
    }
    int ans = *min_element(dp[3].begin(), dp[3].end());
    if (ans >= inf) cout << "-1\n";
    else cout << *min_element(dp[3].begin(), dp[3].end()) << "\n";
    return 0;
}