#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<vector<int>> G(n);
        for(int i = 1, u, v; i < n; i += 1){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        auto bfs = [&](int s){
            vector<int> d(n, -1);
            d[s] = 0;
            queue<int> q;
            q.push(s);
            while(not q.empty()){
                int u = q.front();
                q.pop();
                for(int v : G[u]) if(d[v] == -1){
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
            return d;
        };
        auto d0 = bfs(0);
        int L = 0, R = n - 1;
        while(L < R){
            int m = (L + R + 1) >> 1;
            int s = max_element(d0.begin(), d0.begin() + m + 1) - d0.begin();
            auto ds = bfs(s);
            int t = max_element(ds.begin(), ds.begin() + m + 1) - ds.begin();
            auto dt = bfs(t);
            int cL = 1;
            for(int i = 0; i <= m; i += 1) if(ds[i] + dt[i] != ds[t]) cL = 0;
            if(cL) L = m;
            else R = m - 1;
        }
        int m = L;
        int s = max_element(d0.begin(), d0.begin() + m + 1) - d0.begin();
        auto ds = bfs(s);
        int t = max_element(ds.begin(), ds.begin() + m + 1) - ds.begin();
        vector<LL> ans(n + 1);
        vector<int> sz(n), an(n), rm(n);
        function<void(int)> dfs = [&](int u){
            an[u] = u == t;
            sz[u] = 1;
            for(int v : G[u]) if(ds[v] == ds[u] + 1){
                dfs(v);
                sz[u] += sz[v];
                if(an[v]) rm[u] = sz[v];
                an[u] |= an[v];
            }
        };
        dfs(s);
        ans[0] = (LL)n * (n - 1) / 2;
        ans[1] = ans[0] - (LL)(n - sz[0]) * (n - sz[0] - 1) / 2; 
        for(int v : G[0]){
            if(ds[v] > ds[0])
                ans[1] -= (LL)sz[v] * (sz[v] - 1) / 2; 
        }
        int U = 0, D = 0;
        for(int i = 1; i <= m; i += 1){
            if(ds[i] < ds[U]) U = i;
            if(ds[i] > ds[D]) D = i;
            ans[i + 1] = (LL)(n - rm[U]) * sz[D];
            //cout << i << " " << s << " " << U << " " << D << endl;
        }
        for(int i = 0; i < n; i += 1) ans[i] -= ans[i + 1];
        for(LL x : ans) cout << x << " ";
        cout << "\n";
    }
	return 0;
}