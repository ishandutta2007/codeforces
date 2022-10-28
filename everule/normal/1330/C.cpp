//https://codeforces.com/contest/1330/problem/C
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<ll>
using namespace std;
ll solve(){
    ll n,m;
    cin>>n>>m;
    ll l[m];
    ll length=0;
    for(ll i=0;i<m;i++){
        cin>>l[m-i-1];
        length+=l[m-i-1];
    }
    ll ans[m];
    ans[0]=1;
    ll used_till[m];
    used_till[0]=l[0];
    for(ll i=1;i<m;i++){
        ans[i]=max(1ll,used_till[i-1]+2ll-l[i]);
        used_till[i]=max(l[i],used_till[i-1]+1);
    }
    if(used_till[m-1]>n || length<n){
        cout<<"-1";
    }
    else if(used_till[m-1]==n){
        for(ll i=m-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
    }
    else{
        ll length=0;
        ll last=n+1;
        for(ll i=m-1;i>=0;i--){
            length+=l[i];
            ans[i]=last-l[i];
            last=ans[i];
            if(used_till[i-1]+length>=n){
                break;
            }
        }
        for(ll i=m-1;i>=0;i--){
            cout<<ans[i]<<' ';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}