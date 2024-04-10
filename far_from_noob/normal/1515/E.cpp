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
ll ans[401][401];
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
    cin>>n>>mod;
    ll fac[1005];
    ll infac[1005];
    fac[0]=1;
    fo(i,1000){
        fac[i+1]=fac[i]*(i+1)%mod;
    }
    infac[0]=1;
    infac[1]=1;
    for(int i=2;i<1002;i++){
        infac[i]=infac[i-1]*power(i,mod-2)%mod;
    }
    ll ncj[401][401];
    fo(i,401)fo(j,401)if(i>=j)ncj[i][j] = fac[i]*infac[j]%mod *infac[i-j]%mod;

    while(t--){
        fo(i,401)fo(j,401)ans[i][j]=0;
        ans[0][0]=1;
        fo1(i,n)ans[i][0]=power(2,i-1);
        for(int j = 1;j<=n;j++){
            fo1(i,n){
                for(int l=2;l<=i-1;l++){
                    ans[i][j]+= ans[l-1][0]*ans[i-l][j-1]%mod*ncj[l-1 + i-l -j+1][l-1] %mod;
                    //if(i==3 && j==1)cout<<l<<" "<<ans[l-1][0]<< " "<<ans[i-l][j-1]<<endl;
                    ans[i][j]%=mod;
                }
            }
        }
        ll sum=0;
        //cout<<ans[3][1]<<endl;
        fo(i,n+1)sum+= ans[n][i],sum%=mod;
        cout<<sum<<endl;
        





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}