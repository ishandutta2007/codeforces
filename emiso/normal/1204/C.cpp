#include <bits/stdc++.h>

#define MN 110

using namespace std;
typedef long long ll;

int n, m, adj[MN][MN], dp[1000100], last[1000100], dist[MN][MN], INF = 1000000, p[1000100];

int main() {
    scanf("%d", &n);

    for(int i = 0; i < MN; i++)
        for(int j = 0; j < MN; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%1d", &adj[i][j]);
            if(adj[i][j]) dist[i][j] = 1;
        }
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
        scanf("%d", &p[i]);

    dp[1] = 1, last[1] = 0;
    for(int i = 2; i <= m; i++) {
        int best = INF, bpai = -1;
        for(int j = i - 1; j >= max(1, i - n); j--) {
            if(dist[p[j]][p[i]] == (i - j) && dp[j] < best) {
                best = dp[j];
                bpai = j;
            }
        }
        dp[i] = best + 1;
        last[i] = bpai;
    }

    printf("%d\n", dp[m]);

    vector<int> ans;
    while(m != 0) {
        ans.push_back(p[m]);
        m = last[m];
    }
    reverse(ans.begin(), ans.end());

    for(int x : ans) printf("%d ", x);
    return 0;
}