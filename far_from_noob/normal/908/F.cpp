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
        cin>>n;
        vll v[3];
        fo(i,n){
            char c;
            cin>>m;cin>>c;
            if(c=='G')v[0].pb(m);
            else if(c=='R')v[1].pb(m);
            else v[2].pb(m);
        }
        ll ans=0;
        if(v[0].size()==0){
            if(v[1].size()>0)ans+=v[1][v[1].size()-1] - v[1][0];
            if(v[2].size()>0)ans+=v[2][v[2].size()-1] - v[2][0];
            cout<<ans<<endl;
            break;
        }
        if(v[1].size()>0){
            if(v[1][0]<v[0][0])ans+=v[0][0]-v[1][0];
            if(v[1][v[1].size()-1]> v[0][v[0].size()-1] )ans+=v[1][v[1].size()-1] - v[0][v[0].size()-1];
        }
        if(v[2].size()>0){
            if(v[2][0]<v[0][0])ans+=v[0][0]-v[2][0];
            if(v[2][v[2].size()-1]> v[0][v[0].size()-1] )ans+=v[2][v[2].size()-1] - v[0][v[0].size()-1];
        }
        ll temp1=0,temp2=0;
        while(temp1<v[1].size()){
            if(v[1][temp1]>v[0][0])break;
            else temp1++;
        }
        while(temp2<v[2].size()){
            if(v[2][temp2]>v[0][0])break;
            else temp2++;
        }
        //cout<<temp1<<temp2<<endl;
        //break;
        for(int i=0;i<v[0].size()-1;i++){
            vll v1 , v2;
            while(temp1<v[1].size()){
                if(v[1][temp1]>v[0][i+1])break;
                else {v1.pb(v[1][temp1]); temp1++;}
            }
            while(temp2<v[2].size()){
                if(v[2][temp2]>v[0][i+1])break;
                else {v2.pb(v[2][temp2]); temp2++;}
            }
            ll mdif1=0,mdif2=0;
            //cout<<v1.size()<<v2.size()<<endl; continue;
            if(v1.size()>0){mdif1= max(v1[0] - v[0][i] , v[0][i+1] - v1[v1.size()-1] );
            fo(i,v1.size()-1)mdif1=max(mdif1, v1[i+1]-v1[i]);}
            if(v2.size()>0){mdif2= max(v2[0] - v[0][i] , v[0][i+1] - v2[v2.size()-1] );
            fo(i,v2.size()-1)mdif2=max(mdif2, v2[i+1]-v2[i]);}

            if(v1.size()==0 && v2.size()==0){
                ans+= v[0][i+1]-v[0][i];
            }
            else if(v1.size()==0)ans+= 2*v[0][i+1]-2*v[0][i]   - mdif2 ;
            else if(v2.size()==0)ans+= 2*v[0][i+1]-2*v[0][i]   - mdif1 ;
            else ans+= min(2*v[0][i+1]-2*v[0][i] , 3*v[0][i+1]-3*v[0][i] - mdif1-mdif2 );
        }
        cout<<ans<<endl;







        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}