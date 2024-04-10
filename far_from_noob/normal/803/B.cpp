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
        int a[n];
        fo(i,n)cin>>a[i];
        int l[n],r[n];
        int temp=1000000;
        for(int i=0;i<n;i++){
            if(a[i]==0)temp=0;
            else temp++;
            l[i]=temp;
        }
         temp=1000000;
        for(int i=n-1;i>=0;i--){
            if(a[i]==0)temp=0;
            else temp++;
            r[i]=temp;
        }
        fo(i,n)cout<<min(l[i],r[i])<<" ";
    }

    return 0;
}