#include <cstdio>
//#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 500000;
const int SIGMA = 22;
const int INF = 1000000000;

int dp[1 << SIGMA];
vector<pair<int, char> > g[1 + MAXN];
int depth[1 + MAXN], weight[1 + MAXN];
int mask[1 + MAXN], answer[1 + MAXN];

void Precompute(int node) {
    weight[node] = 1;
    for (auto &son : g[node]) {
        depth[son.first] = depth[node] + 1;
        mask[son.first] = mask[node] ^ (1 << son.second);
        Precompute(son.first);
        weight[node] += weight[son.first];
    }
}

vector<int> nodes;

void GetSubTree(int node) {
    nodes.clear();
    nodes.push_back(node);
    for (int i = 0; i < nodes.size(); i++) {
        node = nodes[i];
        for (auto &son: g[node])
            nodes.push_back(son.first);
    }
}

void Solve(int node, bool dump) {
    int best = 0;
    if (g[node].empty()) {
        if (!dump)
            dp[mask[node]] = max(dp[mask[node]], depth[node]);
        return;
    }
    for (auto &son : g[node])
        if (weight[son.first] > weight[best])
            best = son.first;
    for (auto &son : g[node])
        if (son.first != best) {
            Solve(son.first, true);
            answer[node] = max(answer[node], answer[son.first]);
        }
    Solve(best, false);
    answer[node] = max(answer[node], answer[best]);
    for (auto &son : g[node])
        if (son.first != best) {
            GetSubTree(son.first);
            for (auto &it : nodes) {
                answer[node] = max(answer[node], depth[it] + dp[mask[it]] - 2 * depth[node]);
                for (int i = 0; i < SIGMA; i++)
                    answer[node] = max(answer[node], depth[it] + dp[mask[it] ^ (1 << i)] - 2 * depth[node]);
            }
            for (auto &it : nodes)
                dp[mask[it]] = max(dp[mask[it]], depth[it]);
        }
    answer[node] = max(answer[node], depth[node] + dp[mask[node]] - 2 * depth[node]);
    for (int i = 0; i < SIGMA; i++)
        answer[node] = max(answer[node], depth[node] + dp[mask[node] ^ (1 << i)] - 2 * depth[node]);
    dp[mask[node]] = max(dp[mask[node]], depth[node]);
    if (dump) {
        GetSubTree(node);
        for (auto &it : nodes)
            dp[mask[it]] = -INF;
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    for (int i = 0; i < (1 << SIGMA); i++)
        dp[i] = -INF;
    scanf("%d", &n);
    for (int node = 2; node <= n; node++) {
        int dad;
        char letter;
        scanf("%d %c", &dad, &letter);
        g[dad].push_back(make_pair(node, letter - 'a'));
    }
    depth[1] = 1;
    Precompute(1);
    Solve(1, false);
    for (int i = 1; i <= n; i++)
        printf("%d ", answer[i]);
    return 0;
}