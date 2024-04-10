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
ll temp[200005];
ll ans[200005][5];
void dfs1(ll node, ll root){
    fo(i,5)ans[node][i]=0;
    ans[node][0]=1;
    temp[node]=0;
    fo(i,v[node].size()){
        if(v[node][i]==root)continue;
        dfs1( v[node][i] , node);
        fo(j,k){
            ans[node][(j+1)%k]+=ans[v[node][i]][j];
        }
        temp[node]+=temp[v[node][i]]+ ans[v[node][i]][k-1];
    }
}
ll fans[200005];
void dfs2(ll node, ll root){
    if(node==root){
        ll kk =0;
        fo1(i,k-1)kk+=ans[node][i];
        fans[ node]= temp[ node ]+ kk;
    }
    fo(i, v[node].size()){
        if(v[node][i]==root)continue;
        else{
            ll temp1=temp[node]-temp[v[node][i]]- ans[v[node][i]][k-1];
            ll jj[k];
            fo(j,k)jj[j]=ans[v[node][i]][j];
            fo(j,k){
                ans[v[node][i]][j]+= ans[node][(j+k-1)%k]- jj[(j+2*k-2)%k];
                //if(v[node][i]==2)cout<<ans[v[node][i]][j]<<endl;
            }
            //ans[v[node]]
            temp[v[node][i]]+=temp1 + ans[node][k-1] - jj[(2*k-2)%k];
            ll kk=0;
            fo1(j,k-1)kk+=ans[v[node][i]][j];
            fans[v[node][i]]=temp[v[node][i]]+kk;
            dfs2(v[node][i], node);
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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>k;
        fo(i,n-1){
             ll a,b;
             cin>>a>>b;
             v[a].pb(b);
             v[b].pb(a);
        }
        dfs1(1,1);
        //cout<<ans[2][1];
        dfs2(1,1);
        ll tans=0;
        //cout<<fans[2]<<endl;
        fo1(i,n)tans+=fans[i];
        cout<<tans/2;







        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}