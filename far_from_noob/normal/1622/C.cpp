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
        ll a[n];fo(i,n)cin>>a[i];
        //cin>>k;

        sort(a,a+n);

        ll sum=0;fo(i,n)sum+=a[i];
        if(sum<=k){cout<<0<<endl; continue;}

        ll suf[n+1];suf[n]=0;
        suf[n-1]=a[n-1];
        for(int i=n-2;i>0;i--)suf[i] = suf[i+1]+a[i];

        ll ans= 1e18;
        fo(i,n){
            if(i==0)ans = min(ans, sum-k);
            else{
                ll val = k- (suf[1] - suf[n-i]);
                //cout<<val<<endl;

                ll kk ;
                if(val>0)kk = (val +(i+1)*1e9) /(i+1)   - 1e9;
                else kk =   (val - i )/(i+1);
                //cout<<kk<<endl;
                //if(i==4) cout<<val<<" "<<kk<<" "<<ans<<endl;
                ans = min(ans, max(a[0]-kk ,0) + i);
                //if(ans== 6)cout<<i<< endl;


            }
        }
        cout<<ans<<endl;

        //cout<<(1  )/5;

        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}