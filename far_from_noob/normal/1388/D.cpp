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

 vll vec[200005];
 ll h[200005];
ll isdone[200005];
 void dfs(ll node) {
    fo(i,vec[node].size()){
        h[vec[node][i]]=h[node]+1;
        dfs(vec[node][i]);
    }
 }
vll vans;
void prnt(ll node){
    isdone[node]=1;
    vans.pb(node);
    //cout<<node<<endl;
    fo(i,vec[node].size()){
        //cout<<node<<" "<<vec[node][i]<<endl; 
        if(isdone[vec[node][i]]==0)prnt(vec[node][i]);
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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;

        ll a[n+1],b[n+1];
        fo(i,n)cin>>a[i+1];
        fo(i,n)cin>>b[i+1];
        ll count[n+1];
        fo(i,n+1)count[i]=0,isdone[i]=0;
        fo1(i,n)if(b[i]!=-1){vec[b[i]] .pb(i); }
        fo1(i,n)if(b[i]==-1){ h[i]=0; dfs(i);}
        vector<pll >p;
        fo1(i,n){p.pb(mp(h[i], i)) ;}
        sort(all(p));
        queue<ll>q;
        for(int i=n-1;i>=0;i--)q.push(p[i].se);
        
        //fo1(i,n)if(count[i]==0)q.push(i);
        ll ans=0;
        vll v;
        ll is[n+1];
        fo(i,n+1)is[i]=0;

        while(q.size()){
            ll node=q.front();
            q.pop();
            //cout<<node<<" " <<h[node]<<endl;

            if(a[node]>0 && b[node]!=-1){
                a[b[node]]+=a[node];
            }
            else prnt(node);
            //if(b[node]!=-1 )if(is[b[node]]==0){q.push(b[node]); is[b[node]]=1;}
            ans+=a[node];
            v.pb(node);
        }
        cout<<ans<<endl;
        fo(i,vans.size())cout<<vans[vans.size()-1-i]<<" "; 





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}