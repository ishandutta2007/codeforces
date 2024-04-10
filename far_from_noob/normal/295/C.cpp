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
int mod=1000000007;
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
    ll fac[10005];
    ll infac[10005];
    fac[0]=1;
    fo(i,10004){
        fac[i+1]=fac[i]*(i+1)%mod;
    }
    infac[0]=1;
    infac[1]=1;
    for(int i=2;i<10002;i++){
        infac[i]=infac[i-1]*power(i,mod-2)%mod;
    }
    while(t--){
        cin>>n>>k;
        ll a=0,b=0;
        fo(i,n){
            cin>>m;
            if(m==50)a++;
            else b++;
        }
        //cout<<a<<b<<endl;
        ll dp[201][a+1][b+1];
        fo(i,201)fo(j,a+1)fo(l,b+1)dp[i][j][l]=0;
        dp[0][a][b]=1;
        ll ncr[51][51];
        fo(i,51)fo(j,i+1){
            ncr[i][j]= fac[i]*(infac[j]*infac[i-j]%mod)%mod;
        }
        fo1(l,200){
            fo(i,a+1)fo(j,b+1)fo(i1,a+1)fo(j1, b+1){
                if(i >= a- i1 && j >= b- j1 && !( i == a- i1 && j == b- j1) ){
                    if((i-a+i1)*50 + (j-b+j1)*100 <=k){
                        ll k1=(i-a+i1), k2=(j-b+j1);
                        
                        dp[l][i1][j1]+= dp[l-1][i][j]*(ncr[i][k1]*ncr[j][k2]%mod)%mod;
                        dp[l][i1][j1]%=mod;
                    }
                }
            }
        }
        ll val=-1;
        ll ans=0;
        for(int i=1;i<200;i+=2){
            if(dp[i][a][b]!=0){
                val=i;
                ans=dp[i][a][b];
                break;
            }
        }
        cout<<val<<endl;
        cout<<ans<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}