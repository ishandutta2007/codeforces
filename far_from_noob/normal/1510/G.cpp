//Utkarsh.25dec
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define deb(x) cerr<<#x<<' '<<'='<<' '<<x<<'\n'
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// ordered_set s ; s.order_of_key(val)  no. of elements strictly less than val
// s.find_by_order(i)  itertor to ith element (0 indexed)
typedef vector<vector<ll>> matrix;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=500023;
bool vis[N];
vector <int> adj[N];
ll par[N];
int mark[N];
ll n,k;
vl seq;
int good;
int height[N];
int taken[N];
void foo(int curr)
{
    vis[curr]=1;
    if(curr==1)
    {
        height[curr]=1;
    }
    for(auto it:adj[curr])
    {
        if(vis[it])
            continue;
        height[it]=height[curr]+1;
        foo(it);
    }
}
void dfs(int curr)
{
    if(k==0)
        return;
    seq.pb(curr);
    if(mark[curr]==1 && taken[curr]==0)
    {
        good--;
    }
    if(taken[curr]==0)
    {
        taken[curr]=1;
        k--;
    }
    if(k==0)
        return;
    if(k<=good)
    {
        while(true)
        {
            if(mark[curr])
                break;
            curr=par[curr];
            seq.pb(curr);
        }
        for(auto it:adj[curr])
        {
            if(it==par[curr])
                continue;
            if(mark[it])
                dfs(it);
        }
    }
    else
    {
        for(auto it:adj[curr])
        {
            if(it==par[curr])
                continue;
            if(mark[it])
                continue;
            if(k<=good)
                break;
            dfs(it);
            if(k<=good)
                break;
            seq.pb(curr);
        }
        for(auto it:adj[curr])
        {
            if(it==par[curr])
                continue;
            if(mark[it])
                dfs(it);
        }
    }
}
void solve()
{
    seq.clear();
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        vis[i]=0;
        par[i]=0;
        mark[i]=0;
        height[i]=0;
        taken[i]=0;
    }
    for(int i=2;i<=n;i++)
    {
        ll c;
        cin>>c;
        adj[i].pb(c);
        adj[c].pb(i);
        par[i]=c;
    }
    if(n==1)
    {
        cout<<0<<'\n';
        cout<<1<<'\n';
        return;
    }
    foo(1);
    int maxi=1;
    int node=0;
    for(int i=2;i<=n;i++)
    {
        if(maxi<height[i])
        {
            maxi=height[i];
            node=i;
        }
    }
    while(node!=1)
    {
        mark[node]=1;
        node=par[node];
    }
    mark[1]=1;
    good=maxi;
    dfs(1);
    cout<<(seq.size()-1)<<'\n';
    for(auto it:seq)
        cout<<it<<' ';
    cout<<'\n';
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    int t=0;
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}