#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,p,q,a,b,x,flag=0;
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

    cin>>n;
    if(n%2==0){
        fo(i,n/2)cout<<i*2+1<<" ";
        fo(i,n/2)cout<<n-i*2-1<<" ";
        for(int i=2;i<=n;i=i+2)cout<<i<<" ";
        for(int i=n-2;i>0;i=i-2)cout<<i<<" ";
        cout<<n;
        
    }
    else {
        for(int i=2;i<n;i=i+2)cout<<i<<" ";
        for(int i=n-1;i>0;i=i-2)cout<<i<<" ";
        for(int i=1;i<=n;i=i+2)cout<<i<<" ";
        for(int i=n-2;i>0;i=i-2)cout<<i<<" ";
        cout<<n;
    }
    

    return 0;
}