#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
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
vector<ll>v[100005];
dd ans,count1;
 
ll dfs(ll len,ll root,ll node,dd p){
    if(v[node].size()==1 && node!=1){
        ans+=len*p;
    }
    else {
        ll l;
        if(node==1)l=v[1].size();
        else l=v[node].size()-1;
        fo(i,v[node].size()){
            if(v[node][i]!=root)dfs(len+1,node,v[node][i],p/l);
        }
    }
    return 0;
}
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        if(n==1){cout<<0;return 0;}
        fo(i,n-1){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        ans=0;
        
        dfs(0,1,1,1);
        
        printf("%.9f",ans);
        
    }
 
    return 0;
}