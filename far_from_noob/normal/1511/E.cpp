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
ll mod=998244353;
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
        ll ans[300005];
        ans[0]=0;
        ans[1]=0;
        ll temp1=0, temp2=0;
        for(int i=2;i<300005;i++){
            temp1=(i-1)/2  + temp1*2;
            temp2= temp2 + ans[i-1];
            ans[i] = temp1+ temp2 + i/2;
            ans[i]%=mod;
            temp1%=mod;
            temp2%=mod;
            //cout<<temp1<<" "<<ans[i]<<endl;
            //temp2+=ans[i];
            //cout<<ans[i]<<" ";
 
        }
        //cout<<ans[5];
        char a[n][m];
        ll cc=0;
        fo(i,n)fo(j,m){cin>>a[i][j]; if(a[i][j]=='o')cc++;}
        //cout<<cc<<endl;
        ll h[n][m];
        ll ansm=0;
        fo(i,n){
            ll temp=0;
            fo(j,m){
                if(a[i][j]=='o')temp++;
                ll kk=0;
                if(j==m-1){kk=1;}
                else{
                    if(a[i][j+1]=='*')kk=1;
                }
                if(kk==1){
                    ansm+= ans[temp]*power(2,cc-temp);
                    ansm%=mod;
                    //cout<<temp<<endl;
                    temp=0;
                }
            }
        }
        fo(j,m){
            ll temp=0;
            fo(i,n){
                if(a[i][j]=='o')temp++;
                ll kk=0;
                if(i==n-1){kk=1;}
                else{
                    if(a[i+1][j]=='*')kk=1;
                }
                if(kk==1){
                    ansm+= ans[temp]*power(2,cc-temp);
                    ansm%=mod;
                    //cout<<temp<<endl;
                    temp=0;
                }
            }
        }
        cout<<ansm<<endl;
 
 
 
 
 
 
        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}