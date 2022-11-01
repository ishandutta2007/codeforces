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
        ll a[n];
        fo(i,n)cin>>a[i];

        ll val [n][n];
        ll presum[n];
        presum[0]=a[0];
        fo1(i,n-1){
            if(i%2==0)presum[i]=presum[i-1]+a[i];
            else presum[i]=presum[i-1]-a[i];
        }
        fo(i,n){
            if(i%2==0)continue;
            val[i][i]= -1*a[i];
            ll curr= -1*a[i];
            for(int j=i+1;j<n;j++){
                if(j%2==0){
                    val[i][j]=val[i][j-1];
                    curr+=a[j];
                }
                else{
                    curr-=a[j];
                    val[i][j]= min(val[i][j-1], curr);
                }
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            if(i%2==1)continue;
            for(int j=i+1;j<n;j++){
                if(j%2==0)continue;
                if(j== i+1)ans+=min(a[i],a[j]);
                else{
                    ll mini  = val[i+1][j-1];
                    //cout<<mini<<endl;
                    ll kk = presum[j-1]-presum[i];
                    //cout<<kk<<endl;
                    kk-=mini; 
                    //cout<<kk<<endl;
                    ans+= max(min(a[i] + mini+1 , a[j]-kk+1), 0);
                }
                //cout<<ans<<endl;
            }
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}