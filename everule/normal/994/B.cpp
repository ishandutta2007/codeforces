#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    map<int,int> coin;    
    for(auto &x : p){
        cin>>x;
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        coin[p[i]] = x;
    }
    map<int,ll> ans;
    vector<int> p2 = p;
    set<pair<int,int>, greater<pair<int,int>>> curr;
    auto get = [&](int p){
        int K = k;
        ll ans = 0;
        for(const auto &x : curr){
            if(K==0) break;
            --K;
            ans+=x.first;
        }
        return ans;
    };
    sort(p2.begin(), p2.end());
    for(int i=0;i<n;i++){
        ans[p2[i]] = get(p2[i]);
        curr.insert({coin[p2[i]], p2[i]});
    }
    for(int i=0;i<n;i++){
        cout<<ans[p[i]] + coin[p[i]]<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}