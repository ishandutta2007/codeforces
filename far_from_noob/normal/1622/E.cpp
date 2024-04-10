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
        cin>>n>>m;
        ll x[n];fo(i,n)cin>>x[i];
        string a[n];
        fo(i,n)cin>>a[i];

        ll val = pow(2,n);
        //cout<< (3 & (1<<2));
        ll arr[m];

        ll ans=-2;
        fo(i,val){
            int is[n];
            fo(j,n)is[j]=0;
            ll temp=0;
            fo(j,n)if((i &  (1<< j )) == 0){
                is[j]=1; temp+= x[j];
            } else temp-=x[j];

            //fo(j,n)cout<<is[j]<<" ";cout<<endl;

            pll cnt[m];fo(j,m)cnt[j]=mp(0,j);

            fo(j,m)fo(l,n)if(a[l][j] =='1'){if(is[l]==0)cnt[j].fi++; else cnt[j].fi--; }

            sort(cnt , cnt+m);
            ll curr=0;

            fo1(j,m)curr+= j*cnt[j-1].fi;

            //ans= max(ans, curr+ temp);
            //cout<<curr<<endl;
            if(ans <curr+ temp){

                ans= curr+ temp;
                fo(j,m){arr[cnt[j].se] = j+1; }
            }
        }
        //cout<<ans<<endl;
        fo(i,m)cout<<arr[i]<<" ";cout<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}