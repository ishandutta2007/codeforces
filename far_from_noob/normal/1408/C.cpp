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
        int l;
        cin>>n>>l;
        ll a[n];
        map<ll,ll>m1;
        fo(i,n)cin>>a[i],m1[a[i]]++;
        int i=0,j=l;
        dd s1=1,s2=1;
        dd t1=0,t2=l;
        cout.precision(20);
        while(t2-t1>.0000001){
            dd mid=(t1+t2)/2;
            s1=1;
            dd pos1=0;
            dd time=mid;
            fo(i,n){
                if(a[i]-pos1<= time*s1){
                    time-=(dd)(a[i]-pos1)/s1;
                    s1++;
                }
                else break;
                pos1=a[i];
            }
            pos1+= time*s1;
            s2=1;
            dd pos2=l;
            time=mid;
            for(int i= n-1;i>=0;i--){
                if(pos2-a[i]<= time*s2){
                    time-=(dd)(pos2-a[i])/s2;
                    s2++;
                }
                else break;
                pos2=a[i];
            }
            pos2-= time*s2;

            if(pos1>pos2){
                t2=mid;
            }
            else t1=mid;

            //if(t==3)cout<<t1<<" "<<t2<<endl;
            //break;


        }
        cout<<(t1+t2)/2<<endl;
        


        





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}