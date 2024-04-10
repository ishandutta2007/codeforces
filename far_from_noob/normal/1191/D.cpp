#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(ll i=0;i<n;i++)
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
            cin>>n;
            ll a[n];
            fo(i,n)cin>>a[i];
            sort(a,a+n);
            if(a[n-1]==0){cout<<"cslnb";return 0;}
            if(a[1]==0){cout<<"cslnb";return 0;}
            int temp=0;
            fo(i,n-1)if(a[i]==a[i+1])temp++;
            if(temp>1){cout<<"cslnb";return 0;}
            for(int i=1;i<n-1;i++)if(a[i]-a[i-1]==1 && a[i]==a[i+1]){cout<<"cslnb";return 0;}
            ll sum=0;
            fo(i,n)sum+=a[i];
            if((sum-n*(n-1)/2 )%2==0){cout<<"cslnb";return 0;}
            else {cout<<"sjfnb";return 0;}

    }

    return 0;
}