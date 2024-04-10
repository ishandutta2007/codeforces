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
        ll a[100];
        fo(i,100){
            a[i]=128*i;
        }
        ll b[100];
        fo(i,100)b[i]=i+1;
        cout<<"? ";
        cout << flush;
        fo(i,100)cout<< a[i]<< " ";
        cout<<endl;
        cout << flush;
        cin>>n;
        n=n%128;
         cout<<"? ";
         cout << flush;
        fo(i,100)cout<< b[i]<< " ";
        cout<<endl;
        cout << flush;
        cin>>m;
        ll l=m%128;
        n=n+ m-l ;
        cout<<"! "<<n;
        cout << flush;
        
        
        
    }

    return 0;
}