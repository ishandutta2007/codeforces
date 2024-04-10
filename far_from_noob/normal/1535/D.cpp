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
        cin>>k;
        string s;
        cin>>s;
        n= s.size();
        ll nxt[n];
        ll temp=0;
        vll v[n];
        for(int l=k-1;l>0;l--){
            ll val =(ll)pow(2,l);
            for(int i=temp; i<temp+val;i++){
                //cout<<i<<endl;
                nxt[i]= temp + val + (i-temp)/2 ;
                v[temp + val + (i-temp)/2].pb(i);
            }
            temp+=val;
        }
        ll ans[n];
        temp=(ll)pow(2,k-1);
        fo(i,temp){if(s[i]=='?')ans[i]=2; else ans[i]=1;}
        nxt[n-1]=-1;
        for(int l=k-2;l>=0;l--){
            ll val =(ll)pow(2,l);
            for(int i=temp; i<temp+val;i++){
                if(s[i]=='?')ans[i]=ans[v[i][0]] + ans[v[i][1]];
                else if(s[i]=='0')ans[i]=ans[v[i][0]];
                else ans[i]=ans[v[i][1]];
            }
            temp+=val;
        }

        cin>>q;
        fo(i,q){
            ll x; char c;
            temp = (ll)pow(2,k-1);
            cin>>x>>c; x--;
            s[x]=c;
            while(x != -1 ){
                c=s[x];
                if(v[x].size()==0){
                    if(c=='?')ans[x]=2;
                    else ans[x]=1;
                }

                else{
                    if(c=='?')ans[x]=ans[v[x][0]] + ans[v[x][1]];
                    else if(c=='0')ans[x]=ans[v[x][0]];
                    else ans[x]=ans[v[x][1]];
                }
                x=nxt[x];
            }
            cout<<ans[n-1]<<endl;
        }



        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}