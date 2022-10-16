#include <cstdio>
//#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
const int MAXW = 1000;

int weight[1 + MAXN], beauty[1 + MAXN];
int dp[2][1 + MAXW], groups;
int which[1 + MAXN];
vector<int> g[1 + MAXN], group[1 + MAXN];

void DFS(int node) {
    group[groups].push_back(node);
    which[node] = groups;
    for (auto &neighbour : g[node])
        if (!which[neighbour])
            DFS(neighbour);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, limit;
    scanf("%d%d%d", &n, &m, &limit);
    for (int i = 1; i <= n; i++)
        scanf("%d", &weight[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &beauty[i]);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!which[i]) {
            groups++;
            DFS(i);
        }
    int now = 0, before = 1;
    for (int i = 1; i <= groups; i++) {
        swap(now, before);
        int sumWeight = 0, sumBeauty = 0;
        for (auto &it : group[i]) {
            sumWeight += weight[it];
            sumBeauty += beauty[it];
            for (int j = limit - weight[it]; j >= 0; j--)
                if (dp[before][j] > 0 || j == 0)
                    dp[now][j + weight[it]] = max(dp[now][j + weight[it]], dp[before][j] + beauty[it]);
        }
        for (int j = limit - sumWeight; j >= 0; j--)
            if (dp[before][j] > 0 || j == 0)
                dp[now][j + sumWeight] = max(dp[now][j + sumWeight], dp[before][j] + sumBeauty);
        for (int j = 0; j <= limit; j++)
            dp[now][j] = max(dp[now][j], dp[before][j]);
    }
    int answer = 0;
    for (int i = 0; i <= limit; i++)
        answer = max(answer, dp[now][i]);
    printf("%d\n", answer);
    return 0;
}