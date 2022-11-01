#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=998244353;
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
ll fac[1000000];

int main() {
    fo(i,1000000){
        if(i==0)fac[i]=1;
        else {
            fac[i]=(fac[i-1]*i)%mod;
        }
    }
    //cout<<fac[31]<<endl;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        ll a[n],b[n];
        pair<ll,ll>p[n];
        fo(i,n){
            ll x,y;
            cin>>x>>y;
            a[i]=x,b[i]=y;
            p[i]=make_pair(x,y);
        }
        sort(a,a+n);
        sort(b,b+n);
        sort(p,p+n);
        ll ans=fac[n]+mod*1000000;
        ll temp1=1,t1=1;
        fo(i,n-1){
            if(a[i+1]==a[i])t1++;
            else{
                temp1*=fac[t1]%mod;
                temp1%=mod;
                t1=1;
            }
        }
        temp1*=fac[t1];
        temp1%=mod;
        ans-=temp1;
         temp1=1,t1=1;
        fo(i,n-1){
            if(b[i+1]==b[i])t1++;
            else{
                temp1*=fac[t1]%mod;
                temp1%=mod;
                t1=1;
            }
        }
        temp1*=fac[t1]%mod;
        temp1%=mod;
        ans-=temp1;
         temp1=1,t1=1;
        fo(i,n-1){
            if(p[i+1].first==p[i].first && p[i+1].second==p[i].second)t1++;
            else{
                temp1*=fac[t1]%mod;
                temp1%=mod;
                t1=1;
            }
            if(p[i+1].first<p[i].first || p[i+1].second<p[i].second)flag=1;
        }
        temp1*=fac[t1]%mod;
        temp1%=mod;
        if(flag!=1)ans+=temp1;
        
        cout<<ans%mod;
        
    }

    return 0;
}