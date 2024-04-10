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
    int n;
    cin>>n;
    int a;
    cin>>a;
    vector<vector<int>> g1(a);
    for(int i=1;i<a;i++){
        int p;
        cin>>p;
        --p;
        g1[p].push_back(i);
    }
    vector<int> x(a, -1);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        --t;
        x[t] = i;
    }
    int b;
    cin>>b;
    vector<vector<int>> g2(b);
    for(int i=1;i<b;i++){
        int p;
        cin>>p;
        --p;
        g2[p].push_back(i);
    }
    vector<int> y(b);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        --t;
        y[t] = i;
    }
    vector<int> tin1(a, n), tin2(b, n), tout1(a), tout2(b), sz1(a, 1), sz2(b, 1);
    vector<int> dp(n+1);
    {
        function<void(int)> dfs = [&](int u){
            for(auto &v : g1[u]){
                dfs(v);
                sz1[u] += sz1[v];
                tin1[u] = min(tin1[u], tin1[v]);
                tout1[u] = max(tout1[u], tout1[v]);
            }
            if(g1[u].size() == 0){
                tout1[u] = tin1[u] = x[u];
            }
        };
        dfs(0);
    }
    {
        function<void(int)> dfs = [&](int u){
            for(auto &v : g2[u]){
                dfs(v);
                sz2[u] += sz2[v];
                tin2[u] = min(tin2[u], tin2[v]);
                tout2[u] = max(tout2[u], tout2[v]);
            }
            if(g2[u].size() == 0){
                tout2[u] = tin2[u] = y[u];
            }
        };
        dfs(0);
    }
    //cout+tin1+tout1+tin2+tout2+sz1+sz2;
    vector<vector<array<int, 2>>> dptrans(n+1);
    for(int i=0;i<a;i++){
        dptrans[tout1[i] + 1].push_back({tin1[i], sz1[i] - (i == 0)});
    }
    for(int i=0;i<b;i++){
        dptrans[tout2[i] + 1].push_back({tin2[i], sz2[i] - (i == 0)});
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<dptrans[i].size();j++){
            dp[i] = max(dp[i], dp[dptrans[i][j][0]] + dptrans[i][j][1]);
        }
    }
    cout<<dp[n]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}