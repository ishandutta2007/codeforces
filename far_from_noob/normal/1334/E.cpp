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
ll gcd(ll a , ll b){ if(b > a) return gcd(b , a) ; if(b == 0) return a ; return gcd(b , a%b) ;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll fac[1005];
    ll infac[1005];
    fac[0]=1;
    fo(i,1000){
        fac[i+1]=fac[i]*(i+1)%mod;
    }
    infac[0]=1;
    infac[1]=1;
    for(int i=2;i<1002;i++){
        infac[i]=infac[i-1]*po(i,mod-2,1,1,i)%mod;
    }
    //cin>>t;
    t=1;
    while(t--){
        ll d;
        cin>>d;
        vector<ll>factors;
        ll kk=(ll)sqrt(d);
        ll count=0;
        for(int i=2;i<=kk+1;i++){
            count++;
            if(d%i==0){
                factors.pb(i);
                while(d%i==0)d/=i;
            }
        }
        if(d!=1)factors.pb(d);
        cin>>q;
        fo(l,q){
            ll a,b;
            cin>>a>>b;
            ll kk =gcd(a,b);
            a=a/kk;
            b=b/kk;
            ll ans=1;
            ll suma=0;
            fo(i,factors.size()){
                ll temp=0;
                while(b%factors[i]==0){
                    b/=factors[i];
                    temp++;
                }
                ans*=infac[temp];
                ans%=mod;
                suma+=temp;
            }
            ans*=fac[suma];
            ans%=mod;
            //cout<<ans;
            suma=0;
            fo(i,factors.size()){
                ll temp=0;
                while(a%factors[i]==0){
                    a/=factors[i];
                    temp++;
                }
                ans*=infac[temp];
                ans%=mod;
                suma+=temp;
            }
            ans*=fac[suma];
            ans%=mod;
            cout<<ans<<endl;

        }
        //cout<<count;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

    return 0;
}