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
ll a[1000000];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(ll i=1000000;i>=0;i--){
        a[i]=i*(i+1)/2;
    }
    ll temp=1;
    cin>>n>>k;
    if(k>=1000000){cout<<-1;return 0;}
    if(n<a[k]){cout<<-1;return 0;}
    if(n%a[k]==0){ temp=n/a[k];}
    else {
 
        ll kk;
        if(n>100000)kk=100000;
        else kk=n;
        for(int i=1;i<= kk;i++){
            if(n%i==0){
                if( temp<i && i<=n/a[k])temp=i;
                if(temp<n/i && n/i <= n/a[k])temp=n/i;
            }
        }
        //cout<<temp<<endl;
 
 
    }
    n=n/temp;
    ll t1=1;
    while(t1<k){
        cout<<t1*temp<<" ";
        n=n-t1;
        t1++;
 
    }
    cout<<n*temp;
 
 
    return 0;
}