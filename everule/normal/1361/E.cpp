#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
const int checks = 80;
const int INF = 1e9 + 7;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    vector<pair<int,int>> edges;
    edges.reserve(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(pair(v,i));
        edges.emplace_back(u,v);
    }
    int root = -1;
    for(int i=0;i<checks;i++){
        vector<bool> vis(n);
        vector<bool> instack(n);
        bool ans = 1;
        function<void(int)> dfs = [&](int u){
            instack[u] = 1;
            vis[u] = 1;
            for(const auto &[v,idx] : adj[u]){
                if(vis[v]){
                    if(!instack[v]){
                        ans = 0;
                    }
                    continue;
                }
                dfs(v);
            }
            instack[u] = 0;
        };
        int idx = ((rand()<<15)^(rand()<<10)^rand()) % n;
        dfs(idx);
        if(ans){
            root = idx;
            break;
        }
    }
    if(root == -1){
        cout<<"-1\n";
        return;
    }
    vector<int> dep(n);
    vector<int> passing(n);
    vector<int> passidx(n, -1);
    [&](){
        vector<bool> vis(n);
        vector<int> par(n);
        dep[root] = 0;
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(const auto &[v,idx] : adj[u]){
                if(vis[v]){
                    passing[v]--;
                    passing[u]++;
                    int d1 = dep[v];
                    int d2 = (passidx[u] == -1) ? INF : min(dep[edges[passidx[u]].first], dep[edges[passidx[u]].second]);
                    if(d1 < d2){
                        passidx[u] = idx;
                    }
                }
            }
            for(const auto &[v,idx] : adj[u]){
                if(vis[v]) continue;
                par[v] = u;
                dep[v] = dep[u] + 1;
                dfs(v);
                passing[u] += passing[v];
                int d1 = (passidx[v] == -1) ? INF : min(dep[edges[passidx[v]].first], dep[edges[passidx[v]].second]);
                int d2 = (passidx[u] == -1) ? INF : min(dep[edges[passidx[u]].first], dep[edges[passidx[u]].second]);
                if(d1 < d2){
                    passidx[u] = passidx[v];
                }
            }
        };
        dfs(root);
    }();
    vector<bool> answer(n);
    answer[root] = 1;
    vector<int> dp(m, -1);
    function<int(int)> solve = [&](int eid){
        if(dp[eid] != -1) return dp[eid];
        auto [u,v] = edges[eid];
        if(v == root) return dp[eid] = 1;
        if(passing[v] != 1) return dp[eid] = 0;
        int neid = passidx[v];
        return dp[eid] = solve(neid);
    };
    for(int i=0;i<n;i++){
        if(i == root) continue;
        if(passing[i] != 1) continue;
        answer[i] = solve(passidx[i]);
    }
    int cnt = count(answer.begin(), answer.end(), bool(1));
    if(5*cnt < n){
        cout<<"-1\n";
    }
    else{
        //cout<<cnt<<"\n";
        for(int i=0;i<n;i++) if(answer[i]) cout<<i+1<<" ";
        cout<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    //srand(0);
    srand(time(0));
    while(t--){
        solve();
    }
}