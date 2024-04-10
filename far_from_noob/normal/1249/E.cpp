#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
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
        cin>>n>>k;
        ll a[n];
        ll b[n];
        fo(i,n-1)cin>>a[i];
        fo(i,n-1)cin>>b[i];
        ll sta[n],ele[n];
        sta[0]=0,ele[0]=0;
        sta[1]=a[0],ele[1]=b[0]+k;
        for(int i=2;i<=n-1;i++){
            sta[i]=min(sta[i-1]+a[i-1],ele[i-1]+a[i-1]);
            //cout<<sta[i];
            ele[i]=min(sta[i-1]+b[i-1]+k,ele[i-1]+b[i-1]);
            //cout<<ele[i];
            
        }
        
        fo(i,n)cout<<min(sta[i],ele[i])<<" ";
    }

    return 0;
}