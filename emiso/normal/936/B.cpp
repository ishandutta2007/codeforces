#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, s, b, c, visit[MN];
vector<int> adj[MN];

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

stack<int> bt;
int dp[MN][2];
bool solve(int node, int f) {
    if(dp[node][f] != -1) return false;

    dp[node][f] = f;
    for(int v : adj[node]) {
        if(solve(v, 1 - f)) {
            bt.push(node);
            return true;
        }
    }

    if(f && adj[node].empty()) {
        bt.push(node);
        return true;
    }

    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof dp);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &c);
        for(int j = 0; j < c; j++) {
            scanf("%d", &b);
            adj[i].push_back(b);
        }
    }
    scanf("%d", &s);

    if(solve(s, 0)) {
        printf("Win\n");
        while(!bt.empty()) {
            printf("%d ", bt.top());
            bt.pop();
        } puts("");
    }
    else if(cycle(s)) printf("Draw\n");
    else printf("Lose\n");

    return 0;
}