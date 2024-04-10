#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
vector<int>v[200005];queue<int>s;
ll n,k,t,m,p,q,x,flag=0,ans=0,waiting=0;
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

    while(1){
            m=n;
    ll a=n/1000;
    n=n-a*1000;
    ll b= n/100;
    n=n-b*100;
ll    c=n/10;
    n=n-c*10;
    k=(a+b+c+n)%4;
    //cout<<k;
    if(k==0){cout<<m;break;}

    n=m+1;
    }





    return 0;
}