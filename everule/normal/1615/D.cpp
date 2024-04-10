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
    int n,m;
    cin>>n>>m;
    vector<vector<array<int, 2>>> g(n);
    vector<vector<array<int, 2>>> pg(n);
    for(int i=1;i<n;i++){
        int x,y,v;
        cin>>x>>y>>v;
        --x;--y;
        g[x].push_back({y, v});
        g[y].push_back({x, v});
        if(v != -1){
            pg[x].push_back({y, __builtin_popcount(v) % 2});
            pg[y].push_back({x, __builtin_popcount(v) % 2});
        }
    }
    for(int i=0;i<m;i++){
        int a,b,p;
        cin>>a>>b>>p;
        --a;--b;
        pg[a].push_back({b, p});
        pg[b].push_back({a, p});
    }
    vector<int> prty(n);
    {
        bool flg = 0;
        vector<bool> vis(n);
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(auto &v : pg[u]){
                if(vis[v[0]]){
                    if(prty[v[0]] ^ prty[u] ^ v[1]){
                        flg = 1;
                        return;
                    }
                    continue;
                }
                prty[v[0]] = (prty[u] ^ v[1]);
                dfs(v[0]);
            }
        };
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i);
            if(flg){
                cout<<"NO\n";
                return;
            }
        }
    }
    vector<vector<array<int, 2>>> gf(n);
    {
        function<void(int,int)> dfs = [&](int u,int pr){
            for(auto &v : g[u]){
                if(v[0] == pr) continue;
                if(v[1] != -1){
                    gf[u].push_back(v);
                }
                else{
                    gf[u].push_back({v[0], (prty[u] ^ prty[v[0]])});
                }
                dfs(v[0], u);
            }
        };
        dfs(0, 0);
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++){
        for(auto &v : gf[i]){
            cout<<i+1<<" "<<v[0] + 1<<" "<<v[1]<<"\n";
        }
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