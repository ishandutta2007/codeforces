#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 20000 + 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<vector<int>> G(n + 1), H(n + 1);
        for(int i = 1, u, v; i < n; i += 1){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> par(n + 1), rm(n + 1);
        function<void(int)> DFS = [&](int u){
            vector<int> trm;
            for(int v : G[u]) if(v != par[u]){
                par[v] = u;
                DFS(v);
                if(not rm[v]) trm.push_back(v);
            }
            if(u == 1){
                for(int i = 2; i < (int)trm.size(); i += 1) rm[trm[i]] = 1;
                return;
            }
            if((int)trm.size() >= 2){
                rm[u] = 1;
                for(int i = 2; i < (int)trm.size(); i += 1) rm[trm[i]] = 1;
            }
        };
        DFS(1);
        for(int i = 2; i <= n; i += 1) if(not rm[i]){
            H[i].push_back(par[i]);
            H[par[i]].push_back(i);
        }
        vector<pair<int, int>> ans1, ans2;
        vector<int> vis(n + 1);
        for(int i = 2; i <= n; i += 1)
            if(rm[i]) ans1.push_back({i, par[i]});
        int Last = 0;
        function<int(int)> dfs = [&](int u){
            vis[u] = 1;
            for(int v : H[u]) if(not vis[v]) return dfs(v);
            return u;
        };
        for(int i = 1; i <= n; i += 1){
            if((int)H[i].size() <= 1 and not vis[i]){
                if(Last) ans2.push_back({Last, i});
                Last = dfs(i);
                //cout << i << " " << Last << "!" << endl;
            }
        }
        //for(auto [x, y] : ans1) cout << x << " " << y << endl;
        //cout << endl;
        //for(auto [x, y] : ans2) cout << x << " " << y << endl;
        assert(ans1.size() == ans2.size());
        cout << ans1.size() << "\n";
        for(int i = 0; i < (int)ans1.size(); i += 1)
            cout << ans1[i].first << " " << ans1[i].second << " " << ans2[i].first << " " << ans2[i].second << "\n";
    }
    return 0;
}