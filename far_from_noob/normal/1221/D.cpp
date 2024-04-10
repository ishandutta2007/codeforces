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
        ll a[n],b[n];
        fo(i,n){
            cin>>a[i]>>b[i];
        }
        ll x,y,z=2*b[0];
        x=0,y=b[0];
        fo(i,n-1){
            ll c=x,d=y,e=z;
            if(a[i+1]== a[i])x=min(e,d);
            else if(a[i+1]==a[i]+1)x=min(c,e);
            else if(a[i+1]==a[i]+2)x=min(d,c);
            else x=min(min(e,d),c);
            if(a[i+1]+1== a[i])y=min(e,d)+b[i+1];
            else if(a[i+1]+1==a[i]+1)y=min(c,e)+b[i+1];
            else if(a[i+1]+1==a[i]+2)y=min(d,c)+b[i+1];
            else y=min(min(e,d),c)+b[i+1];
            if(a[i+1]+2== a[i])z=min(e,d)+b[i+1]*2;
            else if(a[i+1]+2==a[i]+1)z=min(c,e)+b[i+1]*2;
            else if(a[i+1]+2==a[i]+2)z=min(d,c)+b[i+1]*2;
            else z=min(min(e,d),c)+b[i+1]*2;
            
        }
cout<<min(x,y)<<endl;
    }

    return 0;
}