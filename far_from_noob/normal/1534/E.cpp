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
        ll c1=0,c2=0;
        ll n1=n,k1=k;
        while(n1%2==0){c1++; n1/=2;}
        while(k1%2==0){c2++; k1/=2;}
        if(c1 ==0 && c2>0){cout<<-1<<endl; return 0;}
        //cout<<c1<<c2<<endl;
        //break;
        ll minans=1;
        ll count[n+1];
        while(1){
            if(k*minans <n || k*minans%2 != n%2){minans++; continue;}
            ll kk;
            if((minans-1)%2==0)kk = minans-1; else kk=minans-2;
            if(n * kk < (k*minans -n)){minans++; continue;}
            else{
                fo1(i,n)count[i]=1;
                ll val= k*minans - n;
                fo1(i,n){
                    count[i]+= min(kk , val);
                    val-=min(kk,val);
                }
                break;
            }

        }

        //fo1(i,n)cout<<count[i];cout<<endl;
        vector<pll>v;
        fo1(i,n)v.pb(mp(-1*count[i],i));
        fo1(i,n){
            //cout<<v[i].fi<<" "<<v[i].se<<endl;
        }
        ll ans=0;
        fo(i,minans){
            sort(all(v));
            cout<<"? ";
            fo(j,k){
                cout<<v[j].se<<" ";
                v[j].fi++;
            }
            cout<<endl;
            cin>>m;
            ans=ans^m;
        }   
        cout<<"! "<<ans<<endl;


        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}