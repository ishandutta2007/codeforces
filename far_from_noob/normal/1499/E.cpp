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
ll mod=998244353;
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
ll a[1003][1003][2];
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
        string s1,s2;
        cin>>s1>>s2;
        n= s1.size(),m=s2.size();
        ll temp1[n],temp2[m];
        ll flag=0;
        temp1[0]=1,temp2[0]=1;
        fo1(i,n-1){if(s1[i]!=s1[i-1])temp1[i]=temp1[i-1]+1;else temp1[i]=1;}
        fo1(i,m-1){if(s2[i]!=s2[i-1])temp2[i]=temp2[i-1]+1;else temp2[i]=1;}
            fo(i,n)fo(j,m)a[i][j][0]=0,a[i][j][1]=0;
        if(s1[0]!=s2[0]){
            a[0][0][0]=1;a[0][0][1]=1;
        }
        //fo(i,n)cout<<temp1[i];cout<<endl;
        ll ans=0;
        fo(i,n)fo(j,m){
            if(i==0 && j==0);
            else if(i==0){
                if(s1[i]!=s2[j]){a[i][j][0]+=temp2[j];}

                if(s2[j]!=s1[i]){a[i][j][1]+= a[i][j-1][0]+ temp1[i]; }
                if(s2[j]!=s2[j-1])a[i][j][1]+=a[i][j-1][1];
            }
            else if(j==0){
                if(s1[i]!=s2[j]){a[i][j][1]+=temp1[i];}

                if(s1[i]!=s2[j]){a[i][j][0]+= a[i-1][j][1]+ temp2[j]; }
                if(s1[i]!=s1[i-1])a[i][j][0]+=a[i-1][j][0];
            }
            else{
                if(s2[j]!=s1[i]){a[i][j][1]+= a[i][j-1][0]+ temp1[i]; }
                if(s2[j]!=s2[j-1])a[i][j][1]+=a[i][j-1][1];

                if(s1[i]!=s2[j]){a[i][j][0]+= a[i-1][j][1]+ temp2[j]; }
                if(s1[i]!=s1[i-1])a[i][j][0]+=a[i-1][j][0];
            }
            a[i][j][0]%=mod;
            a[i][j][1]%=mod;
            //cout<<i<<" "<<j<<" "<<a[i][j][0]<<" "<<a[i][j][1]<<endl;
            ans+=a[i][j][0]+a[i][j][1];
            ans%=mod;
        }
        cout<<ans;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}