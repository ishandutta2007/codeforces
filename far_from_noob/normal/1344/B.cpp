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
ll a[1000][1000];
char c[1000][1000];
ll ans;
void justdo( ll i, ll j){
    //cout<<a[i+1][j];
    //if(i==1&& j==1)cout<<ans;
    a[i][j]=1;
    if(i>0)if(a[i-1][j]==0 && c[i-1][j]=='#')justdo(i-1,j);
    if(j>0)if(a[i][j-1]==0 && c[i][j-1]=='#')justdo(i,j-1);
    if(i<n-1)if(a[i+1][j]==0 && c[i+1][j]=='#')justdo(i+1,j);
    if(j<m-1)if(a[i][j+1]==0 && c[i][j+1]=='#')justdo(i,j+1);
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
        
        fo(i,n)fo(j,m)cin>>c[i][j];
        flag=0;
        ll count1[n],count2[m];
        fo(i,n){
            ll f=0;
            ll cc=0;
            fo(j,m){
                if(c[i][j]=='#')cc++;
                if(f==0){
                    if(c[i][j]=='#')f=1;
                }
                else if(f==1){
                    if(c[i][j]=='.')f=2;
                }
                else if(f==2){
                    if(c[i][j]=='#')flag=1;
                }
            }
            count1[i]=cc;
        }
        fo(j,m){
            ll f=0;
            ll cc=0;
            fo(i,n){
                if(c[i][j]=='#')cc++;
                if(f==0){
                    if(c[i][j]=='#')f=1;
                }
                else if(f==1){
                    if(c[i][j]=='.')f=2;
                }
                else if(f==2){
                    if(c[i][j]=='#')flag=1;
                }
            }
            count2[j]=cc;
        }
        if(flag==1){cout<<-1; return 0;}
        ans=0;
        //ll a[n][m];
        fo(i,n)fo(j,m)a[i][j]=0;
        fo(i,n)fo(j,m){
            //if(i==1 && j==1)cout<<a[i][j];
            if(a[i][j]==0 && c[i][j]=='#'){
                //cout<<i<<j<<endl;
                ans++;
                justdo(i,j);
                //cout<<a[i+1][j]<<" ";
            }
        }
        ll m1[n];
        ll m2[m];
        fo(i,n)m1[i]=0;
        fo(i,m)m2[i]=0;
        fo(i,n)fo(j,m){
            if(count1[i]==0&& count2[j]==0)m1[i]++, m2[j]++;
        }
        flag=0;
        fo(i,n)fo(j,m){
            if(count1[i]==0  && m1[i]==0 ){cout<<-1 ; return 0;}
            if(count2[j]==0  && m2[j]==0 ){cout<<-1 ; return 0;}

        }

        cout<<ans;






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}