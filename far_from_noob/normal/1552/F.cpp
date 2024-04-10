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
ll mod=998244353;
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
        ll x[n],y[n],p[n];
        fo(i,n)cin>>x[i]>>y[i]>>p[i];
        map<ll,ll>m1;
        fo(i,n)m1[x[i]]=i;

        set<ll>s;
        fo(i,n)s.insert(x[i]);
        ll ans[n+1];
        ans[0]=0;
        fo(i,n){
            auto it=(s.lower_bound(y[i]));
            int j  = m1[(*it)];
            ans[i+1]= x[i]-y[i];
            if(i==j){ans[i+1]+=ans[i]; continue;}
            //cout<<j<<i<<endl;
            ans[i+1]+= ans[i]-ans[j]+mod;

            ans[i+1]+=ans[i];
            ans[i+1]%=mod;

            //cout<<ans[i+1]<<endl;
        }
        //cout<<ans[2]<<endl;
        ll final[n];final[0]=0;
        fo(i,n){
            if(i==0){
                if(p[i]==0){ final[i]=x[i];}
                else{ final[i]= x[i]+ ans[i+1]-ans[i] + mod; }
            }

            else{
                if(p[i]==0){final[i]=x[i]-x[i-1] + final[i-1]; }
                else{final[i]=x[i]-x[i-1] + final[i-1]+ ans[i+1]-ans[i]+mod; }
            }

            final[i]%=mod;
        }
        cout<<(1+final[n-1])%mod;






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}