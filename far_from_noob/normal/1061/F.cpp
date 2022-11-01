#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
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
ll check(ll node){
    ll y= 1 + node;
    if(node==n)y=node-1;
    fo1(i,n){
        if(i==node || i==y )continue;
        cout<<"? "<<y<<" "<<node<<" "<<i<<endl;
        string s;
        cin>>s;
        if(s=="Yes")return 0;

    }
    return 1;
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
        cin>>n;
        cin>>k;
        ll leaf1;
        ll leaf2;
        srand(time(0));
        while(1){
            leaf1 = rand();
            leaf1 =1 + leaf1%n;
            if(check(leaf1)==1)break;
        } 
        while(1){
            leaf2 = rand();
            leaf2 = 1 + leaf2%n;
            if(leaf2== leaf1)continue;
            if(check(leaf2)==1){
                ll cnt=0;
                fo1(i,n){
                    cout<<"? "<<leaf1<< " "<<i<<" "<< leaf2<<endl;
                    string s;cin>>s;
                    if(s=="Yes")cnt++;
                }
                cnt=(cnt-1)/2;
                if( pow(k,cnt) *2 >=n)break;
                else continue;            }
        }
    
        vll v;
        fo1(i,n){
            if(i!= leaf1 ){
                cout<<"? "<<leaf1<< " "<<i<<" "<<leaf2<<endl;
                string sl;
                cin>>sl;
                if(sl=="Yes")v.pb(i);
            }
        }
        ll l= v.size();
        
        fo(i, l/2){
            ll curr= leaf2;
            fo(j,v.size()){
                if(v[j]== leaf1)continue;
                cout<<"? "<<leaf1<< " "<<v[j]<< " "<<curr<<endl;
                string sl;
                cin>>sl;
                if(sl=="Yes")curr= v[j];
            }
            leaf1= curr;

        }
        cout<<"! "<<leaf1<<endl; 





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}