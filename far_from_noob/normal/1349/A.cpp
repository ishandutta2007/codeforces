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
#define vll vector<ll>
#define pll pair<ll,ll>
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// ordered_set s ; s.order_of_key(a) -- no. of elements strictly less than a
// s.find_by_order(i) -- itertor to ith element (0 indexed)
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
ll gcd(ll a , ll b){ if(b > a) return gcd(b , a) ; if(b == 0) return a ; return gcd(b , a%b) ;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef NOOBxCODER
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else 
    #define NOOBxCODER 0
    #endif
    //cin>>t;
    vector<ll>prime;
    map<ll ,ll>ifused;
    for(ll i=2;i<300005;i++){
        if(ifused[i]==1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=300000){
            ifused[j]=1;
            j+=i;
        }
    }
    t=1;
    while(t--){
        cin>>n;
        ll a[n];
        fo(i,n)cin>>a[i];
        vll v[200005];
        map<ll,ll>po;
        fo(j,2){
            ll kk=a[j];
            ll temp=0;
            for(int i=0; prime[i]<200000 ;i++){
                ll cc=0;
                while(kk%prime[i]==0){
                    kk/=prime[i];
                    cc++;
                }
                v[j].pb(cc);
            }
        }
        ll ans=1;
        fo(i,v[0].size()){
            if(v[0][i]>0 || v[1][i]>0){
                ll a1=min(v[0][i], v[1][i]),a2=max(v[0][i], v[1][i]);
                //cout<<prime[i]<<a2<<endl;
                for(int j=2;j<n;j++){
                    ll cc=0;
                    while(a[j]%prime[i] ==0){
                        a[j]/=prime[i];
                        cc++;
                    }
                    if(cc<=a1){
                        a2=a1 ; a1=cc;
                    }
                    else if(cc<a2){
                        a2=cc;
                    }
                }
                ans*=(ll)pow(prime[i] , a2);
            }
        }
        cout<<ans;






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}