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
        char a[n][m];
        fo(i,n)fo(j,m)cin>>a[i][j];
        vector<vll>v;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j+=2){

                if(a[i][j]=='0' && a[i][j+1]=='0')continue;
                vll v1;
                v1.pb(i+1);
                v1.pb(j);
                a[i+1][j]='1'+'0'-a[i+1][j];

                if(a[i][j]=='1' && a[i][j+1]=='0'){
                    v1.pb(i);
                    v1.pb(j);
                    v1.pb(i+1);
                    v1.pb(j+1);
                    a[i+1][j+1]='1'+'0'-a[i+1][j+1];
                }
                else if(a[i][j]=='0' && a[i][j+1]=='1'){
                    v1.pb(i);
                    v1.pb(j+1);
                    v1.pb(i+1);
                    v1.pb(j+1);
                    a[i+1][j+1]='1'+'0'-a[i+1][j+1];
                }
                else {
                    v1.pb(i);
                    v1.pb(j);
                    v1.pb(i);
                    v1.pb(j+1);
                }
                a[i][j]='0';a[i][j+1]='0';
                v.pb(v1);
                //cout<<i<<j<<endl;
                //fo(i,n){fo(j,m)cout<<a[i][j]; cout<<endl;}cout<<endl;
            }
        }
        //fo(i,n){fo(j,m)cout<<a[i][j]; cout<<endl;}

        if(n%2==1 && m%2==1){
            if(a[n-1][m-1]=='1'){
                //cout<<444<<endl;
                vll v1;
                v1.pb(n-1);
                v1.pb(m-1);
                v1.pb(n-2);
                v1.pb(m-1);
                v1.pb(n-1);
                v1.pb(m-2);
                v.pb(v1);
                a[n-1][m-1]='0';
                a[n-2][m-1]='1'+'0'-a[n-2][m-1];
                a[n-1][m-2]='1'+'0'-a[n-1][m-2];
            }

        }
            if(m%2==1)for(int i=0;i<n-1;i+=2){
                if(i==n-2){
                    if(a[i][m-1]=='1' && a[i+1][m-1]=='1'){
                    vll v1;
                    v1.pb(i+1);v1.pb(m-2);v1.pb(i+1);v1.pb(m-1);v1.pb(i);v1.pb(m-1);
                    v.pb(v1);
                    a[i+1][m-2]='1'+'0'-a[i+1][m-2];
                    
                }
                else if(a[i][m-1]=='0' && a[i+1][m-1]=='1'){
                    vll v1;
                    v1.pb(i);v1.pb(m-2);v1.pb(i);v1.pb(m-1);v1.pb(i+1);v1.pb(m-1);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(i);v1.pb(m-2);v1.pb(i);v1.pb(m-1);v1.pb(i+1);v1.pb(m-2);
                    v.pb(v1);
                    a[i+1][m-2]='1'+'0'-a[i+1][m-2];
                }
                else if(a[i][m-1]=='1' && a[i+1][m-1]=='0'){
                    vll v1;
                    v1.pb(i);v1.pb(m-2);v1.pb(i+1);v1.pb(m-1);v1.pb(i);v1.pb(m-1);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(i);v1.pb(m-2);v1.pb(i+1);v1.pb(m-1);v1.pb(i+1);v1.pb(m-2);
                    v.pb(v1);
                    a[i+1][m-2]='1'+'0'-a[i+1][m-2];
                }
                    continue;
                }
                if(a[i][m-1]=='1' && a[i+1][m-1]=='1'){
                    vll v1;
                    v1.pb(i);v1.pb(m-2);v1.pb(i+1);v1.pb(m-2);v1.pb(i);v1.pb(m-1);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(i);v1.pb(m-2);v1.pb(i+1);v1.pb(m-2);v1.pb(i+1);v1.pb(m-1);
                    v.pb(v1);
                }
                else if(a[i][m-1]=='0' && a[i+1][m-1]=='1'){
                    vll v1;
                    v1.pb(i);v1.pb(m-2);v1.pb(i+1);v1.pb(m-2);v1.pb(i+1);v1.pb(m-1);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(i);v1.pb(m-1);v1.pb(i+1);v1.pb(m-2);v1.pb(i+1);v1.pb(m-1);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(i);v1.pb(m-2);v1.pb(i);v1.pb(m-1);v1.pb(i+1);v1.pb(m-1);
                    v.pb(v1);
                }
                else if(a[i][m-1]=='1' && a[i+1][m-1]=='0'){
                    vll v1;
                    v1.pb(i);v1.pb(m-2);v1.pb(i+1);v1.pb(m-2);v1.pb(i);v1.pb(m-1);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(i);v1.pb(m-1);v1.pb(i+1);v1.pb(m-2);v1.pb(i+1);v1.pb(m-1);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(i);v1.pb(m-2);v1.pb(i);v1.pb(m-1);v1.pb(i+1);v1.pb(m-1);
                    v.pb(v1);
                }
                //a[i][m-1]=0;  a[i+1][m-1]=0;
            }

        
            for(int i=0;i<m-1;i+=2){
                if(a[n-1][i]=='1'  && a[n-1][i+1]=='1'){
                    vll v1;
                    v1.pb(n-2);v1.pb(i);v1.pb(n-2);v1.pb(i+1);v1.pb(n-1);v1.pb(i);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(n-2);v1.pb(i);v1.pb(n-2);v1.pb(i+1);v1.pb(n-1);v1.pb(i+1);
                    v.pb(v1);
                }
                else if(a[n-1][i]=='0' && a[n-1][i+1]=='1'){
                    vll v1;
                    v1.pb(n-2);v1.pb(i);v1.pb(n-1);v1.pb(i+1);v1.pb(n-1);v1.pb(i);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(n-2);v1.pb(i);v1.pb(n-2);v1.pb(i+1);v1.pb(n-1);v1.pb(i+1);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(n-1);v1.pb(i);v1.pb(n-2);v1.pb(i+1);v1.pb(n-1);v1.pb(i+1);
                    v.pb(v1);
                }
                else if(a[n-1][i]=='1' && a[n-1][i+1]=='0'){
                    vll v1;
                    v1.pb(n-2);v1.pb(i);v1.pb(n-1);v1.pb(i+1);v1.pb(n-1);v1.pb(i);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(n-2);v1.pb(i);v1.pb(n-2);v1.pb(i+1);v1.pb(n-1);v1.pb(i);
                    v.pb(v1);
                    v1.clear();
                    v1.pb(n-1);v1.pb(i);v1.pb(n-2);v1.pb(i+1);v1.pb(n-1);v1.pb(i+1);
                    v.pb(v1);
                }
            }
            
            cout<<v.size()<<endl;
            fo(i,v.size()){
                fo(j,6)cout<<v[i][j]+1<<" ";
                cout<<endl;
            }
        
        





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}