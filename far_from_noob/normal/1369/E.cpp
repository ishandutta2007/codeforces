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
        ll count[1000005]={0};
        fo(i,n){
            cin>>count[i+1];
        }
        vll v[n+1];
        pair<ll,ll>p[m+1];
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            p[i]=mp(a,b);
            v[a].pb(i);
            v[b].pb(i);
        }
        ll vsiz[n+1];
        fo1(i,n)vsiz[i]=v[i].size();
        ll is[m+1];
        fo(i,m)is[i]=0;
        vll ans;
        queue<ll>q;
        fo1(i,n){
            if(count[i]==0 && v[i].size()!=0){q.push(i);}
        }
        while(q.size()!=0){
            ll node=q.front();
            //cout<<node<<endl;
            q.pop();
            fo(i,v[node].size()){
                if(is[v[node][i]]==1)continue;
                //cout<<v[node][i]<<"  "; 
                is[v[node][i]]=1;
                ans.pb(v[node][i]);
                ll temp=v[node][i];
                if(p[temp].fi == node){
                    if(count[p[temp].se]==0){cout<<"DEAD"; return 0;}
                    count[p[temp].se]--;
                    vsiz[p[temp].se]--;
                    //cout<<p[temp].se<<" ";
                    if(count[p[temp].se] ==0)q.push(p[temp].se);
                }
                else{
                     if(count[p[temp].fi]==0){cout<<"DEAD"; return 0;}
                    vsiz[p[temp].fi]--;
                    count[p[temp].fi]--;
                    if(count[p[temp].fi] ==0)q.push(p[temp].fi);
                    //cout<<p[temp].fi<<" "<<vsiz[p[temp].fi] <<" ";
                }

            }
        }
        
        vll ans2;
        fo1(i,n){
            if(count[i]>0 && vsiz[i]<=count[i])q.push(i);
        }
        while(q.size()>0){
            ll node=q.front();
            q.pop();
            fo(i,v[node].size()){
                if(is[v[node][i]]==1)continue;
                //cout<<v[node][i]<<"  "; 
                is[v[node][i]]=1;
                ans2.pb(v[node][i]);

            
            ll temp=v[node][i];
            if(p[temp].fi == node){
                   vsiz[p[temp].se]--;
                   if(count[p[temp].se]>0 && vsiz[p[temp].se]<=count[p[temp].se])q.push(p[temp].se);
                }
                else{
                    vsiz[p[temp].fi]--;
                    if(count[p[temp].fi]>0 && vsiz[p[temp].fi]<=count[p[temp].fi])q.push(p[temp].fi);
                }
            }

        }
        if(ans.size()+ans2.size()<m){cout<<"DEAD"; return 0;}
        cout<<"ALIVE"<<endl;
        fo(i,ans.size())cout<<ans[i]+1<<" ";
        if(ans2.size()>0)for(int i=ans2.size()-1;i>=0;i--){
            cout<<ans2[i]+1<<" ";
        }






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}