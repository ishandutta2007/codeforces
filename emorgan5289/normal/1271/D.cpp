#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m, k; fin >> n >> m >> k;
    vector<int> a(n), b(n), c(n), p(n);
    iota(all(p), 0);
    for (int i = 0; i < n; i++) fin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < m; i++) {
        int u, v; fin >> u >> v;
        p[v-1] = max(p[v-1], u-1);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
        adj[p[i]].push_back(i);
    fill(&dp[0][0], &dp[0][0]+sizeof(dp)/sizeof(int), -inf);
    dp[0][k] = 0;
    int x = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < a[i-1]; j++)
            dp[x][j] = -inf;
        for (int j = 5000; j >= b[i-1]; j--)
            dp[x][j] = dp[x][j-b[i-1]];
        for (auto& j : adj[i-1]) {
            x++;
            for (int z = 0; z < 5001; z++) {
                dp[x][z] = dp[x-1][z];
                dp[x][z] = max(dp[x][z], dp[x-1][z+1]+c[j]);
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j < 30; j++)
    //         cout << (dp[i][j] < 0 ? "-" : to_string(dp[i][j])) << " ";
    //     cout << "\n";
    // }
    int out = -inf;
    for (int i = 0; i < 5001; i++)
        out = max(out, dp[n][i]);
    cout << (out < 0 ? -1 : out) << "\n";
}