#include <bits/stdc++.h>

using namespace std;

int n, m, ans[500050][2], cnt[500050];
vector<pair<int, int>> adj[500050];


int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[b].push_back({a, c});
    }

    memset(ans, 0x7f, sizeof ans);
    ans[n][0] = ans[n][1] = 0;
    queue<int> fila({n});

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for(auto tt : adj[u]) {
            int v = tt.first, c = tt.second;
            ans[v][c] = min(ans[v][c], max(ans[u][0], ans[u][1]) + 1);
            if(ans[v][0] <= n && ans[v][1] <= n && cnt[v] == 0) {
                fila.push(v);
                cnt[v]++;
                //assert(cnt[v] == 1);
            }
        }
    }

    int tmp = max(ans[1][0], ans[1][1]);
    printf("%d\n", tmp > n ? -1 : tmp);
    for(int i = 1; i <= n; i++) {
        printf("%d", ans[i][0] > ans[i][1] ? 0 : 1);
    }
    puts("");
    return 0;
}