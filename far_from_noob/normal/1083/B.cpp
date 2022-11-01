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
        cin>>n>>k;
        string s1,s2;
        cin>>s1>>s2;
        ll temp=0;
        while(s1[temp]==s2[temp] && temp<n-1){
            temp++;

        }
        ll ans=temp;
        ll temp1=0;
        ll temp2=0;
        if(s1[temp]=='a')temp1=1;
        if(s2[temp]=='b')temp2=1;
        if(temp1+temp2>=k){cout<<ans +k + k*(n-1-temp); return 0;}
        ans+=temp1+temp2;
        fo1(i,n-1-temp){
            if(s1[i+temp]=='a')temp1*=2;
            else temp1=temp1*2-1;
            if(s2[i+temp]=='b')temp2*=2;
            else temp2=temp2*2-1;
            if(temp1+temp2>=k){
                ans= ans + (k)*(n-i-temp);
                break;
            }
            else ans+=temp1+temp2;
            //if(i==n-1)cout<<ans;
        }
        cout<<ans;






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}