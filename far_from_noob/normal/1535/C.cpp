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
        //cin>>n;
        string s;cin>>s;
        n=s.size();
        ll ans=0;
        ll last=0;
        ll cc=0;
        ll first =-1;
        fo(i,n)if(s[i]!='?'){first=i; break;}
        //cout<<first<<endl;
        if(first==-1){cout<<n*(n+1)/2<<endl; continue;}
        for(int i=first-1;i>=0;i--){
            s[i]= '1'+'0'-s[i+1];
        }

        ans++;
        last=0;
        fo1(i,n-1){
            if(s[i]=='?'){
                ans+=(i-last + 1);
                s[i]='1'+'0'- s[i-1];
                cc++; 
            }
            else if(s[i]!=s[i-1]){

                ans+=(i-last+1);
                cc=0;
            }
            else{
                ans+= cc+1;
                last=i-cc;
                cc=0;
            }
        }
        cout<<ans<<endl;






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}