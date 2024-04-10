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
int lcs1[5005][5005];
int lcs[5005][5005];
string s1,s2;
ll find1(ll n, ll m){
    if(lcs1[n][m]!=-1)return lcs1[n][m];
    if(n==0 || m==0)return 0;
    if(s1[n-1]==s2[m-1]){lcs1[n][m]= 2+ find1(n-1,  m-1); find1(n,  m-1);find1(n-1,  m); return lcs1[n][m];}
    lcs1[n][m]= max(max(find1(n-1,m),  find1(n,m-1)) -1 , 0);
    return lcs1[n][m];
}
ll find(ll n,ll m){
    if(lcs[n][m]!=-1)return lcs[n][m];
    if(n==0 || m==0)return 0;
    lcs[n][m]=max(find(n,m-1) , find(n-1,m));
    lcs[n][m]=max(lcs[n][m],find1(n,m));
    return lcs[n][m];
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
        //string s1,s2;
        cin>>s1>>s2;
        fo(i,5005)fo(j,5005)lcs[i][j]=-1,lcs1[i][j]=-1;
        find(n,m);
        // ll maxi=0;
        // ll mini[n];
        // fo(i,n)mini[i]=0;
        // for(int i=1;i<=n;i++){
        //     ll temp=0;

        //     for(int j=1;j<=m;j++){
        //         //cout<<lcs[i][j]<<" ";
        //         ll val= lcs[i][j]*4 - i - j;
        //         if(1)mini[i-1]=min(mini[i-1],val);
        //         temp=min(temp,mini[i-1]);
        //         //if(val-temp==15)cout<<i<<" "<<lcs[i][j]<<" "<<j<<" "<<val<<endl;
        //         maxi=max(maxi,val- temp);
        //     }
        // }
        cout<<lcs[n][m];





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}