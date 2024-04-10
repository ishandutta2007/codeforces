//https://codeforces.com/problemset/problem/1312/D
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
ll p =998244353;
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
ll fact[200007];
ll invfact[200007];
void computefactorial(){
    fact[0]=1;
    for(int i=1;i<200007;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=p;
    }
    invfact[200006]=modpower(fact[200006],p-2);
    for(int i=200005;i>=0;i--){
        invfact[i]=(i+1)*invfact[i+1];
        invfact[i]%=p;
    }
}
inline ll ncr(int n, int r){
    return ((fact[n]*invfact[r])%p * invfact[n-r])%p;
}
ll solve(){
    int n,m;
    cin>>n>>m;
    if(n==2){
        return 0;
    }
    ll ans=n-2;
    ans*=ncr(m,n-1);
    ans%=p;
    ans*=modpower(2,n-3);
    ans%=p;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computefactorial();
    cout<<solve();
}