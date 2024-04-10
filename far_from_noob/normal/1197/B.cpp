#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=998244353;
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
        fo(i,n)cin>>a[i];
        ll maxx=0,position;
        fo(i,n){
            if(a[i]>maxx)maxx=a[i],position=i;
        }
        //cout<<position;
        for(int i=position-1;i>=0;i--){
            if(a[i]>a[i+1])flag=1;
        }
        for(int i=position +1;i<n;i++){
            if(a[i-1]<a[i])flag=1;
        }
        if(flag)cout<<"NO";
        else cout<<"YES";
    }

    return 0;
}