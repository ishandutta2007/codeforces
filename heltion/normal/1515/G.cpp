#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
vector<pair<int, LL>> G[maxn];
LL ans[maxn], d;
vector<int> scc;
LL sum[maxn], dep[maxn];
vector<int> kosaraju(const vector<vector<int>>& G){
    int n = G.size(), c = 0;
    vector<int> vis(n), res(n, -1), p;
    vector<vector<int>> H(n);
    function<void(int)> DFS1 = [&](int u){
        vis[u] = 1;
        for(int v : G[u]) if(not vis[v]) DFS1(v);
        p.push_back(u);
    };
    function<void(int)> DFS2 = [&](int u){
        res[u] = c;
        for(int v : H[u]) if(not ~res[v]) DFS2(v);
    };
    for(int i = 0; i < n; i += 1) for(int j : G[i]) H[j].push_back(i);
    for(int i = 0; i < n; i += 1) if(not vis[i]) DFS1(i);
    reverse(p.begin(), p.end());
    for(int i : p) if(not ~res[i]) DFS2(i), c += 1;
    return res;
}
void DFS(int u){
    for(auto [v, w] : G[u]) if(scc[v] == scc[u]){
        if(not dep[v]){
            sum[v] = sum[u] + w;
            dep[v] = dep[u] + 1;
            DFS(v);
        }
        else if(dep[v] < dep[u]){
            d = gcd(d, abs(sum[u] - sum[v] + w));
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> H(n + 1);
    for(int i = 0; i < m; i += 1){
        int a, b, l;
        cin >> a >> b >> l;
        G[a].push_back({b, l});
        G[b].push_back({a, -l});
        H[a].push_back(b);
    }
    scc = kosaraju(H);
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i += 1) mp[scc[i]].push_back(i);
    for(auto [x, v] : mp){
        d = 0;
        dep[v[0]] = 1;
        DFS(v[0]);
        for(auto y : v) ans[y] = d;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i += 1){
        LL v, s, t;
        cin >> v >> s >> t;
        if(s == 0){
            cout << "YES\n";
        }
        else if(mp[scc[v]].size() == 1){
            cout << "NO\n";
        }
        else{
            LL a = gcd(s, t);
            LL b = gcd(ans[v], t);
            if(a == 0 or (b and a % b == 0)){
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
    return 0;
}