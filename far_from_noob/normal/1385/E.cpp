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
 
map<ll,ll> ifused;
vll v[200005],dir[200005];
vector<pll> ans;
void dfs(ll node){
    //cout<<node<<ifused<<endl;
    fo(i,v[node].size()){
                    
                if(ifused[v[node][i]]==2)ans.pb(mp(node,v[node][i]));
                if(ifused[v[node][i]]==1)ans.pb(mp(v[node][i],node));
                    
                }
 
    fo(i,dir[node].size()){
                    //if(t==0 && node==4)cout<<dir[node][i]<<" "<<ifused[1]<<endl;
                    if(ifused[dir[node][i]]==1){
                        //cout<<node<<" "<<dir[node][i]<<endl;
                        flag=1; return ;
                    }
                    else if(ifused[dir[node][i]]==2){
                        ans.pb(mp(node,dir[node][i]));
                    }
                    else{
                       
                        ifused[dir[node][i]]=1;
                        dfs(dir[node][i]);
                        ans.pb(mp(node,dir[node][i]));
                    }
                    
                }
                
          ifused[node]=2;
 
 
 
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
        fo1(i,n){
            v[i].clear();
            dir[i].clear();
            ifused[i]=0;
        }
        fo(i,m){
            cin>>k;
            ll a,b;
            if(k==0){
                cin>>a>>b;
                v[a].pb(b);
                v[b].pb(a);
            }
            if(k==1){
                cin>>a>>b;
                dir[a].pb(b);
            }
        }
        map<pll, ll>m1;
        queue<ll>q;
        //map<ll,ll>ifused;
        ans.clear();
        flag=0;
        fo1(i1,n){
            vll temp;
            if(ifused[i1]==0){
                
                ifused[i1]=1;
                dfs(i1);
                
            }
            
        }
        if(flag==1){cout<<"NO"<<endl; continue;}
        else{
            cout<<"YES"<<endl;
            fo(i,ans.size()){
                cout<<ans[i].fi<<" "<<ans[i].se<<endl;
            }
        }
 
 
 
 
 
 
 
        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}