#include <bits/stdc++.h>

#define MX 2020
#define MN 1001000
#define NOT(x) ((x)^1)

using namespace std;
typedef long long ll;

ll t, n, g[1010][1010], h[1010][1010], vis[4040];
vector<int> adj[4040];

void dfs(int no) {
    if(vis[no]) return;
    vis[no] = 1;
    for(int v : adj[no]) {
        dfs(v);
    }
}

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%1lld", &g[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%1lld", &h[i][j]);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] == h[i][j]) { // 0 ou 2
                adj[2*i].push_back(MX+2*j);
                adj[MX+2*j].push_back(2*i);

                adj[NOT(2*i)].push_back(NOT(MX+2*j));
                adj[NOT(MX+2*j)].push_back(NOT(2*i));
            } else { // 1
                adj[2*i].push_back(NOT(MX+2*j));
                adj[MX+2*j].push_back(NOT(2*i));

                adj[NOT(2*i)].push_back(MX+2*j);
                adj[NOT(MX+2*j)].push_back(2*i);
            }
        }
    }

    int flag = 1;
    for(int i = 0; flag && i < n; i++) {
        if(!vis[2*i] && !vis[NOT(2*i)]) {
            dfs(2*i);
        }
        if(vis[2*i] && vis[NOT(2*i)]) flag = 0;

        if(!vis[MX+2*i] && !vis[NOT(MX+2*i)]) {
            dfs(MX+2*i);
        }
        if(vis[MX+2*i] && vis[NOT(MX+2*i)]) flag = 0;
    }

    puts(flag ? "YES" : "NO");

    for(int i = 0; i <= 2*n; i++) {
        adj[i].clear();
        adj[i+MX].clear();
        vis[i] = 0;
        vis[i+MX] = 0;
    }
    if(--t) goto st;
    return 0;
}