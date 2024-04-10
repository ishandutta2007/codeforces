//https://codeforces.com/contest/1343/problem/E
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
void solve(){
    int n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;
    --a, --b, --c;
    vector<vector<int>> edges(n);
    vector<int> distfroma(n, -1);
    vector<int> distfromb(n, -1);
    vector<int> distfromc(n, -1);
    distfroma[a]=0;
    distfromb[b]=0;
    distfromc[c]=0;
    vector<ll> prices(m);
    vector<ll> priceprefix(m+1);
    for(auto &x : prices){
        cin>>x;
    }
    sort(prices.begin(), prices.end());
    for(int i=1;i<=m;i++){
        priceprefix[i]=priceprefix[i-1]+prices[i-1];
    }
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        edges[--x].pb(--y);
        edges[y].pb(x);
    }
    queue<int> tochk;
    tochk.push(a);
    while(!tochk.empty()){
        int x=tochk.front();
        tochk.pop();
        for(const auto &adj : edges[x]){
            if(distfroma[adj]==-1){
                tochk.push(adj);
                distfroma[adj]=distfroma[x]+1;
            }
        }
    }
    tochk.push(b);
    while(!tochk.empty()){
        int x=tochk.front();
        tochk.pop();
        for(const auto &adj : edges[x]){
            if(distfromb[adj]==-1){
                tochk.push(adj);
                distfromb[adj]=distfromb[x]+1;
            }
        }
    }
    tochk.push(c);
    while(!tochk.empty()){
        int x=tochk.front();
        tochk.pop();
        for(const auto &adj : edges[x]){
            if(distfromc[adj]==-1){
                tochk.push(adj);
                distfromc[adj]=distfromc[x]+1;
            }
        }
    }
    ll ans=1e18;
    for(int i=0;i<n;i++){
        int totdistance=distfroma[i]+distfromb[i]+distfromc[i];
        if(totdistance>m){
            continue;
        }
        ans=min(ans, priceprefix[totdistance] + priceprefix[distfromb[i]]);
    }
    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    //precompute();
    while(t--){
        //init();
        solve();
    }
}