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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n;
        ll a[n+1][2];
        vll v[n+1];
       
        fo(i,n){
            cin>>a[i+1][0];
        }
        fo(i,n)cin>>a[i+1][1];
        map<pll,ll>p;
        fo1(i,n){
            v[a[i][0]].pb(a[i][1]);
            v[a[i][1]].pb(a[i][0]);
            p[mp(a[i][0] , a[i][1])]=i;
        }
        ll ans=0;
        vll vans;
        flag=0;
        fo1(i,n){
            if(v[i].size()!=2)flag=1;
        }
        if(flag==1){cout<<-1<<endl; continue;}
        map<ll,ll>m1;
        fo1(i,n){
            if(m1[i]!=0)continue;
            if(v[i][0]==i)continue;
            m1[i]=1;
            ll last=i;
            ll node=v[last][0];
            ll temp=2,val=0;
            vll v1,v2;
            if(p[mp(last,node)]>=1){
                v1.pb(p[mp(last,node)]);
            }
            else v2.pb(p[mp(node, last)]);
            while(1){
                m1[node]=1;
                ll kk;
                if(v[node][0]==last)kk=v[node][1];
                else kk=v[node][0];
                if(p[mp(node,kk)]>=1){
                    v1.pb(p[mp(node,kk)]);
                }
                else v2.pb(p[mp(kk,node)]);
                //cout<<<<<endl;
                if(kk==i){
                    break;
                }
                temp++;
                last=node;
                node=kk;

            }
            if(v1.size()<=v2.size()){
                fo(j,v1.size())vans.pb(v1[j]);
            }
            else{
                fo(j,v2.size())vans.pb(v2[j]); 
            }
        }
        cout<<vans.size()<<endl;
        fo(i,vans.size())cout<<vans[i]<<" ";
        cout<<endl;







        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}