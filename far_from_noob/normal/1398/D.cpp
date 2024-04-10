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
ll r,g,b;
ll red[200],green[200],blue[200];
ll dp[201][201][201];

ll find(ll i, ll j,ll k){
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    //return 1;
    ll ans=0;
    if(i>0 && j>0)ans=max(ans, find(i-1,j-1,k)+ red[i-1]*green[j-1]);
    if(j>0 && k>0)ans=max(ans, find(i,j-1,k-1)+ blue[k-1]*green[j-1]);
    if(i>0 && k>0)ans=max(ans, find(i-1,j,k-1)+ red[i-1]*blue[k-1]);
    dp[i][j][k]=ans;
    return ans;

}

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
        ll r,g,b;
        cin>>r>>g>>b;
        fo(i,r+1)fo(j,g+1)fo(k,b+1)dp[i][j][k]=-1;
        fo(i,r)cin>>red[i];
        fo(i,g)cin>>green[i];
        fo(i,b)cin>>blue[i];
        sort(red,red+r);
        sort(green,green+g);
        sort(blue,blue+b);
        cout<<find(r,g,b);




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}