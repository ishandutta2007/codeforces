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
        cin>>n;
        ll seat[2*n+1];
        fo1(i,2*n)seat[i]=0;
        fo(i,n){
            ll a,b;
            cin>>a>>b;
            seat[a]=b;
        }
        ll val[2*n+1];
        fo(i,2*n+1)val[i]=0;
        ll count[2*n+1];
        fo(i,2*n+1)count[i]=0;
        ll ans=1;
        fo1(i,2*n){
            if(val[i]!=0)continue;
            vll v;
            v.pb(i);
            map<ll,ll>m1;
            m1[i]=1;
            ll node=i;
            while(1){
                if(seat[node]==node){
                    fo(j,v.size())val[v[j]]=-1;
                    break;
                }
                if(m1[seat[node]]!=0){
                    ans*=2;
                    ans%=mod;
                    fo(j,v.size())val[v[j]]=-1;
                    break;
                }
                if(val[seat[node]]==-1){
                    fo(j,v.size())val[v[j]]=-1;
                    break;
                }
                if(val[seat[node]]!=0){
                    fo(j,v.size())val[v[j]]=val[seat[node]],count[val[seat[node]]]++;
                    break;
                }
                if(seat[node]==0){
                    fo(j,v.size()){val[v[j]]=node,count[node]++;}
                    //count[node]++;
                    break;
                }
                node=seat[node];
                v.pb(node);
                m1[node]=1;


            }
            //cout<<i<<ans;
        }
        //cout<<count[2];
        fo(i,2*n+1){
            if(count[i]>0){
                ans*=count[i];
                ans%=mod;
            }
        }
        cout<<ans;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}