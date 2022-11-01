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
vll node[200005];
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
        fo1(i,n)v[i].clear();
        fo(i,n)node[i].clear();
        cin>>m;
        ll dis[n+1];
        fo(i,n+1)dis[i]=-1;
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
        }
        node[0].pb(1);
        dis[1]=0;
        ll count=1;
        ll val=0;
        while(count<n){
            fo(i,node[val].size()){
                ll nod=node[val][i];
                fo(j,v[nod].size()){
                    if(dis[v[nod][j]]==-1){
                        dis[v[nod][j]]= val+1;
                        count++;
                        node[val+1].pb(v[nod][j]);
                    }
                }
            }
            val++;
        }
        //fo1(i,n)cout<<dis[i]<<" "; cout<<endl;
        ll ans[n+1];
        ans[1]=0;
        while(val>0){
            fo(j,node[val].size()){
                ll nod = node[val][j];
                //cout<<nod<<" ";
                ll mini= dis[nod];
                fo(i,v[nod].size()){
                    if(dis[nod] < dis[v[nod][i]])mini=min(mini, ans[v[nod][i]]);
                    else{
                        mini= min(mini, dis[v[nod][i]]);
                    }
                }
                ans[nod]=mini;
            }
            val--;
        }
        fo1(i,n)cout<<ans[i]<<" ";
        cout<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}