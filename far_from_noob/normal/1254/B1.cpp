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
    vector<ll>prime;
    map<ll ,ll>ifused;
    for(ll i=2;i<100005;i++){
        if(ifused[i]==1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=100005){
            ifused[j]=1;
            j+=i;
        }
    }
    while(t--){
        cin>>n;
        ll a[n];
        //fo(i,n)
        ll sum=0;
        fo(i,n)cin>>a[i],sum+=a[i];
        ll temp=1;
        vll v;
        ll ans=1e12;
        for(;temp<=sqrt(n);temp++){
            if(sum%temp==0){
                v.pb(sum/temp);
                if(temp==1)continue;
                vll kk;
                ll count=0;
                fo(i,n){
                    if(a[i]==1){count++;
                    if(count%temp ==(temp+1)/2)kk.pb(i);}
                }
                ll val=0;
                count=0;
                fo(i,n){
                    if(a[i]==1){
                        val+=abs(i- kk[count/temp]);
                        count++;

                    }
                }
                ans=min(ans, val);

            }
        }
        //cout<<v[0];
        fo(j,v.size()){
            temp=v[j];
            if(temp==1)continue;
            vll kk;
                ll count=0;
                fo(i,n){
                    if(a[i]==1){count++;
                    if(count%temp ==(temp+1)/2)kk.pb(i);}
                }
                ll val=0;
                count=0;
                //cout<<kk[0];
                fo(i,n){
                    if(a[i]==1){
                        val+=abs(i- kk[count/temp]);
                        count++;

                    }
                }
                ans=min(ans, val);
        }
        if(ans==1e12)cout<<-1<<endl;
        else cout<<ans;







        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}