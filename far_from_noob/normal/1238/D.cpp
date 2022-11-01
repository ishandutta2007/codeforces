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
        cin>>n;
        string s;
        cin>>s;
        vector<ll>a;
        vector<ll>b;
        a.pb(0),b.pb(0);
        fo(i,n){
            if(s[i]=='A')a.pb(i+1);
            else b.pb(i+1);
        }
        ll ans=n*(n-1)/2;
        a.pb(n+1);
        b.pb(n+1);
        for(int i=1;i<a.size()-1;i++){
            ans=ans- (a[i]-a[i-1]-1 + a[i+1]-a[i]-1);
            //ans=ans- (a[i]-a[i-1]-1 + a[i+1]-a[i]-1);
        }
        //cout<<ans<<endl;
        for(int i=1;i<b.size()-1;i++){
            //ans=ans- (b[i]-b[i-1]-1 + b[i+1]-b[i]-1);
            if(b[i]-b[i-1]-1>1)ans-=b[i]-b[i-1]-2;
            if( b[i+1]-b[i]-1>1)ans-= b[i+1]-b[i]-2;
            
            //ans=ans- (a[i]-a[i-1]-1 + a[i+1]-a[i]-1);
        }
        cout<<ans;
        
    }

    return 0;
}