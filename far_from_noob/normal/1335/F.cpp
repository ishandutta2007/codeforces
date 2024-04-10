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
        char a[n][m],c[n][m]; ll val[n][m];ll root[n][m];
        fo(i,n)fo(j,m)cin>>a[i][j];
        fo(i,n)fo(j,m)cin>>c[i][j], val[i][j]=-1;
        map<ll,ll>len;
        map<ll,ll>index;
        ll kk=0;
        fo(i,n)fo(j,m){
            vll v;
            if(val[i][j]!=-1)continue;
            v.pb(1e6*i + j);
            val[i][j]=-2;
            ll x=i, y=j;
            ll temp;
            ll f=-1;
            while(1){
                ll x1=x,y1=y;
                if(c[x][y]=='R')y++;
                else if(c[x][y]=='L')y--;
                else if(c[x][y]=='U')x--;
                else if(c[x][y]=='D')x++;
                if(val[x][y]==-2){temp=1e6*x1+y1;f=1e6*x+y; root[x1][y1]=temp; val[x1][y1]=0; break;}
                else if(val[x][y]>=0){
                    temp= 1e6*x1+y1;
                    root[x1][y1]=root[x][y];
                    val[x1][y1]=1+val[x][y];
                    break;
                }
                else{
                    v.pb(1e6*x+y);
                    val[x][y]=-2;
                }
                
            }
            ll e6=1000000;
            for(int i=v.size()-2;i>=0;i-- ){
                val[v[i]/e6][v[i]%e6]=val[temp/e6][temp%e6]+v.size()-1-i;
                root[v[i]/e6][v[i]%e6]=root[temp/e6][temp%e6];
            }
            if(f>=0){ kk++ ; index[temp]=kk; len[kk]= val[f/e6][f%e6];}
        }
        map<ll,ll>m1[kk+1];
        ll count[kk+1];
        ll ans1=0, ans2=0;
        fo1(i,kk)ans1+=len[i]+1;
        fo(i,n)fo(j,m){
            if(a[i][j]=='1')continue;
            ll par=root[i][j];
            ll ind=index[par];
            if(m1[ind][val[i][j]%(len[ind]+1) ] ==0){
                ans2++; 
                m1[ind][val[i][j]%(len[ind]+1) ]=1;
            }
        }
        cout<<ans1<<" "<<ans2<<endl;

        
        





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}