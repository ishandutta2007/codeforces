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
        ll d;
        cin>>n>>d>>m;
        ll a[n];
        fo(i,n)cin>>a[i];
        ///ll ans[n+1];
        //ans[n]=0;
        vll v1,v2;
        for(int i=n-1;i>=0;i--){
            if(a[i]<=m)v1.pb(a[i]);
            else v2.pb(a[i]);
        }
        sort(all(v1));
        sort(all(v2));
        ll maxi=0;
        fo(i,v1.size()){
            maxi+=v1[i];
        }
        if(v1.size()==n){cout<<maxi<<endl; return 0;}
        ll ans= v2[v2.size()-1];
        v2.pop_back();
        ll temp=0;
        //cout<<maxi<<endl;
        ll last=maxi;
        ll kk=(n-1)/(d+1);
        ll pp=0;
        if(v2.size()*d >= v1.size()){
            //cout<<kk<<v2.size();
            int po=v2.size()-kk;
            for(int i=v2.size()-1;i>=po;i--)pp+=v2[i];
                maxi=max(maxi,pp);
        }
        if(v1.size()>0);
        else {cout<<maxi+ ans<<endl; return 0;}
        ll pre[v1.size()];
        pre[0]=v1[0];
        fo1(i,v1.size()-1)pre[i]=pre[i-1]+v1[i];
        //cout<<maxi+ans<<endl;
        for(int i=(int)v2.size()-1;i>=0;i--){
             last=last+ v2[i];
            if((v2.size()-i)*d<=v1.size()+ i){
               
                //temp+=d;
                if((v2.size()-i)*d>i)maxi=max(maxi,last- pre[(v2.size()-i)*d- i-1]);

                else maxi=max(maxi,last);
                //cout<<maxi<<endl;
                //cout<<pre[(v2.size()-i)*d- i-1]<<endl;
            }
        }
        cout<<ans+maxi<<endl;


        





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}