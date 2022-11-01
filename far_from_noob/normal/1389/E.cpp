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
    vector<ll>prime;
    map<ll ,ll>ifused;
    for(ll i=2;i<200005;i++){
        if(ifused[i]==1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=200000){
            ifused[j]=1;
            j+=i;
        }
    }
    cin>>t;
    //t=1;
    while(t--){
        ll m,d,w;
        cin>>m>>d>>w;
        if((d-1)%w==0){
            ll val=min(d,m);
            //cout<<endl;
            cout<<val*(val-1)/2<<endl; 
            continue;
        }
        ll val=d-1;
        vll v;
        for(int temp=0; prime[temp]< 100000; temp++){   
            while(val%prime[temp]==0){
                //cout<<val<<prime[temp];
                v.pb(prime[temp]);
                val/=prime[temp];
            }
        }
        if(val!=1)v.pb(val);
        fo(i,v.size()){
            //cout<<v[i];
            if(w%v[i]==0)w/=v[i];
        }
        m=min(m,d);
        //cout<<w<<endl;
        ll kk=m/w;
        ll vv=m%w;
        ll ans= w*kk*(kk-1)/2 + vv*kk;
        cout<<ans<<endl;






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}