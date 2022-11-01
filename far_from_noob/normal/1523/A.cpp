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
        cin>>n>>k;
        k=min(k,n);
        set<ll>s;
        string s1;
        cin>>s1;
        string s2=s1;

        // ll temp=0;
        // fo(i,n){
        //     if(s1[i]=='1')temp= k;
        //     else{
        //         if(temp>0){s2[i]='1';
        //         temp--; }
        //     }
        // }
        // temp=0;

        // for(int i=n-1;i>=0;i--){
        //     if(s1[i]=='1')temp= k;
        //     else{
        //         if(temp>0){s2[i]='1';
        //         temp--; }
        //     }
        // }
        // cout<<s2<<endl;
        fo(i,n){
            if(s1[i]=='1')s.insert(i);
        }
        if(s.size()==0){
            cout<<s1<<endl; 
            continue;
        }

        s.insert(-1*mod);s.insert(mod);
        fo(i,n){
            auto it= s.lower_bound(i);
            ll p = *it;

            it--;
            ll p1= *it;
            if(s1[i]=='1')continue;
            ll x= p- i, y = i-p1;
            if(x == y);
            else if(x<=k || y<=k)s1[i]='1';
        }


        cout<<s1<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}