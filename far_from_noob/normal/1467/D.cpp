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
ll val[5005][5005];
//ll b[5005][5005];
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
        cin>>n>>k>>q;
        fo(i,5003)fo(j,5003)val[i][j]=0;
        fo(i,n)val[i][1]=1;

        fo1(i,k){
            fo(j,n){
                if(j>0){val[j-1][i+1]+=val[j][i]; val[j-1][i+1]%=mod;}
                if(j<n-1){val[j+1][i+1]+=val[j][i]; val[j+1][i+1]%=mod;}
            }
        }
        ll f[n];
        fo(i,n)f[i]=0;
        for(int j=k+1;j>=1;j--){
            fo(i,n){
                if(j==k+1){
                    f[i]+=val[i][j];
                    //cout<<val[i][j]<<" ";
                    val[i][j]=1;
                    f[i]%=mod;
                }
                else{
                    if(i>0)f[i]+= (val[i][j]*val[i-1][j+1])%mod;
                    if(i<n-1)f[i]+=(val[i][j]*val[i+1][j+1])%mod;
                    f[i]%=mod;
                    val[i][j]=0;
                    if(i>0)val[i][j]+= val[i-1][j+1];
                    if(i<n-1)val[i][j] += val[i+1][j+1];
                    val[i][j]%=mod;
                }
            }
        }
        //fo(i,n)cout<<f[i]<<" ";

        k++;
        ll a[n];
        fo(i,n)cin>>a[i];
        ll sum=0;
        fo(i,n)sum+=(a[i]*f[i])%mod,sum%=mod;
        fo(i,q){
            ll j;
            cin>>j>>m;
            sum = ((sum - f[j-1]*(a[j-1] -m) + mod * 1000000000 )%mod);
            cout<<sum<<endl;
            
            a[j-1]=m; 
        }

        break;

        // if(k%2==0){
        //     multiset<ll>s;
        //     fo(i,n-1)s.insert(a[i]+a[i+1]);
        //     fo(i,q){
        //         ll j; cin>>j; cin>>m;
        //         j--;
        //         if(j>0){auto it= s.lower_bound(a[j]+a[j-1]);
        //             s.erase(it);
        //             s.insert(a[j-1]+m);
        //         } 
        //         if(j<n-1){
        //             auto it= s.lower_bound(a[j]+a[j+1]);
        //             s.erase(it);
        //             s.insert(a[j+1]+m);
        //         }
        //         a[j]=m;
        //         auto it= s.end();
        //         it--;
        //         ll val=*it;
        //         cout<<val*k/2<<endl;
        //     }
        // }
        // else{
        //     multiset<ll>s;
        //     fo(i,n-1){s.insert(a[i]*(k/2)+a[i+1]*(k+1)/2); s.insert(a[i+1]*(k/2)+a[i]*(k+1)/2);}
        //     fo(i,q){
        //         ll j; cin>>j; cin>>m;
        //         j--;
        //         if(j>0){auto it= s.lower_bound(a[j]*(k/2)+a[j-1]*(k+1)/2);
        //             s.erase(it);
        //             s.insert(a[j-1]*(k+1)/2+m*(k/2));
        //             it= s.lower_bound(a[j]*((k+1)/2)+a[j-1]*(k)/2);
        //             s.erase(it);
        //             s.insert(a[j-1]*(k)/2+m*((k+1)/2));
        //         } 
        //         if(j<n-1){
        //             auto it= s.lower_bound(a[j]*(k/2)+a[j+1]*(k+1)/2);
        //             s.erase(it);
        //             s.insert(a[j+1]*(k+1)/2+m*(k/2));
        //             it= s.lower_bound(a[j]*((k+1)/2)+a[j+1]*(k)/2);
        //             s.erase(it);
        //             s.insert(a[j+1]*(k)/2+m*((k+1)/2));
        //         }
        //         a[j]=m;
        //         auto it= s.end();
        //         it--;
        //         ll val=*it;
        //         cout<<val<<endl;
        //     }
        // }





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}