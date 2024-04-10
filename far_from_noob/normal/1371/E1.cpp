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
        ll p;
        cin>>n>>p;
        ll a[n];
        fo(i,n)cin>>a[i];
        ll count[n];
        fo(i,n)count[i]=0;
        vll ans;
        fo1(x,2000){
            ll ff=0;
            fo(i,n)count[i]=0;
            fo(i,n){
                if(a[i]<=x)count[0]++;
                else if(a[i]-x>=n){ff=1; break;}
                else count[a[i]-x]++;
            }
            if(ff==1)continue;
            ll temp=0;
            //cout<<x<<" ";
            for(int i=n-1;i>=0;i--){
                if(count[i]==0)continue;
                if(temp+ count[i]> n-i){ ff=1; break;}
                ll v1=0,v2=0,v3=0;
                ll kk=p;
                while((n-i-temp)>=kk){
                    v1+=(n-i-temp)/kk;
                    kk*=p;
                }
                kk=p;
                ll val=n-i-temp-count[i];
                while((val)>=kk){
                    v2+=(val)/kk;
                    kk*=p;
                }
                
                temp+=count[i];
                //cout<<i<<" "<<v1<<" "<<v2<< " "<<v3<<endl;
                if(v1!=v2+v3){ff =1; break;}
            }
            //cout<<x<<" "<<ff<<" ";
            if(ff==1)continue;

            ans.pb(x);
        }
        cout<<ans.size()<<endl;
        fo(i,ans.size())cout<<ans[i]<<" ";





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}