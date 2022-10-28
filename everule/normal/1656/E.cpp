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
    int n;
    cin>>n;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        --x;--y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> dep(n);
    {
        function<void(int,int)> dfs = [&](int u,int p){
            for(auto &v : g[u]){
                if(v == p) continue;
                dep[v] = dep[u] + 1;
                dfs(v, u);
            }
        };
        dfs(0, 0);
    }
    bool odd = 0;
    for(int i=0;i<n;i++){
        if(g[i].size() >= n/2){
            if(dep[i] % 2 == 1) odd = 1;
        }
    }
    vector<int> s(n);
    for(int i=0;i<n;i++){
        if(dep[i] == 0){
            s[i] = 1;
            continue;
        }
        if(dep[i] % 2 == 1){
            s[i] = (odd ? 2 : -1);
        }
        else{
            s[i] = (odd ? -1 : 2);
        }
    }
    //cout+s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i] = s[i];
        for(auto &v : g[i]){
            if(dep[v] < dep[i]) continue;
            a[i] -= s[v];
        }
    }
    cout+a;
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