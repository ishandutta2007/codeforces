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
        cin>>n>>m;
        vll v[n+1];
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        ll a[n+1];
        vll blogs[n+1];
        fo1(i,n)cin>>a[i], blogs[a[i]].pb(i);
        map<ll,ll>is;
        flag=0;

        vll ans;
        fo1(i,n){
            ll node;
            fo(j,blogs[i].size()){
                //cout<<node;
                node=blogs[i][j];
                //cout<<node;
                vll temp;
                fo(l,v[node].size()){
                    temp.pb(a[v[node][l]]);
                }
                sort(all(temp));
                ll mex=temp.size();
                ll kk=0;
                if(temp.size()==0)mex=1;
                else fo1(i,n){
                    if(temp[kk]!=i){mex=i; break;}
                    while(temp[kk]==i && kk<temp.size()){kk++;}
                    if(kk == temp.size()){mex=i+1; break;}
                }
                if(mex== i)ans.pb(node);
                else {flag=1; break;}

            }
            if(flag==1)break;
        }
        if(flag)cout<<-1;
        else fo(i,ans.size())cout<<ans[i]<<" ";







        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}