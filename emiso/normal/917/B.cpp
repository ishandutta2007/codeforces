#include <bits/stdc++.h>

using namespace std;

int dp[110][110][28][2], n, m, a, b;
char c;

vector<pair<int, int> > adj[110];

int solve(int mp, int lp, int last, int t) {
    if(dp[mp][lp][last][t] != -1) return dp[mp][lp][last][t];

    if(t == 0) {
        dp[mp][lp][last][t] = 1;
        for(int i = 0; i < adj[mp].size(); i++) {
            int v = adj[mp][i].first, ch = adj[mp][i].second;
            if(ch >= last && solve(v, lp, ch, 1) == 0)
                dp[mp][lp][last][t] = 0;
        }
    }
    else {
        dp[mp][lp][last][t] = 0;
        for(int i = 0; i < adj[lp].size(); i++) {
            int v = adj[lp][i].first, ch = adj[lp][i].second;
            if(ch >= last && solve(mp, v, ch, 0) == 1)
                dp[mp][lp][last][t] = 1;
        }
    }

    return dp[mp][lp][last][t];
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %c", &a, &b, &c);
        adj[a].push_back(make_pair(b, c - 'a' + 1));
    }

    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%c", solve(i, j, 0, 0) ? 'B' : 'A');
        } puts("");
    }
    return 0;
}