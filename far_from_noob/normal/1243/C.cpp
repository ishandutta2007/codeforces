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
    //cin>>t;
    t=1;
    vector<ll>prime;
    map<ll ,ll>ifused;
    for(ll i=2;i<1000100;i++){
        if(ifused[i]==1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=1000100){
            ifused[j]=1;
            j+=i;
        }
    }
    while(t--){
        cin>>n;
        m=n;
        ll temp=0;
        if(n==1){cout<<1;break;}
        while(prime[temp]<=1000000 ){
            if(n%prime[temp]==0){
                while(n%prime[temp]==0){
                    n=n/prime[temp];
                }
                if(n==1)cout<<prime[temp];
                else cout<<1;
                break;
            }
            else temp++;
        }
        if(n==m)cout<<n;
    }

    return 0;
}