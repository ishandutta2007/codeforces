#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m;
        vector<ll>v[n+1];
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
       }
       map<ll,ll>m1;
       fo(i,n){
           if(m1[i+1]==0){
               m1[i+1]=1;
               fo(j,v[i+1].size()){
                   m1[v[i+1][j]]=1;
               }
               fo(j,v[i+1].size()){
                   if(v[v[i+1][j]].size()!=v[i+1].size()){
                       cout<<"NO";
                       return 0;
                   }
                   fo(l,v[v[i+1][j]].size()){
                       if(m1[v[v[i+1][j]][l]] ==0){
                       cout<<"NO";
                       return 0;
                   }
                   }
               }
           }
           
       }
       cout<<"YES";
    }

    return 0;
}