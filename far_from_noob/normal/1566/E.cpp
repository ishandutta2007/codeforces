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
vll v[200005]; ll par[200005],deg[200005],h[200005];

void dfs(ll node, ll root){
    deg[node]=0;
    fo(i,v[node].size()){
        if(v[node][i]==root)continue;
        deg[node]++;
        par[v[node][i]]=node;
        h[v[node][i]]=h[node]+1;

        dfs(v[node][i],node);
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
        cin>>n;
        fo(i,n+1){v[i].clear(); par[i]=-1;}

        fo(i,n-1){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }

        h[1]=0;
        par[1]=1;
        dfs(1,1);

        priority_queue<pll>q;
        
        fo1(i,n){
            //cout<<h[i]<<" ";
            q.push(mp(h[i],i));
        }
        //cout<<endl;

        map<ll,ll>ifused;
        ll ans=1;
        while(q.size()>0){
            pll p = q.top();
            //cout<<p.fi<<endl;
            q.pop();
            if(p.fi == 0)break;
            if(ifused[p.se] ==1)continue;
            ll node = p.se;
            ll bud = par[node];
            //cout<<node<< " "<<bud<<endl;
            ans+= deg[bud]-1;
            ifused[bud]=1;
            deg[par[bud]]--;
            fo(i,v[bud].size()){if(v[bud][i]!=par[bud])ifused[v[bud][i]]=1;}
        }
        cout<<ans<<endl;



        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}