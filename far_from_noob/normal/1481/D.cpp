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
        cin>>n;
        cin>>k;
        char c[n][n];
        fo(i,n)fo(j,n)cin>>c[i][j];
        ll i1=-1,i2;
        fo(i,n)fo(j,n){
            if(i!=j && c[i][j]==c[j][i])i1=i+1,i2=j+1;
        }
        if(i1!=-1){cout<<"YES"<<endl;
        fo(i,k+1){if(i%2==1)cout<<i1<<" "; else cout<<i2<<" ";} cout<<endl; continue;}

        if(k%2==1){i1 =1; i2=2;cout<<"YES"<<endl;
        fo(i,k+1){if(i%2==1)cout<<i1<<" "; else cout<<i2<<" ";} cout<<endl; continue;}

        if(n==2){cout<<"NO"<<endl; continue;}
        ll val1=0,val2=0,val3=0;
        fo(i,n){
            ll c1=0,c2=0;
            fo(j,n){if(c[i][j]=='a')c1++; else if(c[i][j]=='b')c2++;}
            if(c1!=0 && c1!=n-1){
                val1=i+1;
                fo(j,n){
                    if(c[i][j]=='a'){
                        val2=j+1;
                        
                    }
                }
            
                
                fo(j,n){
                    if(c[j][i]=='a'){
                        val3=j+1;
                    }
                }
            }
            if(val1!=0)break;
        }
        cout<<"YES"<<endl;
        
        fo(i,k/2 ){
            if((k/2 -i )%2 ==1)cout<<val2<<" ";
            else cout<<val1<<" ";
        }
        cout<<val1<<" ";
        fo(i,k/2 ){
            if(i %2 ==0)cout<<val3<<" ";
            else cout<<val1<<" ";
        }
        cout<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}