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
//ll rown[5000][5000],rowp[5000][5000],coln[5000][5000],colp[n][m];

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
        //ll n,m;
        cin>>n>>m;
        char a[n][m];
        fo(i,n)fo(j,m)cin>>a[i][j];
        ll rown[n][m],rowp[n][m],coln[n][m],colp[n][m];

        int ans=0,maxcount=0;
        
        fo(i,n)fo(j,m){
            if(a[i][j]=='.')continue;
            fo(i1,n)fo(j1,m)rown[i1][j1]=i1+1,rowp[i1][j1]=i1-1,coln[i1][j1]=j1+1,colp[i1][j1]=j1-1; 
            fo(i1,n)fo(j1,m)if(a[i1][j1]=='.'){
                if(rowp[i1][j1]!=-1)rown[rowp[i1][j1]][j1]=rown[i1][j1];
                if(rown[i1][j1]!=n)rowp[rown[i1][j1]][j1]=rowp[i1][j1];
                if(colp[i1][j1]!=-1)coln[i1][colp[i1][j1]]=coln[i1][j1];
                if(coln[i1][j1]!=m)colp[i1][coln[i1][j1]]=colp[i1][j1];
            }
            ll count=0;
            int i1=i, j1=j;
            count++;
            //cout<<coln[1][0]<<coln[1][2];
            while(1){
                if(rowp[i1][j1]!=-1)rown[rowp[i1][j1]][j1]=rown[i1][j1];
                if(rown[i1][j1]!=n)rowp[rown[i1][j1]][j1]=rowp[i1][j1];
                if(colp[i1][j1]!=-1)coln[i1][colp[i1][j1]]=coln[i1][j1];
                if(coln[i1][j1]!=m)colp[i1][coln[i1][j1]]=colp[i1][j1];
                //cout<<i1<<j1<<" ";
                if(a[i1][j1]=='D'){
                    if(rown[i1][j1] == n)break;
                    else{ count++; i1= rown[i1][j1] ;}
                }
                else if(a[i1][j1]=='U'){
                    if(rowp[i1][j1] == -1)break;
                    else{ count++; i1= rowp[i1][j1] ;}
                }
                else if(a[i1][j1]=='R'){
                    if(coln[i1][j1] == m)break;
                    else{ count++; j1= coln[i1][j1] ;}
                }
                else if(a[i1][j1]=='L'){
                    if(colp[i1][j1] == -1)break;
                    else{ count++; j1= colp[i1][j1] ;}
                }

                //cout<<i1<<j1<<endl;
                //break;
            }
            if(count==ans)maxcount++;
            else if(count>ans)ans=count,maxcount=1;
            

        }
        cout<<ans<<" "<<maxcount;

        //vector<pll> v;

        





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}