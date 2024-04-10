#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
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
        cin>>n>>k;
        ll m=n;
        n=3;
        ll val1[n],val2[n];

        fo(i,n){
            cout<<"or" <<" "<<i +1<<" "<<(i+1)%n + 1<<endl;
            cin>>val1[i];
        }
        fo(i,n){
            cout<<"and" <<" "<<i +1<<" "<<(i+1)%n + 1<<endl;
            cin>>val2[i];
        }
        ll a[m];
        ll po[30];
        fo(i,30)po[i]=(ll)pow(2,i);
        fo(i,n){
            //cout<<val1[i]<<endl;
            ll val = val1[i]&val1[(i-1+n)%n];
            //cout<<val<<endl;
            a[i]=0;
            fo(j,30){
                if((val/po[j])%2==1){
                    if(((val2[(i+1+n)%n] / po[j]) )%2==1 && ((val2[(i)%n] / po[j]) )%2==0);
                    else a[i]+=po[j];
                }
            }
        }
        //fo(i,3)cout<<a[i];

        for(int i=3;i<m;i++){
            cout<<"and" <<" "<<i <<" "<<i+1<<endl;
            ll and1;cin>>and1;
            cout<<"or" <<" "<<i<<" "<<(i+1)<<endl;
            ll or1;cin>>or1;
            a[i]= or1-a[i-1]+and1;
        }
        sort(a,a+m);
        cout<<"finish"<<" " <<a[k-1]<<endl;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}