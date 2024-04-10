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
        string s;
        cin>>s;
        ll x,y;
        cin>>x>>y;
        if(x>y){
            swap(x,y);
            reverse(s.begin(),s.end());
        }
        n=s.size();
        map<ll,ll>m1;
        vll v;
        fo(i,n)if(s[i]=='?')m1[i]=1,s[i]='1',v.pb(i);
        ll count1[n],count0[n];
        count1[0]=0;count0[0]=0;
        if(s[0]=='0')count0[0]++;
        else count1[0]++;
        ll ans=0;
        ll val=0;
        ll c1=0,c0=0;
        if(s[0]=='0')c0++;
        else c1++;
        fo1(i,n-1){
            if(s[i]=='1'){c1++; val+=count0[i-1]*x; count1[i]=count1[i-1]+1; count0[i]=count0[i-1];}
            if(s[i]=='0'){c0++; val+=count1[i-1]*y; count1[i]=count1[i-1]; count0[i]=count0[i-1]+1;}

        }
        ans=val;
        //cout<<c0<<c1;
        if(x<=y)fo(i,v.size()){
            if(v[i]>0){val+= (count1[v[i]-1]-i)*y; val-= (count0[v[i]-1]+i)*x ;  }
            val+= (c1-count1[v[i]])*x; val-= (c0-count0[v[i]])*y; 
            ans=min(ans,val);
        }
        cout<<ans;








        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}