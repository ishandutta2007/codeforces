#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
//#define endl "\n"
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
        cin>>n;
        cin>>k;
        vll v[k];
        map<ll,ll>m1;
        fo(i,k){
            cin>>m;
            fo(j,m){
                ll pp;
                cin>>pp;
                v[i].pb(pp);
                m1[pp]=1;
            }
        }
        vll temp;
        fo1(i,n){
            if(m1[i]==0)temp.pb(i);
        }
        ll ans[k];
        cout<<"?"<<" "<< n<<" ";
        fo(i,n){
            cout<<i+1<<" ";

        }
        cout<<endl;
        ll maxi;
        cin>>maxi;
        ll l=0,r=k-1;
        while(l!=r){
            //cout<<l<<" "<<r<<endl;
            vll kk=temp;
            ll mid=(l+r)/2;
            for(int i=l;i<=mid;i++){
                fo(j,v[i].size())kk.pb(v[i][j]);
            }
            cout<<"?"<<" "<<kk.size()<<" ";
            fo(i,kk.size())cout<<kk[i]<<" ";
            cout<<endl;
            ll zz;
            cin>>zz;
            if(zz==maxi){
                for(int i=mid+1;i<=r;i++)ans[i]=maxi;
                r=mid;
            }
            else{
                for(int i=l;i<=mid;i++)ans[i]=maxi;
                l=mid+1;
            }
            
        }
        vll kk=temp;
        fo(i,k){
            if(i==l)continue;
            fo(j,v[i].size())kk.pb(v[i][j]);
        }
        cout<<"?"<<" "<<kk.size()<<" ";
        fo(i,kk.size())cout<<kk[i]<<" ";
        cout<<endl;
        cin>>ans[l];
        cout<<"! ";
        fo(i,k)cout<<ans[i]<<" ";
        cout<<endl;
        string tt;
        cin>>tt;
        




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}