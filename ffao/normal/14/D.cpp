#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

struct info {
    int longest_path, deepest_path[2];
};

int n,k;
vector< pair<int,int> > adj[110000];
vector< info > dp[110000][3];
info none;

info dfs(int v, int p, int d = 0) {
    if (d && (p <= 0 || p >= (int)adj[v].size())) return none;
    
    info &ret = dp[v][d+1][p];
    if (ret.longest_path == -1) {
        info p1, p2;
        vector<int> deep;
        if (d) {
            p1 = dfs(adj[v][p].first, adj[v][p].second, 0);
            p2 = dfs(v, p+d, d);
        }
        else {
            p1 = dfs(v, p-1, -1);
            p2 = dfs(v, p+1, +1);
        }

        deep.insert(deep.end(), p1.deepest_path,p1.deepest_path+2);
        deep.insert(deep.end(), p2.deepest_path,p2.deepest_path+2);
        sort(deep.begin(), deep.end(), greater<int>());
        ret.longest_path = max(p1.longest_path, p2.longest_path);
        REP(i, 2) ret.deepest_path[i] = deep[i];
        
        if (!d) {
            ret.longest_path = max(ret.longest_path, ret.deepest_path[0] + ret.deepest_path[1] + 2);
            ret.deepest_path[0]++; ret.deepest_path[1] = -1;
        }
    }
    return ret;
}

int main() {
    REP(i,2) none.deepest_path[i] = -1;
    none.longest_path = 0;

    scanf("%d", &n);
    REP(i, n) adj[i].push_back({-1, -1});
    REP(i,n-1) {
        int u,v;
        scanf("%d %d", &u, &v); u--; v--;
        adj[u].push_back( {v, adj[v].size()} );
        adj[v].push_back( {u, adj[u].size()-1} );
    }
    REP(i, n) REP(j,3) {
        dp[i][j].resize(adj[i].size());
        REP(p, adj[i].size()) dp[i][j][p].longest_path = -1;
    }

    long long ans = 0;
    REP(i, n) for (int j = 1; j < (int)adj[i].size(); j++) {
        ans = max(ans, dfs(i, j).longest_path * 1ll * dfs(adj[i][j].first, adj[i][j].second).longest_path);
    }
    printf("%lld\n", ans);
}