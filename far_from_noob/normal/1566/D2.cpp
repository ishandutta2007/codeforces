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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n>>m;
        ll a[n*m];
        ll seat[n][m];

        fo(i,n*m)cin>>a[i];
        vll v;
        map<ll,ll>m1;
        ll temp=1;
        fo(i,n*m){v.pb(a[i]);}
        sort(all(v));
        fo(i,n*m){
            if(m1[v[i]]==0){m1[v[i]]=temp; temp++;}
            //cout<<v[i]<<" "<<m1[v[i]]<<" ";
        }
        //cout<<endl;
        vll ind[temp];
        fo(i,n*m){a[i]=m1[a[i]]; ind[a[i]].pb(i);}
        //fo(i,n*m)cout<<a[i]<<" ";cout<<endl;

        //cout<<temp<<endl;
        ll last=0;
        fo1(i,temp-1){
            //cout<<ind[i].size()<<endl;
            ll l = last, r= last+ ind[i].size()-1;
            //cout<<l<<" "<<r<<endl;
            if(r/m == l/m  ){
                ll tt=0;
                for(int k=r;k>=l;k--){seat[k/m][k%m]=ind[i][tt]; tt++; }
            }
            else{
                ll x = m - l%m;
                ll y = r%m;
                //cout<<x<< " "<<y<<endl;
                ll tt=0;
                for(int k= l+x-1 ; k>=l;k--){
                    seat[k/m][k%m] = ind[i][tt];
                    tt++;
                }
                for(int k= r-y-1;k>=l+x; k--){
                    seat[k/m][k%m] = ind[i][tt];
                    tt++;
                }
                for(int k =  r;k>=r-y;k--){
                    seat[k/m][k%m] = ind[i][tt];
                    tt++;
                }
            }

            last= r +1;
        }
        fo(i,n){

            //fo(j,m)cout<<seat[i][j]+1<< " ";
            //cout<<endl;
        }
        //cout<<endl;

        ll ans=0;

        fo(i,n)fo(j,m){
            for(int k=0;k<j;k++){
                if(seat[i][k]<seat[i][j])ans++;
            }
        }
        cout<<ans<<endl;







        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}