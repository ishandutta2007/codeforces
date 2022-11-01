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
ll vv[1000005];
ll ifused[20000004];
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
    vector<ll>prime;
    
    fo(i,20000004)ifused[i]=0;
    for(ll i=2;i<20000004;i++){
        if(ifused[i]>=1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=20000003){
            ifused[j]++;
            j+=i;
        }
    }
    ll po[40];
    fo(i,40)po[i]=(ll)pow(2,i);
    fo1(i,500000){
        ll cc=0;
        ll val = i;
            //cout<<val<<" ";
        ll temp=0;
            ll kk =sqrt(val)+1;
            while(prime[temp]<kk){
                if(val%prime [temp]==0)cc++;
                else {temp++; continue;}
                while(val%prime[temp] ==0 )val/=prime[temp];
                temp++;
            }
            if(val>1)cc++;
            vv[i]=  po[cc];
    }
    
    while(t--){
        ll c,d,x;
        cin>>c>>d>>x;
        int i=1;
         vll v;
         while(i*i<=x){
            if(i*i ==x){v.pb(i); break;}
            if(x%i==0 ){
                v.pb(i);
                v.pb(x/i);
            }
            i++;
         }
         ll ans=0;
         // fo(i,v.size()){
         //    if(c>v[i]){
         //        if(d%(c-v[i])==0 && (x/v[i])%(d/(c-v[i]) ) ==0  )ans++;
         //    }
         // }
         fo(i,v.size()){
            //cout<<v[i];
            //continue;
            ll val = d+ v[i];
            if(val%c!=0)continue;
            val/=c;
            ll temp=0;
            ll cc=ifused[val];
                        //cout<<val<<" ";
            // ll kk =sqrt(val)+1;
            // while(prime[temp]<kk){
            //     if(val%prime [temp]==0)cc++;
            //     else {temp++; continue;}
            //     while(val%prime[temp] ==0 )val/=prime[temp];
            //     temp++;
            // }
            // if(val>1)cc++;
            ans+= po[cc];
         }
         cout<<ans<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}