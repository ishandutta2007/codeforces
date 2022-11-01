#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;

vector<ll>v[100005];
ll n,k,t,m,q,x,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
           cin>>n;
           ll a[n];
           fo(i,n-1){
               ll l,r;
               cin>> l>>r;
               v[l].push_back(r);
               v[r].push_back(l);
               
           }
           for(int i=1;i<=n;i++){
               if(v[i].size()==2){
               for(int j=0;j<v[i].size();j++){
                   if(1){cout<<"NO";return 0;}
               }
               }
           }
           cout<<"YES";
    }

    return 0;
}