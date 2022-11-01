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
int dp[5000][5001];
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
        fo(i,n)fo(j,n+1)dp[i][j]=-1;
        //dp[0][0]=1;
        for(int i=min(a[0],n); i>=0;i--){
            if(i==min(a[0],n)){if(a[0]<=n)dp[0][i]=a[0]; else dp[0][i]=1+ a[0];}
            else{
                dp[0][i]=min(dp[0][i+1], i+1);
            }
            //cout<<dp[0][i]<<" "; 
        }
        for(int i=1;i<n;i++){
            for(int j=min(a[i],n); j>=0;j--){
                if(j==min(a[i],n)){
                    if(dp[i-1][j]==-1)dp[i][j]=dp[i-1][a[i-1]]+a[i]-a[i-1];
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
                else{
                    if(dp[i-1][j]==-1)dp[i][j]=min(dp[i-1][a[i-1]]+j-a[i-1]+1 , dp[i][j+1] );
                    else{
                        dp[i][j]=min(dp[i-1][j]+1 ,  dp[i][j+1]);
                    }
                }
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        ll ans=mod;
        fo(i,n+1){
            if(dp[n-1][i]!=-1)ans=min(ans, dp[n-1][i]);
        }
        cout<<ans;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}