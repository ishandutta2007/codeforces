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
vll v[300005];
ll val[300005];
ll ans;

void findans(ll node, ll root){
    ll sum=1;
    vll temp;
    fo(i,v[node].size()){
        if(v[node][i]==root)continue;
        findans(v[node][i], node);
        temp.pb(val[v[node][i]]);
    }
    sort(all(temp));
    if(temp.size()==0){
        ans=max(ans,sum);
    }
    else if(temp.size()==1){
        sum+=temp[0];
        if(node==root)ans=max(ans,sum);
    }
    else{
        sum+=temp[temp.size()-1]+ temp.size()-1;
        if(node!=root)ans=max(ans, sum+ temp[temp.size()-2]);
        else ans=max(ans, sum+ temp[temp.size()-2]-1);
    }
    val[node]=sum;
    //cout<<node<<" "<<val[node]<<endl;

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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n;
        fo(i,n-1){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        ans=0;
        findans(1,1);
        cout<<ans<<endl;
        fo1(i,n){
            v[i].clear();
        } 





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}