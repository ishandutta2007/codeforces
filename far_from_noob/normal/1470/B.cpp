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
    for(ll i=2;i<10005;i++){
        if(ifused[i]==1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=10000){
            ifused[j]=1;
            j+=i;
        }
    }
    cin>>t;
    //t=1;
    while(t--){
        cin>>n; 
        ll a[n];
        fo(i,n)cin>>a[i];
        map<ll,ll>count;
        vll v;
        fo(i,n){
            int j=0;
            while(prime[j]<1000){
                while(a[i]%(prime[j]*prime[j]) == 0 ){
                    a[i]/=(prime[j]*prime[j]);
                }
                j++;
            }
            count[a[i]]++;
            v.pb(a[i]);
        }
        ll maxi=0,maxi1=0;
        ll sum=0;
        fo(i,v.size()){
            maxi=max(maxi,count[v[i]]);
            if(count[v[i]]%2==0)sum++;
            else maxi1=max(maxi1, count[v[i]]);
        }
        if(count[1]%2==1)sum+=count[1];
        cin>>q;
        fo(i,q){
            ll w;
            cin>>w;
            if(w==0)cout<<maxi<<endl;
            else cout<<max(maxi1, sum)<<endl;
        }






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}