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
ll dp[5005][5005];
ll a,b;
ll ans[5005];

ll findans(ll i){
    if(i>=n+1)return 0;
    if(ans[i]>0)return ans[i];
    ll maxi=1e9;
    maxi= min(maxi ,a +findans(i+1));
    fo1(j,n){
        if(dp[i][j]>0 && dp[i][j]+j<=i)maxi=min(maxi, b+ findans(i+j));
    }

    ans[i]=maxi;
    return maxi;
}

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
        //ll a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        char c[n+1];
        fo(i,n)c[i+1]=s[i];
        
        fo(i,n+1)fo(j,n+1)dp[i][j]=0;
        //ll ans=min(a,b);
        for(int i=2;i<=n;i++){
            ll last=0;
            for(int j=i-1;j>0;j--){
                if(c[i]==c[j]){last=j;break;}
            }
            dp[i][1]=last;
            ll j=1;
            ll temp=last;
            while(dp[i][j]!=0 && i+j<=n){
                //if(i==4)cout<<j<<" "<<temp<<endl;
                if(1 ){
                    if(c[temp+ j]==c[i+j]){
                        dp[i][j+1]=temp;
                        j++;
                    }
                    else{
                        temp=dp[temp][j];
                    }
                }
                else{
                    temp=dp[temp][j];
                }
                if(temp==0)break;
            }


        }
        fo(i,n+1){fo(j,n+1)if(dp[dp[i][j]][j]!=0)dp[i][j]=dp[dp[i][j]][j]; }
        //fo(i,n+1){fo(j,n+1)cout<<dp[i][j]<<" ";cout<<endl;}
        fo(i,n+1)ans[i]=0;
        cout<<findans(1);





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}