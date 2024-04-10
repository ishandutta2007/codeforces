#include <bits/stdc++.h>
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
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> gt(n);
    vector<int> dep(n);
    vector<int> par(n, -1);
    {
        vector<bool> vis(n);
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(auto &v : g[u]){
                if(vis[v]) continue;
                gt[u].push_back(v);
                par[v] = u;
                dep[v] = dep[u] + 1;
                dfs(v);
            }
        };
        dfs(0);
    }
    int q;
    cin>>q;
    vector<int> prt(n);
    vector<vector<int>> paths(q);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        --a;--b;
        vector<int> s1, s2;
        while(dep[a] > dep[b]){
            s1.push_back(a);
            prt[a] ^= 1;
            a = par[a];
        }
        while(dep[b] > dep[a]){
            s2.push_back(b);
            prt[b] ^= 1;
            b = par[b];
        }
        while(a != b){
            s1.push_back(a);
            prt[a] ^= 1;
            a = par[a];
            s2.push_back(b);
            prt[b] ^= 1;
            b = par[b];
        }
        s1.push_back(a);
        reverse(s2.begin(), s2.end());
        for(auto &x : s1) paths[i].push_back(x+1);
        for(auto &x : s2) paths[i].push_back(x+1);
    }
    ll ans = accumulate(prt.begin(), prt.end(), 0);
    {
        function<void(int)> dfs = [&](int u){
            int cnt = prt[u];
            for(auto &v : gt[u]){
                cnt += prt[v];
                dfs(v);
            }
            ans -= cnt / 2;
        };
        dfs(0);
    }
    if(ans == 0){
        cout<<"YES\n";
        for(int i=0;i<q;i++){
            cout<<paths[i].size()<<"\n";
            cout+paths[i];
        }
        return;
    }
    cout<<"NO\n";
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}