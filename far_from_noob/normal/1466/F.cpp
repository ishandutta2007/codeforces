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
ll root[500005];
vll v[500005];
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
        pair<pll,ll>p[n];
        fo(i,n){
            cin>>m;
            if(m==1){
                ll a;
                cin>>a;
                p[i]=mp(mp(a,k+1),i);
                //cout<<p[i].fi.fi<<endl;
            }
            else{
                ll a,b;
                cin>>a>>b;
                if(a>b)swap(a,b);
                p[i]=mp(mp(a,b),i);
            }
        }
        // sort(p,p+n);
        // pair<pll,ll>p1[n];
        // fo(i,n)p1[i]=p[i];
        // fo(i,n)p[i]=p1[n-1-i];
        //cout<<p[0].fi.fi<<endl;
        ll is[k+1];
        fo(i,k+1)is[i]=0;
        //cout<<p[0].fi.fi<<endl;
        ///ll ans=0;
        vll ans;
        fo1(i,k+1){root[i]=i;v[i].pb(i);}
        //cout<<p[0].fi.fi<<endl;
        fo(i,n){
            //cout<<endl<<p[i].fi.fi<<" "<<p[i].fi.se<<" "<<p[i].se<<endl;
            //cout<<ans.size()<<endl;
            if(p[i].fi.se==k+1){
                //cout<<99;
                if(is[p[i].fi.fi]==1)continue;
                else {ll val = root[p[i].fi.fi];
                    fo(j,v[val].size())is[v[val][j]]=1;
                 ans.pb(p[i].se);}
            }
            else{
                if(is[p[i].fi.fi]==1){
                    //cout<<33;
                    ll temp=root[p[i].fi.se];
                    if(is[temp]==1)continue;
                    else{
                        ans.pb(p[i].se);
                        fo(j,v[temp].size()){
                            is[v[temp][j]]=1;
                        }
                    }
                }
                else if(is[p[i].fi.se]==1){
                    //cout<<44<<endl;
                    ll temp=root[p[i].fi.fi];
                    if(is[temp]==1)continue;
                    else{
                        ans.pb(p[i].se);
                        fo(j,v[temp].size()){
                            is[v[temp][j]]=1;
                        }
                    }
                }
                else{
                    ll temp1=root[p[i].fi.fi], temp2=root[p[i].fi.se];
                    //cout<<temp1<<temp2;
                    if(temp1==temp2)continue;
                    //cout<<00;
                    if(v[temp1].size()>=v[temp2].size()){
                        fo(j,v[temp2].size()){v[temp1].pb(v[temp2][j]);root[v[temp2][j]]=temp1; }
                        v[temp2].clear();
                    }
                    else{
                        fo(j,v[temp1].size()){v[temp2].pb(v[temp1][j]);root[v[temp1][j]]=temp2; }
                        v[temp1].clear();
                    }
                    //cout<<33;
                    ans.pb(p[i].se);
                }
            }
            //
        }
        //cout<<ans.size();
        cout<<power(2,ans.size())<<" "<<ans.size()<<endl;
        sort(all(ans));
        fo(i,ans.size())cout<<ans[i]+1<<" ";





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}