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
    vector<ll>prime;
    map<ll ,ll>ifused;
    for(ll i=2;i<100005;i++){
        if(ifused[i]==1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=100000){
            ifused[j]=1;
            j+=i;
        }
    }
    cin>>t;
    //t=1;
    while(t--){
        ll p,q;
        cin>>p>>q;
        if(q>p || p%q!=0 ){cout<<p<<endl; continue;}
        map<ll,ll>m1;
        vll v;
        for(int i=0; prime[i]<50000;i++){
            if(q%prime[i]!=0)continue;
            v.pb(prime[i]);
            while(q%prime[i]==0){
                q/=prime[i];
                m1[prime[i]]++;
            }
        }
        if(q>1){
            v.pb(q);
            m1[q]++;
        }
        ll maxi=1;
        fo(i,v.size()){
            ll p1=p;
            ll val=0;

            while(p1%v[i]==0){
                val++;
                p1/=v[i];
            }
            p1=p;
            fo(j,val-m1[v[i]]+1)p1/=v[i];
            maxi=max(maxi,p1);
        }
        cout<<maxi<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}