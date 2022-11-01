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
        ll a[n];
        ll sum1=0, i1,i2;
        fo(i,n)cin>>a[i],sum1+=a[i];
        cin>>m;
        ll b[m],sum2=0;
        fo(i,m)cin>>b[i],sum2+=b[i];
        ll min1=1e18,min2=1e18;
        set<pair<ll,pll> >s;
        set<pll>s1;
        fo(i,m)s1.insert(mp(b[i],i));
        s1.insert({-1e18,-1});
        s1.insert({1e18,-1});
        s.insert(mp(-1e18,mp(-1,-1)));
        s.insert(mp(1e18,mp(-1,-1)));
        fo(i,m){
            fo(j,i){
                if(i==j)continue;
                s.insert(mp(b[i]+b[j],mp(i,j)));
            }
        }
        ll in1,in2,in3,in4;
        fo(i,n){
            ll temp=a[i]- (sum1-sum2)/2;
            auto it=s1.upper_bound(mp(temp,-1));
            pll p=*it;
            if(min1> abs(sum1-2*a[i] -sum2 + 2*p.fi) ){
                min1=abs(sum1-2*a[i] -sum2 + 2*p.fi);
                i1=i;
                i2=p.se;
            }
            it--;
            p=*it;
            if(min1> abs(sum1-2*a[i] -sum2 + 2*p.fi) ){
                min1=abs(sum1-2*a[i] -sum2 + 2*p.fi);
                i1=p.se;
            }

        }
        fo(i,n){
            fo(j,i){
                if(i==j)continue;
                ll temp=a[i]+a[j]- (sum1-sum2)/2;
                auto it=s.upper_bound(mp(temp,mp(-1,-1)));
                pair<ll,pll>p=*it;
                if(min2> abs(sum1 -2*a[i]-2*a[j] -sum2 +2*p.fi)){
                    min2=abs(sum1 -2*a[i]-2*a[j] -sum2 +2*p.fi);
                    in1=i;
                    in2=j;
                    in3=p.se.fi;
                    in4=p.se.se;

                }
                it--;
                p=*it;
                if(min2> abs(sum1 -2*a[i]-2*a[j] -sum2 +2*p.fi)){
                    min2=abs(sum1 -2*a[i]-2*a[j] -sum2 +2*p.fi);
                    in1=i;
                    in2=j;
                    in3=p.se.fi;
                    in4=p.se.se;

                }
            }    
        }
        if(abs(sum1-sum2)<=min1 && abs(sum1-sum2)<=min2){
            cout<<abs(sum1-sum2)<<endl;
            cout<<0<<endl;
        }
        else if(min1<=min2){
            cout<<min1<<endl;
            cout<<1<<endl;
            cout<<i1+1<<" "<<i2+1<<endl;
        }
        else{
            cout<<min2<<endl<<2<<endl;
            cout<<in1+1<<" "<<in3+1<<endl;
            cout<<in2+1<<" "<<in4+1<<endl;
        }





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}