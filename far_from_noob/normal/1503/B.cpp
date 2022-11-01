#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
//#define endl "\n"
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
        ll x=0,y=1;
        vector<pll>v1,v2;
        fo1(i,n)fo1(j,n){
            if((i+j)%2==0)v1.pb(mp(i,j));
            else v2.pb(mp(i,j));
        }
        ll  t1=0,t2=0;
        fo(i,n*n){
            cin>>m;
            if(t1<v1.size() && t2<v2.size()){
                if(m==1){
                    cout<<3<<" "<<v1[t1].fi<<" "<<v1[t1].se;

                    t1++;
                }
                else{
                    cout<<1<<" "<<v2[t2].fi<<" "<<v2[t2].se;

                    t2++;
                }
            }
            else if(t2==v2.size()){
                if(m==3){
                    cout<<2<<" "<<v1[t1].fi<<" "<<v1[t1].se;

                    t1++;
                }
                else{
                    cout<<3<<" "<<v1[t1].fi<<" "<<v1[t1].se;

                    t1++;
                }
            }
            else{
                if(m==1){
                    cout<<2<<" "<<v2[t2].fi<<" "<<v2[t2].se;

                    t2++;
                }
                else{
                    cout<<1<<" "<<v2[t2].fi<<" "<<v2[t2].se;

                    t2++;
                }
            }

            cout<<endl;
        }






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}