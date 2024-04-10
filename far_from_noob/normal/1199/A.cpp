#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,q,x,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll max(ll a,ll b){
    if(a>b)return a;
    else return b;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        ll y;
        cin>>x>>y;
        ll a[n];
        fo(i,n)cin>>a[i];
        ll mini=mod;
        fo(i,n){
            vector<ll>v;
            for(ll j= max(1-1,i-x);j<= min(n-1,i+y);j++){
                v.push_back(a[j]);
            }
            ll temp=a[i];
            mini=mod;
            //sort( v , v + v.size());
            fo(j,v.size())mini=min(mini,v[j]);
            if(temp==mini ){cout<<i+1;return 0;}
            
        }
        //cout<<mini;
        
    }

    return 0;
}