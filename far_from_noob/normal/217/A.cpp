#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,p,q,b,flag=0;
int x[100],y[100];
map<int,int>mapx;
map<int,int>mapy;
map<int,int>dfslaga;
void dfs(int j,int n){
    fo(i,n){
        if((x[i]==x[j]||y[i]==y[j]) && dfslaga[i]==0)dfslaga[i]=1,dfs(i,n);
    }
}
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;
        ans%=mod;
        ans1=ans1*ans1;
        ans1%=mod;
        n=n-temp;
        temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //cout<<po(2,78,1,1,2);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        ll ans=-1;
        fo(i,n)cin>>x[i]>>y[i];
        fo(i,n)if(dfslaga[i]==0)dfslaga[i]=1,dfs(i,n),ans++;

        cout<<ans;

    }

    return 0;
}