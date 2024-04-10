#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

vector< pair<int, int> > E[3005];
int dp[3005], many[3005], least[3005], height[3005];
int N;

void dfs(int x) {
    dp[x] = 0;
    //if (height[x] == 1)
    //    least[x] = 10005;
    least[x] = min(least[x], 2 * many[x] - height[x]);

    for (auto &it: E[x])
        if (dp[it.first] == -1) {
            many[it.first] = many[x] + it.second;
            least[it.first] = min(least[x], 2 * many[x] - height[x]);
            height[it.first] = height[x] + 1;
            dfs(it.first);
            dp[x] += dp[it.first] + it.second;
        }
}

int main() {
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int x, y; cin >> x >> y;
        E[x].push_back({y, 0});
        E[y].push_back({x, 1});
    }

    int answer = N - 1;
    if (N <= 2)
        answer = 0;
    for (int i = 1; i <= N; ++i) {
        memset(dp, -1, sizeof(dp));
        memset(many, 0, sizeof(many));
        memset(least, 0, sizeof(least));
        memset(height, 0, sizeof(height));
        dfs(i);

        for (int j = 1; j <= N; ++j) {
            if (i != j) {
                int toadd = height[j] - many[j] + least[j];
                answer = min(answer, dp[i] - (many[j] - many[i]) + toadd);
            }
            //if (i == 4)
            //    cerr << j << " -> " << dp[j] << " " << many[j] << " " << least[j] << " " << height[j] << "\n";
        }
    }

    cout << answer << "\n";
}