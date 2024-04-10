#include <iostream>
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
    vector<ll> people(n), happiness(n);
    cin>>people>>happiness;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<pair<ll,ll>> dp(n);
    bool poss = 1;
    function<void(int,int)> dfs = [&](int u,int par){
        ll currh=0, currb=0;
        for(const auto &v : adj[u]){
            if(v==par){
                continue;
            }
            dfs(v, u);
            currh+=dp[v].first;
            currb+=dp[v].second;
        }
        ll hp = happiness[u] - currh + currb;
        if((people[u] + hp)%2 !=0) poss = 0;
        //if(u==0) cout<<currh<<" "<<currb<<" "<<hp<<"\n";
        if(happiness[u] < currh - currb - people[u]) poss = 0;
        if(happiness[u] > currh + currb + people[u]) poss = 0;
        if(happiness[u] > currh - currb + people[u]){
            currh+=(hp - people[u])/2;
            currb-=(hp - people[u])/2;
        }
        hp = happiness[u] - currh + currb;
        dp[u].first = (people[u] + hp)/2;
        dp[u].second = (people[u] - hp)/2;
        dp[u].first+=currh;
        dp[u].second+=currb;
    };
    dfs(0,-1);
    /*for(const auto &x : dp){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    */
    if(poss==0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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