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
        cin>>n>>m;
        ll a[n],b[m];
        vll v;
        fo(i,n)cin>>a[i];
        fo(i,m)cin>>b[i];
        ll temp=m-1;
        for(int i=n-1;i>=0;i--){
            if(a[i]==b[temp]){v.pb(i); temp--;}
            if(temp==-1 )break;
        }
        flag=1;
        ll mini=1e12;
        if(v.size()!=m){cout<<0; break;}
        sort(all(v));
        temp=m-1;
        ll val=b[m-1];
        v.pb(mod);
        for(int i=n-1;i>=0;i--){
            mini=min(mini, a[i]);
            if(mini<val){flag=0;} 
            if(i== v[temp]){
                temp--;
                if(temp==-1){val=b[0]; temp=m;}
                else val=b[temp];
            }

        }
        if(flag==0){cout<<0 ;  return 0;}
        ll ans=1;
        for(int i=m-1;i>0;i--){
            ll temp=1;
            for(int kk = v[i]-1; kk>=0; kk--){
                if(a[kk]>= b[i])temp++;
                else break;
            }
            ans*=temp;
            ans%=mod;
        }
        cout<<ans;






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}