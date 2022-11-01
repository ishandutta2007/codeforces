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
ll mod = 998244353;
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
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
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
        ll k1;
        cin>>n>>k1;
        ll dp[n+1][n+1];
        fo1(i,n)fo1(j,n)dp[i][j]=0;
        ll lasttemp=0;
        ll dpsum[n+1];
        dpsum[0]=0;
        fo1(k,n){
            fo1(i,n)fo1(j,n)dp[i][j]=0;
            ll temp=0;
            fo1(i,n){
                if(i==1){dp[i][1]=2;continue;}
                ll temp=0;
                fo1(j,k)temp+=dp[i-1][j];
                temp%=mod;
                dp[i][1]=temp;
                for(int j=2;j<=k;j++){
                    dp[i][j]=dp[i-1][j-1];
                }
            }
            fo1(i,n)temp+=dp[n][i];
            temp%=mod;
            dpsum[k]=temp;

        }
        ll ans=0;
        
        // fo1(i,n){
        //     ll temp=0;ll dpsum[n+1];
        //     fo1(j,n)temp+=dp[n][j][i];
        //     if(i==1)dpsum[i]=temp%mod;
        //     else dpsum[i]=(mod+temp-lasttemp)%mod;
        //     lasttemp=temp;
        //     //acout<<dpsum[i]<<endl;;
        // }
        fo1(i,n){
            ll temp=0;
            while(i*temp<k1){
                temp++;
                if(temp==n+1)break;
            }
            temp--;
            if(temp==0)continue;
            ll a1=(dpsum[i]-dpsum[i-1]+mod)%mod;
            //fo1(j,n)a1+=dp[n][j][i],a1%=mod;
            ll a2=dpsum[temp];
            //fo1(j,n)a2+=dp[n][j][temp],a2%=mod;
            ll kk =a1*a2%mod;
            ll m1=mod-2;
            kk= kk * po( 2, m1,1,1,2 ) % mod;
            ans+=kk;
            ans%=mod;

        }
        cout<<ans;




        
        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}