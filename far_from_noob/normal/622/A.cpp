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
ll vo(ll n){return n*(n+1)/2;}
ll maxn(ll n,ll temp,ll k){
    if(vo(temp+k) >= n ){
        if(vo(temp+k-1) <n)return temp+k-1;
        else return maxn(n,1,k+temp/2);
    }
    else return maxn(n,temp*2,k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //cin>>t;
    t=1;
    while(t--){
            cin>>n;
            n=n-vo(maxn(n,1,0));
            cout<<n;
        }

    return 0;
}