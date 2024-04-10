#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> childcount(n);
    vector<int> par(n);
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(const auto &v : adj[u]){
            if(vis[v]) continue;
            par[v] = u;
            dfs(v);
            ++childcount[u];
        }
    };
    dfs(0);
    set<pair<int,int>> nodes;
    vis = vector<bool>(n);
    vector<pair<int,int>> answer;
    for(int i=0;i<n;i++){
        nodes.insert({childcount[i], i});
    }
    auto remove = [&](int u){
        assert(u!=0);
        vis[u] = 1;
        nodes.erase(nodes.find({childcount[par[u]], par[u]}));
        --childcount[par[u]];
        nodes.insert({childcount[par[u]], par[u]});
    };
    while(nodes.size()>1){
        if((*(++nodes.begin())).first!=0){
            break;
        }
        answer.pb({0,0});
        answer.back().first = (*nodes.begin()).second;
        nodes.erase(nodes.begin());
        answer.back().second = (*nodes.begin()).second;
        nodes.erase(nodes.begin());
        remove(answer.back().first);
        remove(answer.back().second);
    }
    if(2*(int)answer.size()>=(n+1)/2){
        cout<<"PAIRING\n";
        cout<<answer.size()<<"\n";
        for(const auto [a,b] : answer){
            cout<<a+1<<" "<<b+1<<"\n";
        }
    }
    else{
        cout<<"PATH\n";
        cout<<n - 2*answer.size()<<"\n";
        function<void(int)> printdfs = [&](int u){
            cout<<u+1<<" ";
            vis[u] = 1;
            for(const auto &v : adj[u]){
                if(vis[v]) continue;
                printdfs(v);
            }
        };
        printdfs(0);
        cout<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}