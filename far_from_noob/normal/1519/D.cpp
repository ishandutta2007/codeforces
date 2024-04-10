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
ll dp[5005][5005];
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
        ll a[n+1],b[n+1];
        fo1(i,n)cin>>a[i];
        fo1(i,n)cin>>b[i];
        ll val[n+2];
        val[0]=0;val[n+2]=0;
        fo1(i,n)val[i]=a[i]*b[i];
        fo1(i,n)val[i]+=val[i-1];
        ll ans= val[n];
        //cout<<ans<<endl;
        fo(diff,n)for(int j=1;j<=n-diff;j++){
            if(diff==0)dp[j][j]=ans;
            else if(diff==1){
                //if(j==4&& diff == 1)cout<<val[n]<<endl;
                dp[j][j+1] = val[n] - a[j]*b[j]-a[j+1]*b[j+1] + a[j]*b[j+1]+a[j+1]*b[j];
            }
            else{
                dp[j][j+diff]= dp[j+1][j+diff-1] - a[j]*b[j]-a[j+diff]*b[j+diff] + a[j]*b[j+diff]+a[j+diff]*b[j];
            }
            ans=max(ans, dp[j][j+diff]);
        }
        //cout<<dp[4][5]<<endl;
        cout<<ans;






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}