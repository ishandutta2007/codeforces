#include<bits/stdc++.h>
using namespace std;
#define ll int
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
vector<int> v[300005];
bool is[300005];
int par[300005];
int in[300005],out[300005];
ll tim;
void dfs(ll node){
    in[node]=tim;
    tim++;
    fo(i,v[node].size()){
        if(is[v[node][i]]==0){
            // v1[node].pb(v[node][i]);
            // v1[v[node][i]].pb(node);
            is[v[node][i]]=1;
            dfs(v[node][i]);
            par[v[node][i]]=node;
        }
    }
    out[node]=tim;
    tim++;
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
        cin>>n>>m;
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        cin>>q;
        pll p[q];
        ll m1[n+1];fo(i,n+1)m1[i]=0;
        ll cnt=0;
        fo(i,q){
            ll a,b;
            cin>>a>>b;
            p[i]=mp(a,b);
            m1[a]++;
            m1[b]++;
            if(m1[a]%2==1)cnt++;else cnt--;
            if(m1[b]%2==1)cnt++;else cnt--;
        }
        if(cnt!=0){cout<<"NO"<<endl; cout<<cnt/2<<endl; break;}

        cout<<"YES"<<endl;
        fo(i,n+1)is[i]=0;
        is[1]=1;
        dfs(1);
        tim=0;
        //fo1(i,n-1)cout<<par[i+1]<<" ";cout<<endl;
        fo(i,q){
            vll ans;
            vll ans2;
            while(1){
                ans2.pb(p[i].se);
                if(in[p[i].se] <= in[p[i].fi] && out[p[i].se]>= out[p[i].fi]){
                    break;
                }
                p[i].se = par[p[i].se];
            }
            while(p[i].fi!=p[i].se){
                ans.pb(p[i].fi);
                p[i].fi = par[p[i].fi];
            }


            for(int i1=ans2.size()-1;i1>=0;i1--)ans.pb(ans2[i1]);



            cout<<ans.size()<<endl;
            fo(i1,ans.size())cout<<ans[i1]<<" ";
            cout<<endl;
        }





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}