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
vll v[300005];
ll m1[300005],mark[300005];
ll num;
void dfs(ll node){
    fo(i,v[node].size()){
        if(mark[v[node][i]]==0){
            mark[v[node][i]]=1;
            num++;
            dfs(v[node][i]);
        }
    }
}
void dfs2(ll node){
    if(m1[node] == 1) fo(i,v[node].size()){
        if(m1[v[node][i]]==0){
            m1[v[node][i]]=3- m1[node];
            dfs2(v[node][i]);
        }
    }
    else{
        fo(i,v[node].size()){
            if(m1[v[node][i]]==0){
                ll kk =v[node][i];
                ll f=0;
                fo(j,v[kk].size())if(m1[v[kk][j]]==1)f=1;
                if(f==1){
                    m1[kk]=2;
                    dfs2(kk);
                }
                else{
                    m1[kk]=1;
                    dfs2(kk);
                }
            }
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
        cin>>n;
        fo(i,n+1){v[i].clear(); m1[i]=0;mark[i]=0;}
        cin>>m;
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        num=0;
        mark[1]=1;
        num++;
        dfs(1);
        if(num!=n){cout<<"NO"<<endl; continue;}
        m1[1]=1;
        dfs2(1);
        cout<<"YES"<<endl;
        vll ans;
        fo1(i,n)if(m1[i]==1)ans.pb(i);
        cout<<ans.size()<<endl;
        fo(i,ans.size())cout<<ans[i]<<" ";cout<<endl;






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}