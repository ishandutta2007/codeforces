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
        ll n1,n2,n3;
        cin>>n1>>n2>>n3;
        ll a1[n1],a2[n2],a3[n3];
        ll s[3]={0,0,0}; ll mini[3];
        fo(i,3)mini[i]=1e9;
        fo(i,n1){cin>>a1[i]; s[0]+=a1[i]; mini[0]=min(mini[0],a1[i]);};
        fo(i,n2){cin>>a2[i]; s[1]+=a2[i]; mini[1]=min(mini[1],a2[i]);};
        fo(i,n3){cin>>a3[i]; s[2]+=a3[i]; mini[2]=min(mini[2],a3[i]);};
        sort(mini,mini+3);
        sort(s,s+3);
        cout<<max(s[2]+s[1]-s[0], s[0]+s[2]+s[1]- 2*mini[0]-2*mini[1]);






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}