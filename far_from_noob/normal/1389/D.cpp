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
    //t=1;
    while(t--){
        cin>>n>>k;
        ll l1,l2,r1,r2;
        cin>>l1>>r1>>l2>>r2;
        ll val=0;
        ll given=0;
        if(l2>=r1){
            val = l2-r1;
        }
        else if(l1>=r2){
            val = l1-r2;
        }
        else{
            given=min(r1,r2)-max(l1,l2);
        }
        //cout<<val<<given<<endl;
        if(given*n >= k){cout<<0<<endl; continue;}
        k-= given*n;
        //given=0;
        ll node= max(r2,r1)-min(l2,l1) - given;
        if(node*n < k ){
            cout<<(val + node)*n + (k-node*n)*2<<endl;
        }
        else{
            ll kk =k/(node);
            ll ans= (val + node)*kk;
            //cout<<k<<" "<<node<< " "<<val<<endl;
            if(k%node!=0){
                if(kk!=0)ans+=min(2*(k%node), val+ k%node);
                else ans+=(val+ k%node);

            }
            cout<<ans<<endl;
        }






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}