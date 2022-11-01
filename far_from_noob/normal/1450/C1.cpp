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
char a[1000][1000];
ll is[1000][1000];
vector<pll> v[3];

void fun(ll i, ll j){
    is[i][j]=1;
    v[(i+j)%3].pb(mp(i,j));
    if(i>0)if(a[i-1][j]=='X' && is[i-1][j] ==0)fun(i-1,j);
    if(j>0)if(a[i][j-1]=='X' && is[i][j-1] ==0)fun(i,j-1);
    if(i<n-1)if(a[i+1][j]=='X' && is[i+1][j] ==0)fun(i+1,j);
    if(j<n-1)if(a[i][j+1]=='X' && is[i][j+1] ==0)fun(i,j+1);
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
        cin>>n;
        fo(i,n)fo(j,n)cin>>a[i][j];
        fo(i,n)fo(j,n)is[i][j]=0;
        fo(i,n)fo(j,n){
            if(a[i][j]=='X' && is[i][j]==0){
                fo(l,3)v[l].clear();
                fun(i, j);
                ll val=3;
                if(v[0].size()<=v[1].size()  && v[0].size()<=v[2].size())val=0;
                if(v[1].size()<=v[0].size()  && v[1].size()<=v[2].size())val=1;
                if(v[2].size()<=v[1].size()  && v[2].size()<=v[0].size())val=2;
                //cout<<val<<endl;
                fo(l,v[val].size()){
                    a[v[val][l].fi][v[val][l].se]='O';
                }
            }
        }
        fo(i,n){
            fo(j,n)cout<<a[i][j];
            cout<<endl;
        }





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}