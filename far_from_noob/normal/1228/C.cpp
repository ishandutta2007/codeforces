#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
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
    vector<ll>prime;
    map<ll ,ll>ifused;
    for(ll i=2;i<1000000;i++){
        if(ifused[i]==1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=1000000){
            ifused[j]=1;
            j+=i;
        }
    }
    //cin>>t;
    t=1;
    while(t--){
        ll x;
        cin>>x>>n;
        vector<ll>v;
        ll temp=0;
        map<ll,ll>m1;
        while(1){
            if(x%prime[temp] ==0){
                if(m1[prime[temp]]==0){
                    v.pb(prime[temp]);
                }
                m1[prime[temp]]++;
                x=x/prime[temp];
            }
            else temp++;
            if(prime[temp]>100000)break;
        }
        if(x>100000)v.pb(x);
        ll ans=1;
        fo(i,v.size()){
            for(ll j=1;;j++){
                if(n/(ll)pow(v[i],j) ==0)break;
                else {
            ans*=po( (v[i]) , n/(ll)pow(v[i],j) ,1,1, (v[i]));
            ans%=mod;
                }
            }
        }
        cout<<ans;
    }

    return 0;
}