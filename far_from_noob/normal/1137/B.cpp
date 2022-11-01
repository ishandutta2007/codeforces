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
    ll tt=1;
    while(tt--){
        string s;
        string t;
        cin>>s>>t;
        ll l=t.size();
        ll a[l+1];
        fo(i,l){
            a[i+1]=t[i]-'0';
        }
        ll pre[l+1];
        pre[1]=0;
        pre[0]=-1;
        for(int i=2;i<=l;i++){
            ll temp=pre[i-1];
            while(temp!=-1){
                if(a[temp+1]== a[i]){
                    pre[i]=temp+1;
                    break;
                }
                else temp=pre[temp];
            }
            if(temp==-1)pre[i]=0;
        }
        ll c1=0,c0=0, s1=0,s0=0,t1=0,t0=0;
        fo(i,s.size()){
            if(s[i]=='0')s0++;
            else s1++;
        }
        ll kk=pre[l];
        fo(i,t.size()){
            if(t[i]=='0')t0++;
            else t1++;
            if(i>=kk){
                if(t[i]=='0')c0++;
                else c1++;
            }
        }
        ll ans=0;
        
        if(s1>=t1 && s0>=t0){
            ans++;
            s1-=t1;
            s0-=t0;
            while(s1>=c1 && s0>=c0){
            ans++;
            s1-=c1;
            s0-=c0;
        }
        }
        
        if(ans>0)cout<<t;
        string cc;
        for(int i=kk;i<t.size();i++)cc.pb(t[i]);
        fo(i,ans-1)cout<<cc;
        fo(i,s1)cout<<1;
        fo(i,s0)cout<<0;






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}