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

ll root[200005];
ll findroot(ll node){
    if(root[node]==node)return node;
    root[node]=root[root[node]];
    return findroot(root[node]);
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
        cin>>m;
        set<ll>s[m+1];
        ll a[n];
        fo(i,n){
            cin>>a[i];
            s[a[i]].insert(i+1);
        }
        ll ans=n-1;
        fo1(i,m){
            auto it=s[i].begin();
            s[i].insert(mod);
            ll val=*it;
            while(*it !=mod){
                it++;
                if(*it==val+1)ans--;
                val=*it;
            }
        }
        //ll root[m+1];
        cout<<ans<<endl;
        fo(i,m+1)root[i]=i;
        fo(i,m-1){
            ll a,b;
            cin>>a>>b;
            a=findroot(a);
            b=findroot(b);
            //cout<<a<<b<<endl;
            if(s[a].size()< s[b].size()){
                swap(a,b);
            }
            auto it=s[b].begin();
            s[b].insert(mod);
            auto it2=s[a].begin();
            //cout<<*it2<<endl;
            while(*it !=mod){
                ll val=*it;
                //cout<<val<<" ";
                it2=s[a].lower_bound(val-1);
                if(*it2 == val-1)ans--;
                //cout<<*it2<<" ";
                it2=s[a].lower_bound(val+1);
                if(*it2 == val+1)ans--;
                //cout<<*it2<<endl;
                it++;
            }
            it=s[b].begin();
            while(*it !=mod){
                ll val=*it;
                s[a].insert(val);
                it++;
            }
            root[b]=a;
            cout<<ans<<endl;
        }






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}