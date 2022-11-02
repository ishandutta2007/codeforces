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
ll mod=998244353 ;
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
    ll fac[100005];
    ll infac[100005];
    fac[0]=1;
    fo(i,100003){
        fac[i+1]=fac[i]*(i+1)%mod;
    }
    infac[0]=1;
    infac[1]=1;
    for(int i=2;i<100003;i++){
        infac[i]=infac[i-1]*power(i,mod-2)%mod;
    }
    while(t--){
        ll  l1=0,l2=0,r1=0,r2=0;
        ll ans=0;
        cin>>n;
        string str[n];
        fo(i,n){
            string s;
cin>>s;
            str[i]=s;
            
            if(s[0]=='W')l2++;if(s[0]=='B')l1++;
            if(s[1]=='W')r2++;if(s[1]=='B')r1++;
        }
        //cout<<l1<<l2<<r1<<r2<<endl;
        for(int i = l1 ;i<= n-l2 ; i++){
            if( (n-i) >= r1 && (i)>= r2  );
            else continue;
            ll val1 = fac[n-l1-l2]*infac[i-l1]%mod*infac[n-l2 -i]%mod;
            //cout<<i << " "<<val1<<endl;
            ll val2 = fac[n-r1-r2]*infac[i-r2]%mod*infac[n-r1-r2  -i+r2]%mod;
            //cout<<i << " "<<val2<<endl;
            ans+= val1*val2;
            ans%=mod;
            //cout<<i<<endl;
        }
        int temp1=1,temp2=1;
        ll kk =1;
        fo(i,n){
            if(str[i][0]=='W' || str[i][1]=='B')temp1=0;
            if(str[i][0]=='B' || str[i][1]=='W')temp2=0;

            if(str[i][0]=='?' && str[i][1]=='?')kk*=2;
            else if(str[i][0]==str[i][1]){kk=0; }
            kk%=mod;
            //cout<<kk<<endl;
        }
        //cout<<kk;
        cout<<(ans +temp1+temp2 -kk + mod +mod)%mod;



        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}