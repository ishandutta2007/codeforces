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
        cin>>n>>m>>q;
        ll val[n][m];
        char a[n][m];
        fo(i,n){
            fo(j,m)cin>>a[i][j];
        }
        fo(i,n)fo(j,m)val[i][j]=-1;
        vector<pll>v;
        ll count=0;
        fo(i,n)fo(j,m){
            ll cc=0;
            if(i>0)if(a[i][j]==a[i-1][j])cc++;
            if(j>0)if(a[i][j]==a[i][j-1])cc++;
            if(i<n-1)if(a[i][j]==a[i+1][j])cc++;
            if(j<m-1)if(a[i][j]==a[i][j+1])cc++;
            if(cc>0)val[i][j]=0, v.pb(mp(i,j)), count++;
        }
        //cout<<count<<endl;
        flag=0;
        ll temp=1;
        ll kk=v.size();
        fo(i,n*m)v.pb(mp(0,0));
        if(count==0)flag=1;
        else while(count<n*m){
            vector<pll>vect;
            //ll temp=1;
            fo(i,kk){
                pll p=v[i];
                if(p.fi>0)if(val[p.fi-1][p.se]==-1){
                    val[p.fi-1][p.se]=temp;
                    vect.pb(mp(p.fi-1,p.se));
                    count++;
                }
                if(p.se>0)if(val[p.fi][p.se-1]==-1){
                    val[p.fi][p.se-1]=temp;
                    vect.pb(mp(p.fi,p.se-1));
                    count++;
                }
                if(p.fi<n-1)if(val[p.fi+1][p.se]==-1){
                    val[p.fi+1][p.se]=temp;
                    vect.pb(mp(p.fi+1,p.se));
                    count++;
                }
                if(p.se<m-1)if(val[p.fi][p.se+1]==-1){
                    val[p.fi][p.se+1]=temp;
                    vect.pb(mp(p.fi,p.se+1));
                    count++;
                }
            }
            temp++;
            //cout<<count<<endl;
            //v.erase();
            kk=vect.size();
            fo(i,kk)v[i]=vect[i];
            //cout<<v.size();
        }
        fo(i,q){
            ll x,y,p;
            cin>>x>>y>>p;
            if(flag==1)cout<<(ll)(a[x-1][y-1]-'0')<<endl;
            else if(p<val[x-1][y-1])cout<<(ll)(a[x-1][y-1]-'0')<<endl;
            else cout<<((ll)(a[x-1][y-1]-'0') + p + val[x-1][y-1])%2<<endl;
        }





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}