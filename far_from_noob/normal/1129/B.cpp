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
        //cout<<500500*2000  - 1000000;
        cin>>k;

        ll n2;
        if(k==1000000000){
            cout<<2000<<endl;
            fo(i,1998)cout<<0<<" ";
            cout<<-499500<< " "<<1000000<<endl;
            return 0;
        }
        if(k==999999999){
            ll n2;
            fo1(i,1000){
                if((k+3*i)%1002 ==0){n2=i; break;}
            }
            ll a=(k+3*n2)/1002;
            cout<<1002+ n2<<endl;
            fo(i,1001)cout<<0<<" ";
            cout<<-3<<" ";
            ll b=a+3;
            fo(i,n2){
            if(i<n2-1){
                if(b>0)cout<<1<<" ", b--;
                else cout<<0<<" ";
            }
            else cout<<b;
            }
            return 0;
        }
        fo1(i,1000){
            if((k+i)%1000==0){n2=i; break;}
        }
        ll n1=n2+1000;
        ll a=(k+n2)/1000;
        vector<ll>ans;
        ll b=a+1;
        fo(i,1000-1){
            ans.pb(0);
        }
        ans.pb(-1);

        fo(i,n2){
            if(i<n2-1){
                if(b>0)ans.pb(1), b--;
                else ans.pb(0);
            }
            else ans.pb(b);
        }
        cout<<ans.size()<<endl;
        fo(i,ans.size()){
            cout<<ans[i]<<" ";
        }
       //cout<<1000000-499500<<56345655;




        
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}