#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int kMaxN = 100 * 1000 + 5;
int A[kMaxN];

int64_t dp[kMaxN][4];

vector<int> E[kMaxN];

void dfs(int node, int father = -1) {
    for (auto &x : E[node])
        if (x != father)
            dfs(x, node);

    dp[node][0] = dp[node][1] = dp[node][2] = dp[node][3] = A[node];

    int64_t best0 = 0, best01 = 0, best1 = 0, best11 = 0, best2 = 0, best3 = 0;
    int where0 = -1, where1 = -2;
    for (auto &x : E[node])
        if (x != father) {
            dp[node][2] = max(dp[node][2], dp[x][2]);
            dp[node][2] = max(dp[node][2], dp[x][0] + best0);
            dp[node][2] = max(dp[node][2], dp[x][3] + best1 + A[node]);
            dp[node][2] = max(dp[node][2], dp[x][1] + best3 + A[node]);
            dp[node][2] = max(dp[node][2], dp[x][0] + best1 + best11 + A[node]);
            if (where0 == where1)
                dp[node][2] = max(dp[node][2], dp[x][1] + max(best0 + best11, best1 + best01) + A[node]);
            else
                dp[node][2] = max(dp[node][2], dp[x][1] + best0 + best1 + A[node]);
            best2 = max(best2, dp[x][2]);

            dp[node][3] = max(dp[node][3], dp[x][3] + A[node]);
            dp[node][3] = max(dp[node][3], dp[x][1] + A[node] + best0);
            dp[node][3] = max(dp[node][3], dp[x][0] + A[node] + best1);
            best3 = max(best3, dp[x][3]);

            dp[node][0] = max(dp[node][0], dp[x][0]);
            dp[node][0] = max(dp[node][0], dp[x][1] + best1 + A[node]);
            if (dp[x][0] > best0) {
                best01 = best0;
                best0 = dp[x][0];
                where0 = x;
            } else if (dp[x][0] > best01) {
                best01 = dp[x][0];
            }

            dp[node][1] = max(dp[node][1], dp[x][1] + A[node]);
            if (dp[x][1] > best1) {
                best11 = best1;
                best1 = dp[x][1];
                where1 = x;
            } else if (dp[x][1] > best11) {
                best11 = dp[x][1];
            }
        }
    dp[node][0] = max(dp[node][0], dp[node][1]);
    dp[node][2] = max(dp[node][2], dp[node][3]);
}

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 1; i < N; ++i) {
        int x, y; cin >> x >> y;
        E[x - 1].push_back(y - 1);
        E[y - 1].push_back(x - 1);
    }

    dfs(0);

    cout << dp[0][2] << "\n";
}