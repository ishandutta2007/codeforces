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
        cin>>n>>m;
        ll a=1,b=1,c=0,d=0;
        for(int i=1;i<n;i++){
            ll t1=a,t2=b;
            a=b+d;
            a%=mod;
            b%=mod;
            //c=t1;
            b=t1+c;
            c=t1;
            d=t2;
            
        }
        ll an=a+b+c+d;
        an%=mod;
        a=1,b=1,c=0,d=0;
        
        for(int i=1;i<m;i++){
            ll t1=a,t2=b;
            a=b+d;
            a%=mod;
            b%=mod;
            //c=t1;
            b=t1+c;
            c=t1;
            d=t2;
            
        }
        an+=a+b+c+d;
        an%=mod;
        cout<<(an+mod-2)%mod;
        
    }
 
    return 0;
}