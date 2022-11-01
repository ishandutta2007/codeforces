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
int mod=1000000007;
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
        string s;
        cin>>s;
        ll l=s.size();
        ll p1=37 , p2=43;
        ll hash1[l],hash2[l];
        ll temp1=0,temp2=0;
        ll pp1=1,pp2=1;
        
        ll rev1[l+1],rev2[l+1];
        rev1[l]=0,rev2[l]=0;
        temp1=0,temp2=0;
        pp1=1,pp2=1;
        fo(i,l){
            if(i==0){
                hash1[i]=s[i];
                hash2[i]=s[i];
            }
            else{
                hash1[i]=(hash1[i-1]+ s[i]*pp1)% mod;
                hash2[i]=(hash2[i-1]+ s[i]*pp2)% mod;
            }

            
            rev1[l-1-i]=(rev1[l-i]+ (s[l-1-i])*pp1 ) %mod;
            rev2[l-1-i]=(rev2[l-i]+ (s[l-1-i])*pp2 )%mod;
            pp1=pp1*p1%mod,pp2=pp2*p2%mod;
        }
        
        ll ans[l+1];
        //cout<<hash1[2]<<" "<< 98*37 + 97;
        ans[0]=0;
        ll sum=0;
        pp1=power(power(p1,l-1) , mod-2),pp2=power(power(p2,l-1) , mod-2);
        fo(i,l){
            ans[i+1]=0;
            if(hash1[i]== (rev1[0]+mod-rev1[i+1])*(pp1)%mod)
                if(hash2[i] == (rev2[0]+mod-rev2[i+1])*(pp2)%mod){
                    ans[i+1] = 1+ ans[(i+1)/2];
                    sum+=ans[i+1];
                }
            pp1=pp1*p1%mod,pp2=pp2*p2%mod;
        }
        cout<<sum;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}