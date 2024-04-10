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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n;
        ll a,b;
        cin>>a>>b;
        ll c,d;
        cin>>c>>d;
        if(c>=d){
            ll ans=0;
            ans+=min(c*a , n/2 * c);
            n= max(n-2*a, 0);
            ans+=min(d*b , n/2 * d);
            cout<<ans<<endl;
        }
        else {
            swap(a,b);
            swap(c,d);
            ll ans=0;
            ans+=min(c*a , n/2 * c);
            n= max(n-2*a, 0);
            ans+=min(d*b , n/2 * d);
            cout<<ans<<endl;
        }
    }

    return 0;
}