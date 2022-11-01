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
        string s;
        cin>>s;
        ll a[n-1];
        ll start =0;
        set<ll> st;
        //st.insert(0);
        fo(i,n-1){
            if(s[i]==s[i+1]){
                st.insert(i+1);
                //cout<<i+1<<endl;
                //en.insert(i+1);
            }
            //else a[i]=1;
        }
        st.insert(0);
        st.insert(n);
        auto it= st.begin();
        if(s[0]=='L')cout<<1<<" ";
        else {
            it++;
            cout<<*it +1<<" " ;
        }
        fo1(i,n-1){
            it= st.lower_bound(i);
            if(*it == i){
                if(s[i]=='R'){
                    it++;
                    cout<<*it- i +1<<" ";
                }
                else{
                    it--; 
                    cout<<i-*it +1<< " ";
                }
            }
            else{
                ll tt= *it;
                it--;
                if(s[i]=='L')cout<<1<< " ";
                else cout<<tt- *it +1<< " ";
            }
        }
        if(s[n-1]=='R')cout<<1<<" ";
        else {
            it=st.lower_bound(n);
            it--; 
            cout<<n-*it+1<<" ";
        }
        cout<<endl;

        // ll val[n+1];
        // ll temp=q;
        // val[0]=1;
        // fo(i,n-1){
            
        //     if(a[i]==0)temp=1;
        //     else temp++;
        //     val[i]=temp;
        // }
        // temp++;
        // val[n]=temp;
        // for(int i=n-1;i>=0;i--){
        //     if(a[i]==1)val[i]=val[i+1];
        // }
        // fo(i,n+1){

        // }





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}