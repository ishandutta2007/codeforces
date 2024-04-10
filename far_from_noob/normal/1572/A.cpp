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
vll v[200005];
ll ans;
ll h[200005];
map<ll,ll>is;

void dfs(ll node, ll don){
    h[node]=1;
    is[node]=1;
    fo(i,v[node].size()){
        if(is[v[node][i] ]  == 1)flag=-1;
        if(is[v[node][i]]==0)dfs(v[node][i], don);
        if(v[node][i] <node)h[node]=max(h[node], h[v[node][i]]);
        else h[node]=max(h[node], h[v[node][i]] +1 );
    }
    ans= max(ans,h[node]);
    is[node]=2;
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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n;
        fo(i,n+1){v[i].clear();is[i]=0;h[i]=0;}
        ans=0;flag=0;
        fo1(i,n){
            cin>>k;
            fo(j,k){
                cin>>m;
                v[i].pb(m);
            }
        }

        fo1(i,n){
            if(is[i]!=0)continue;

            dfs(i,i);
        }
        if(flag==-1)cout<<-1<<endl;
        else 
        cout<<ans<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}