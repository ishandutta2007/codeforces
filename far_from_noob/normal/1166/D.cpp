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
        ll a,b;
        cin>>a>>b;
        cin>>m;
        if(a==b){cout<<1<<" "<<a<<endl; continue;}
        ll temp=0;
        ll x=a+1, y=a+m;
        flag=0;
        vll v1,v2;
        v1.pb(x);
        v2.pb(y);
        while(1){
            if(y<b){
                x+=x;
                y+=y;
                v1.pb(x);
                v2.pb(y);
                temp++;
            }
            else if(x>b){
                flag=1;
                break;
            }
            else {
                break;
            }
        }
        if(flag==1){cout<<-1<<endl; continue;}
        vll ans;
         ans.pb(a);
        ll diff=b-x;
        //cout<<diff;
        //te//mp=0;
        //cout<<temp<<endl;
        for(int i=0;i<temp;i++){
            if(diff >= (ll)pow(2,temp-i-1)*(m-1)){
                diff-=(ll)pow(2,temp-i-1)*(m-1);
                v1[i]+=m-1;
                for(int j=i+1;j<temp;j++){
                    v1[j]+=(ll)pow(2,j-i-1)*(m-1);
                }

            }
            ans.pb(v1[i]);
        }
        ans.pb(b);
        cout<<ans.size()<< " ";
        fo(i,ans.size())cout<<ans[i]<<" ";
        cout<<endl;







        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}