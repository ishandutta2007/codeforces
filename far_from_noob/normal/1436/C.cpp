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
    t=1;
    while(t--){
        cin>>n;
        ll x,pos;
        cin>>x>>pos;
        ll fac[100005];
        ll infac[100005];
        fac[0]=1;
        fo(i,100000){
        fac[i+1]=fac[i]*(i+1)%mod;
        }
         infac[0]=1;
        infac[1]=1;
        for(int i=2;i<100002;i++){
            infac[i]=infac[i-1]*power(i,mod-2)%mod;
        }
        ll ans=1;
        ll l=0,r=n;
        ll aa=0,bb=0;

        while(l<r){
            ll mid=(l+r)/2;
            
            if(pos>=mid){l=mid+1; if(mid!=pos)aa++;}
            else {r=mid; bb++;}
            //cout<<l<<" "<<r<<endl;
        }
        //cout<<aa<<bb;
        ans*= fac[n-1-aa-bb];
        ans*=( (fac[x-1] *infac[x-1-aa]%mod))%mod;
        ans%=mod;
        ans*=( (fac[n-x] *infac[n-x-bb]%mod))%mod;
        cout<<ans%mod;







        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}