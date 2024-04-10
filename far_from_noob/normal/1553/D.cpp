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
        string s,str;

        cin>>s>>str;
        set<ll>s1[26],s0[26];
        ll n=s.size();
        fo(i,26)s1[i].insert(mod) ,s0[i].insert(mod);
        fo(i,n){
            if(i%2==0)s0[s[i]-'a'] .insert(i);
            else{
                s1[s[i]-'a'].insert(i);
            }
        }
        m= str.size();
        ll last1[m],last0[m];
        last0[0]=*( s0[str[0]-'a'].lower_bound(0)); 
        last1[0]=*( s1[str[0]-'a'].lower_bound(0));
        //cout<<last0[0]<<" "<<last1[0]<<endl;
        if(last0[0]==mod)last0[0]--;if(last1[0]==mod)last1[0]--;
        fo1(i,m-1){
            last0[i]= *(s0[str[i]-'a'].lower_bound(last1[i-1]));

            last1[i]= *(s1[str[i]-'a'].lower_bound(last0[i-1]));

            if(last0[i]==mod)last0[i]--;if(last1[i]==mod)last1[i]--;
        }
        //cout<<last0[1]<<" "<<last1[1]<<endl;

        if(n%2==1){
            if(last0[m-1]== mod-1  )cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else{
            if(last1[m-1]== mod-1  )cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }



        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}