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
    int n,m,q;
    cin>>n>>m>>q;
    vector<array<int, 2>> edges(m);
    for(auto &[u,v] : edges){
        cin>>u>>v;
        --u;--v;
    }
    vector<int> ans(q);
    vector<array<int, 5>> qr(q);
    vector<vector<int>> tt(n, vector<int>(n, m+1));
    for(int i=0;i<n;i++) tt[i][i] = 0;
    int _ = 0;
    for(auto &[l,r,s,t,i] : qr){
        cin>>l>>r>>s>>t;
        --s;--t;
        i = _++;
    }
    sort(qr.begin(), qr.end());
    reverse(qr.begin(), qr.end());
    for(auto &[l,r,s,t,i] : qr){
        while(l <= edges.size()){
            auto [u,v] = edges.back();
            tt[u][v] = min(tt[u][v], (int)edges.size());
            tt[v][u] = min(tt[v][u], (int)edges.size());
            for(int i=0;i<n;i++){
                if(i == u || i == v) continue;
                tt[u][i] = min(tt[u][i], tt[v][i]);
                tt[v][i] = min(tt[u][i], tt[v][i]);
            }
            edges.pop_back();
        }
        if(tt[s][t] <= r){
            ans[i] = 1;
        }
        else{
            ans[i] = 0;
        }
    }
    for(int i=0;i<q;i++){
        if(ans[i]) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}