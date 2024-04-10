//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 200000;
const int MAXK = 5;

vector<int> g[1 + MAXN];
int dp[1 + MAXN][1 + MAXK], k;
long long sum[1 + MAXN][1 + MAXK];
long long answer = 0;

void DFS(int node, int father) {
    for (auto &son : g[node])
        if (son != father) {
            DFS(son, node);
            dp[son][0] = dp[son][k];
            sum[son][0] = sum[son][k];
            for (int i = k - 1; i >= 1; i--) {
                dp[son][i + 1] = dp[son][i];
                sum[son][i + 1] = sum[son][i];
            }
            dp[son][1] = dp[son][0] + 1;
            sum[son][1] = sum[son][0] + dp[son][0] + 1;
            for (int i = 1; i <= k; i++)
                answer += sum[son][i];
            for (int i = 1; i <= k; i++)
                for (int j = 1; j <= k; j++)
                    if (i + j <= k)
                        answer += sum[node][i] * dp[son][j] + sum[son][j] * dp[node][i] - 1LL * dp[node][i] * dp[son][j];
                    else
                        answer += sum[node][i] * dp[son][j] + sum[son][j] * dp[node][i];
            for (int i = 1; i <= k; i++) {
                dp[node][i] += dp[son][i];
                sum[node][i] += sum[son][i];
            }
        }
}

int main() {
    int n;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    cout << answer << "\n";
    return 0;
}