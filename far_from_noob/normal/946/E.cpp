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
        string s;
        cin>>s;
        ll a[10]={0};
        fo(i,s.size()){
            a[s[i]-'0']++;
        }
        ll temp=0;
        for(int i=s.size()-1;i>0;i--){
            a[s[i]-'0']--;
            flag=-1;
            vll v;
            for(int j=s[i]-'0' -1 ;j>=0;j--){
                a[j]++;
                //if(t==3)cout<<j<<endl;
                fo(i,10)if(a[i]%2==1)v.pb(i);
                if(s.size()%2==0){
                    if(v.size()<=temp){flag=j; break;}
                }
                else if(s.size()%2==1){
                    if(v.size()-1 <= temp){flag=j; break;}
                }
                a[j]--;
                v.clear();
            }
            if(flag>=0){
                fo(j,i)cout<<s[j];
                cout<<flag;
                if(s.size()%2==0){
                    fo(j,temp- v.size())cout<<9;
                    fo(j,v.size())cout<<v[v.size()-1-j];
                }
                
                //cout<<999;
                break;
            }

            temp++;
        }
        if(flag==-1){
            if(s[0]=='1')fo(i,s.size()-2)cout<<9;
            else{
                char c=s[0]-1;
                if(s.size()%2==0){cout<<c; fo(i,s.size()-2)cout<<9; cout<<c;}
                else{cout<<c; fo(i,s.size()-1)cout<<9; }
            }
        }
        cout<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}