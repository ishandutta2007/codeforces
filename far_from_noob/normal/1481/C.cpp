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
        cin>>n>>m;
        map<ll,ll>m1,m2,m3;
        ll a[n],b[n],c[m];
        fo(i,n)cin>>a[i];
        fo(i,n)cin>>b[i];
        vll v1[n+1],v2[n+1],v3[n+1];
        fo(i,n){
            if(a[i]!=b[i]){m1[b[i]]++;v1[b[i]].pb(i); }
            m2[b[i]]++; v2[b[i]].pb(i);
        }
        ll count[n+1];
        fo(i,n+1)count[i]=0;
        fo(i,m){
            cin>>c[i];
            m3[c[i]]++;
            v3[c[i]].pb(i);
        }
        flag=0;
        fo1(i,n){
            if(m1[i]>m3[i])flag=1;
        }
        if(m2[c[m-1]] ==0 )flag=1;
        if(flag==0){cout<<"YES"<<endl;
            vll ans;
            fo(i,m){
                if(count[c[i]]==v1[c[i]].size()){
                    ans.pb(-1);
                }
                else{
                    ans.pb(v1[c[i]][count[c[i]]]+1);
                    count[c[i]]++;
                }
            }
            if(ans[m-1]==-1){
                ans[m-1]=v2[c[m-1]][0]+1;
            }
            fo(i,m)if(ans[i]==-1)ans[i]=ans[m-1];
            fo(i,m)cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}