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
ll is[200005];
map<pll,ll>m1;
ll cc1,cc2;
void dfs(ll node){
    if(is[node]==1)cc2++;
    cc1++;
    fo(i,v[node].size()){
        if(is[v[node][i]] ==0){
            if(m1[mp(node, v[node][i])] == 1){
                is[v[node][i]] =is[node];
            }
            else is[v[node][i]]=3-is[node];
            dfs(v[node][i]);
        }
        else{
            if(m1[mp(node, v[node][i])] == 1){
                if(is[node] != is[v[node][i]])flag=1;
            }
            else if(is[node] == is[v[node][i]])flag=1;
        }
    }
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
        cin>>n>>m;
        m1.clear();
        fo(i,n+1){v[i].clear() ; is[i]=0;}
        flag=0;
        fo(i,m){
            ll a,b; string c;
            cin>>a>>b>>c;
            v[a].pb(b);
            v[b].pb(a);
            ll kk=1;if(c[0]=='i')kk=2;

            if(m1[mp(a,b)] >0 && m1[mp(a,b)] !=kk){flag=1; }
            m1[mp(a,b)]=kk;
            m1[mp(b,a)]=kk;
        }
        
        ll ans=0;
        //cc=0;
        fo1(i,n){
            if(is[i]==0){
                is[i]=1;
                cc1=0,cc2=0;
                dfs(i);
                ans+=max(cc1-cc2,cc2);
            }
        }
        if(flag)cout<<-1<<endl;
        else cout<<ans<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}