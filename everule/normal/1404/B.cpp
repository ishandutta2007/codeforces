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
void solve(){
    int n,a,b,da,db;
    cin>>n>>a>>b>>da>>db;
    --a;--b;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    function<int(void)> diameter = [&](){
        queue<int> bfs;
        bfs.push(0);
        vector<int> dist(n, -1);
        dist[0] = 0;
        int ans = 0;
        while(!bfs.empty()){
            for(const auto &v : adj[bfs.front()]){
                if(dist[v]!=-1) continue;
                dist[v] = dist[bfs.front()] + 1;
                bfs.push(v);
                ans = v;
            }
            bfs.pop();
        }
        dist = vector<int>(n, -1);
        bfs.push(ans);
        dist[ans] = 0;
        while(!bfs.empty()){
            for(const auto &v : adj[bfs.front()]){
                if(dist[v]!=-1) continue;
                dist[v] = dist[bfs.front()] + 1;
                bfs.push(v);
                ans = v;
            }
            bfs.pop();
        }
        return dist[ans];
    };
    int d = diameter();
    da = min(da, d);
    db = min(db, d);
    vector<int> dist(n, -1);
    function<void(int,int)> dfs = [&](int u,int par){
        dist[u] = dist[par] + 1;
        for(const auto &v : adj[u]){
            if(v==par) continue;
            dfs(v,u);
        }
    };
    dfs(a,a);
    if(dist[b] <= da){
        cout<<"Alice\n";
        return;
    }
    if(2*da<db){
        cout<<"Bob\n";
    }
    else{
        cout<<"Alice\n";
    }
    return;
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