#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
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
        ll a[39];
        fo(i,39)a[i]=0;
        m=n;
        for(int i=38;i>=0;i--){
            if(n > (ll)pow(3,i))a[i]=1,n=n-(ll)pow(3,i);
        }
        ll tsum=0;
        for(int i=38;i>=0;i--){
            tsum+=(ll)pow(3,i) * a[i];
        }
        if(tsum==m)cout<<tsum<<endl;
        
        else {
            flag=0;
            tsum=0;
            fo(i,39){
                if(a[i]==0){if(flag==0)a[i]=1;flag=1;}
                if(flag==1)tsum+=(ll)pow(3,i) * a[i];
            }
             cout<<tsum<<endl;   
        }
    }

    return 0;
}