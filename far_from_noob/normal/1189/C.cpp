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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        ll a[n];
        ll sum[n];
        ll temp=0;
        fo(i,n){cin>>a[i];sum[i]=a[i]+temp;temp=sum[i];}
        cin>>q;
        fo(i,q){
            ll l,r;
            cin>>l>>r;
            if(l==1)cout<<(sum[r-1])/10<<endl;
            else cout<<(sum[r-1]-sum[l-2])/10<<endl;
        }
        
    }
 
    return 0;
}