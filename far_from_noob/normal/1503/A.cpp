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
        string s1,s2;
        fo(i,n)s1.pb('0'),s2.pb('0');
        ll c1=0,c2=0,t1=0,t2=0;
        ll cc=0;
        fo(i,n)if(s[i]=='1')cc++;
        if(cc%2==1){cout<<"NO"<<endl; continue;}
        flag=0;
        ll kk=0;
        fo(i,n){
            if(s[i]=='1'){
                if(kk<cc/2){
                    s1[i]='(';s2[i]='(';
                }
                else s1[i]=')',s2[i]=')';
                kk++;
                //cout<<cc/2<<" "<<kk<<endl;
            }
        }
        fo(i,n){
            if(s[i]=='1'){
                if(s1[i]=='(')t1++,t2++;
                else t1--,t2--;

            }
            else{
                if(t1<=t2){s1[i]='(';s2[i]=')'; t1++; t2--;}
                else {s1[i]=')';s2[i]='('; t1--; t2++;}
            }
            //cout<<t1<<t2<<endl;
            if(t1<0 || t2<0)flag=1;
        }
        if(flag){cout<<"NO"<<endl; continue;}
        cout<<"YES"<<endl;
        cout<<s1<<endl;
        cout<<s2<<endl;
        





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}