#include <cstdio>
//#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200000;
const long long INFLL = (1LL << 62);

vector<int> g[1 + MAXN];
int cost[1 + MAXN];
long long sum[1 + MAXN], dp[1 + MAXN][2];

void DFS(int node, int father) {
    long long first = -INFLL, second = -INFLL;
    sum[node] = cost[node];
    dp[node][0] = dp[node][1] = -INFLL;
    for (auto &son : g[node])
        if (son != father) {
            DFS(son, node);
            sum[node] += sum[son];
            dp[node][0] = max(dp[node][0], dp[son][0]);
            dp[node][1] = max(dp[node][1], dp[son][1]);
            if (dp[son][0] > first) {
                second = first;
                first = dp[son][0];
            }
            else
                if (dp[son][0] > second)
                    second = dp[son][0];
        }
    dp[node][0] = max(dp[node][0], sum[node]);
    if (first != -INFLL && second != -INFLL)
        dp[node][1] = max(dp[node][1], first + second);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &cost[i]);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    if (dp[1][1] == -INFLL) {
        printf("Impossible\n");
        return 0;
    }
    printf("%I64d\n", dp[1][1]);
    return 0;
}