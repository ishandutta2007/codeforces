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
    cin>>t;
    ll fac[200005];
    ll infac[200005];
    fac[0]=1;
    fo(i,200003){
        fac[i+1]=fac[i]*(i+1)%mod;
    }
    infac[0]=1;
    infac[1]=1;
    for(int i=2;i<200002;i++){
        infac[i]=infac[i-1]*power(i,mod-2)%mod;
    }
    //t=1;
    while(t--){
        cin>>n;
        ll l , r;cin>>l>>r;
        l = 1-l;
        r = r-n;
        if(l>r)swap(l,r);
        ll val=0;
        if(n%2==0){
            val = fac[n]*infac[n/2]%mod*infac[n/2]%mod;
        }
        else{
            val = 2* fac[n]*infac[n/2]%mod*infac[n  -  n/2]%mod;
        }
        ll ans= val *l%mod;
        for(ll x = 1 ; x<n;x++){
            int low = x; 
            int high = max(0,x -r+l);
            if(n%2==0){
                if(low>n/2)break;
                ans+= fac[n-low - high]*infac[n/2 - low]%mod*infac[n/2 -high]%mod;
                ans%=mod;
            } 
            else{
                if(low> n/2 + 1)break;
                if(low == n/2+1){if(low!=high)ans++;}
                else{
                    ans+= fac[n-low-high]*infac[n/2 - low]%mod*infac[n- n/2 -high]%mod;
                    ans+= fac[n-low-high]*infac[n - n/2 - low]%mod*infac[ n/2 -high]%mod;
                    ans%=mod;
                }
                ans%=mod;
            }
            //cout<<ans<<endl;
        }

        cout<<ans<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}