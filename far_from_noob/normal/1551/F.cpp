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
vll v[1000];

ll is[101][101];

void dfs(ll node, ll root, ll baap, ll h){
    is[baap][h]++;
    fo(i,v[node].size()){
        if(v[node][i]!=root){
            dfs( v[node][i], node , baap, h+1);
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
    ll fac[10005];
    ll infac[10005];
    fac[0]=1;
    fo(i,10000){
        fac[i+1]=fac[i]*(i+1)%mod;
    }
    infac[0]=1;
    infac[1]=1;
    for(int i=2;i<10002;i++){
        infac[i]=infac[i-1]*power(i,mod-2)%mod;
    }
    //t=1;
    while(t--){
        cin>>n>>k;
        fo(i,n+1)v[i].clear();
        fo(i,n-1){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        if(k==2){cout<<n*(n-1)/2<<endl; continue; }
        ll ans=0;
        fo1(i,n){
            vll v1[101];
            //fo(i,101)val[i]=1;
            fo(j,v[i].size()){
                fo(l,101)is[v[i][j]][l]=0;
                //fo(l,101)val[v[i][j]][l]=1;
                dfs(v[i][j], i, v[i][j] ,1);
            }
            fo(j,v[i].size()){
                fo1(l,100){
                    if(is[v[i][j]][l] >=1){
                        v1[l].pb(is[v[i][j]][l]);
                     } 

                    //count[l]%=mod
                }
            }
            fo1(j,100){
                ll dp[k+1];fo(i,k+1)dp[i]=0;
                dp[0]=1;
                fo(l,v1[j].size()){
                    for(int p=k;p>=1;p--){
                        dp[p]+= dp[p-1]*v1[j][l];
                        dp[p]%=mod;
                    }
                }
                ans+=dp[k];
                ans%=mod;
            }


            //cout<<ans<<endl;
        }
        
        cout<<ans<<endl;        



        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}