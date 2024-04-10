#include <bits/stdc++.h>
#define MN 300300

using namespace std;

int dp[MN][27], n, m, a, b, visit[MN], cor[MN];
vector<int> adj[MN];

char s[MN];

bool cycle(int node) {
    if(visit[node] == 1) return true;
    if(visit[node] == 2) return false;
    visit[node] = 1;

    for(int v : adj[node]) {
        if(cycle(v)) return true;
    }

    visit[node] = 2;
    return false;
}

int solve(int node, int c) {
    if(dp[node][c] != -1) return dp[node][c];

    int x = (cor[node] == c);
    for(int v : adj[node]) {
        x = max(x, solve(v, c) + (cor[node] == c));
    }

    return dp[node][c] = x;
}

int main() {
    scanf("%d %d %s", &n, &m, s);
    for(int i = 1; i <= n; i++)
        cor[i] = (s[i-1] - 'a');

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++) {
        if(cycle(i)) {
            printf("-1\n");
            return 0;
        }
    }

    int ans = 0;
    memset(dp, -1, sizeof dp);
    for(int c = 0; c < 26; c++)
        for(int i = 1; i <= n; i++)
            ans = max(ans, solve(i, c));

    printf("%d\n", ans);
    return 0;
}