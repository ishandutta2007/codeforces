#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
const int INF = 1e9;

vector<int> g[1 + MAXN], gt[1 + MAXN];
int dp[1 + MAXN], cnt[1 + MAXN], deg[1 + MAXN];
bool seen[1 + MAXN];

int main() {
    // ifstream cin("input.in");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = INF;
    }
    dp[n] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, n});
    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();
        if (seen[node]) {
            continue;
        }
        seen[node] = true;
        for (auto it : gt[node]) {
            cnt[it]++;
            if (cost + (deg[it] - cnt[it]) < dp[it]) {
                dp[it] = cost + 1 + (deg[it] - cnt[it]);
                pq.push({dp[it], it});
            }
        }
    }
    cout << dp[1] << "\n";
    return 0;
}