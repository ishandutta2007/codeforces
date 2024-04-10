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
        ll pos[n+1];
        fo(i,n){cin>>a[i]; pos[a[i]]=i;}
        vector<vll>vans;
        if(n==1){cout<<0<<endl; return 0;}
        //cout<<2342;
        while(1){
            //cout<<455;
            ll vv=1;
            for(int i1=1;i1<=n;i1++){

                int i=a[i1-1];
                if(i==n)continue;
                if(pos[i+1]<pos[i]){
                    //cout<<3423;
                    vll v;
                    if(pos[i+1]>0)v.pb(pos[i+1]);
                    ll kk=1,tt=i+1,ind=pos[i+1]+1;
                    while(ind<n){
                        //break;
                        //if(i==4)cout<<a[ind]<<" "<<tt+1<<endl;
                        if(a[ind]==tt+1){kk++; ind++; tt++;}
                        else break;
                    }
                    //cout<<kk<<endl;
                    v.pb(kk);
                    v.pb(pos[i]-pos[i+1]+1-kk);
                    //v.pb(1);
                    //v.pb(pos[i]-pos[i+1]);
                    if(pos[i]!=n-1)v.pb(n-1-pos[i]);
                    ll b[n];
                    ll temp=0;
                    ll val=0;
                    for(int j=v.size()-1;j>=0;j--){
                        val+=v[j];
                        //cout<<val;
                        for(int l=0;l<v[j];l++){
                            
                            //cout<<n-val+l<<" ";
                            b[temp]=a[n-val+l];
                            temp++;
                        }
                        //val+=v[j];
                    }
                    vans.pb(v);
                    //cout<<i<<endl;
                    fo(i,n){a[i]=b[i]; pos[b[i]]=i; }
                    //cout<<endl;
                    vv=0;
                    break;
                }
                //cout<<34;
            }
            if(vv==0)continue;
            //cout<<234;
            break;
        }
        cout<<vans.size()<<endl;
        fo(i,vans.size()){
            cout<<vans[i].size()<<" ";
            fo(j,vans[i].size())cout<<vans[i][j]<<" ";
            cout<<endl;
        }






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}