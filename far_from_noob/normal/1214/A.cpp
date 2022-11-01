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
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        ll d,e;
        cin>>d>>e;
        e=e*5;
        ll lcm= e*d/(__gcd(e,d));
        //n=n%(lcm);
        
        ll mini=mod;
        fo(i,n/min(d,e) +1 ){
            mini=min(mini, ((n-i*min(d,e)) %max(e,d) ));
            
        }
        fo(i,n/max(d,e) +1 ){
            mini=min(mini, ((n-i*max(d,e)) %min(e,d) ));
            
        }
        cout<<mini;
        
    }

    return 0;
}