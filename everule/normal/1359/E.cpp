//https://codeforces.com/contest/1359/problem/E
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
const ll p =998244353;
ll modpower(ll base, ll power, ll mod=p){
    ll ans =1;
    base%=p;
    while(power){
        if(power&1){
            ans*=base;
            ans%=p;
        }
        base*=base;
        base%=p;
        power>>=1;
    }
    return ans;
}
vector<ll> fact;
vector<ll> invfact;
void computefactorial(int n){
    ++n;
    fact.resize(n);
    invfact.resize(n);
    fact[0]=1;
    for(int i=1;i<n;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=p;
    }
    invfact[n-1]=modpower(fact[n-1],p-2);
    for(int i=n-2;i>=0;i--){
        invfact[i]=(i+1)*invfact[i+1];
        invfact[i]%=p;
    }
}
ll ncr(int n, int r){
    if(n<0 || r>n){
        return 0;
    }
    return fact[n]*invfact[r]%p * invfact[n-r]%p;
}
void solve(){
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=ncr(n/i - 1, k-1);
    }
    cout<<ans%p<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computefactorial(5e5  + 7);
    solve();
}