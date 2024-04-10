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
        cin>>n>>m>>k;
        if(k%2!=0){
            fo(i,n){fo(j,m)cout<<-1<<" ";cout<<endl;}
            break;
        }
        ll a[n][m-1];
        fo(i,n)fo(j,m-1)cin>>a[i][j];
        ll b[n-1][m];
        fo(i,n-1)fo(j,m)cin>>b[i][j];
        ll ans[n][m][k/2  +  1];
        fo(i,n)fo(j,m){
            ll mini=1e12;
            if(j>0)mini= min(mini, a[i][j-1]);
            if(j<m-1)mini=min(mini, a[i][j]);
            if(i>0)mini= min(mini, b[i-1][j]);
            if(i<n-1)mini=min(mini, b[i][j]);
            ans[i][j][1]=mini;
            //cout<<mini<<endl;

        }
        for(int val =2;val<=k/2;val++){
            fo(i,n)fo(j,m){
                ll mini =1e16;

                if(j>0)mini= min(mini, a[i][j-1] + ans[i][j-1][val-1]);
                if(j<m-1)mini=min(mini, a[i][j] + ans[i][j+1][val-1]);
                if(i>0)mini= min(mini, b[i-1][j]+ ans[i-1][j][val-1]);
                if(i<n-1)mini=min(mini, b[i][j] + ans[i+1][j][val-1]);
                ans[i][j][val]=mini;
            }
        }
        fo(i,n){fo(j,m)cout<<ans[i][j][k/2 ]*2 <<" "; cout<<endl;}





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}