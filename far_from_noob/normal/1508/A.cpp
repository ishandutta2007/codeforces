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
        string s[3];
        fo(i,3)cin>>s[i];
        ll  c0=0,c1=0,c2=0;
        fo(i,2*n){
            if(s[0][i]=='1')c0++;
            if(s[1][i]=='1')c1++;
            if(s[2][i]=='1')c2++;
        }
        //cout<<c1<<c2<<c0<<endl;
        flag=0;
        ll l1,l2;
        if(c0>=n && c1>=n)l1=0,l2=1;
        else if(c2>=n && c1>=n)l1=1,l2=2;
        else if(c0>=n && c2>=n)l1=0,l2=2;
        else{
            flag=1;
            if(c0<n && c1<n)l1=0,l2=1;
            else if(c2<n && c1<n)l1=1,l2=2;
            else if(c0<n && c2<n)l1=0,l2=2;
            ll temp1=0,temp2=0;
            string ans;
            //cout<<l1<<l2<<endl;
            //break;
            fo(i,n){
                for(; temp1<2*n;temp1++){
                    if(s[l1][temp1]=='0'){
                        temp1++;
                        break;
                    }
                    ans.pb(s[l1][temp1]);
                }
                for(; temp2<2*n;temp2++){
                    if(s[l2][temp2]=='0'){
                        ans.pb(s[l2][temp2]);
                        temp2++;
                        break;
                    }
                    ans.pb(s[l2][temp2]);
                }
                //break;
            }
            //cout<<temp1<<temp2<<endl;
            for(;temp1<2*n;temp1++)ans.pb(s[l1][temp1]);
            for(;temp2<2*n;temp2++)ans.pb(s[l2][temp2]);
            cout<<ans;
        }    
        if(flag ==0){
            ll temp1=0,temp2=0;
            string ans;
            //cout<<l1<<l2<<endl;
            //break;
            fo(i,n){
                for(; temp1<2*n;temp1++){
                    if(s[l1][temp1]=='1'){
                        temp1++;
                        break;
                    }
                    ans.pb(s[l1][temp1]);
                }
                for(; temp2<2*n;temp2++){
                    if(s[l2][temp2]=='1'){
                        ans.pb(s[l2][temp2]);
                        temp2++;
                        break;
                    }
                    ans.pb(s[l2][temp2]);
                }
                //break;
            }
            //cout<<temp1<<temp2<<endl;
            for(;temp1<2*n;temp1++)ans.pb(s[l1][temp1]);
            for(;temp2<2*n;temp2++)ans.pb(s[l2][temp2]);
            cout<<ans;

        }    

        cout<<endl;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}