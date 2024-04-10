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
ll ans[100][100][101][2];
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
        cin>>n;string s;
        cin>>s;
        ll a[n+1];
        fo1(i,n)cin>>a[i];
        for(int i=2;i<=n;i++){
            ll val=a[i];
            for(int j=1;j<i;j++){
                val=max(val,a[j]+a[i-j]);
            }
            a[i]=val;
            //cout<<a[i]<<" " ;
        }
        fo(i,100)fo(j,100)fo(l,101)fo(k,2)ans[i][j][l][k]=-1;
        for(int d = 0;d<n;d++){
            for(int i=0;i<n-d;i++){
                if(d==0){
                    ans[i][i+d][0][0]=a[1];
                    ans[i][i+d][0][1]=a[1];
                    if(s[i]=='0')ans[i][i+d][1][0]=0;
                    if(s[i]=='1')ans[i][i+d][1][1]=0;
                    continue;
                }
                for(int l =0;l<=d+1;l++){
                    if(l!=0){
                        ll val1=-1,val0=-1;

                        for(int x= i; x< i+d;x++){
                            if(ans[i][x][1][0]!=-1 && ans[x+1][i+d][l-1][0]!=-1){
                                val0=max(val0,ans[i][x][1][0] + ans[x+1][i+d][l-1][0]  );
                            }
                            if(ans[i][x][l-1][0]!=-1 && ans[x+1][i+d][1][0]!=-1){
                                val0=max(val0,ans[i][x][l-1][0] + ans[x+1][i+d][1][0]  );
                            }

                            if(ans[i][x][l-1][1]!=-1 && ans[x+1][i+d][1][1]!=-1){
                                val1=max(val1,ans[i][x][l-1][1] + ans[x+1][i+d][1][1]  );
                            }
                            if(ans[i][x][1][1]!=-1 && ans[x+1][i+d][l-1][1]!=-1){
                                val1=max(val1,ans[i][x][1][1] + ans[x+1][i+d][l-1][1]  );
                            }

                        }

                        ans[i][i+d][l][0]=val0;
                        ans[i][i+d][l][1]=val1;

                    }
                    else{
                        ll val=-1;
                        for(int x= i; x< i+d;x++){
                            val=max(val,ans[i][x][0][0] + ans[x+1][i+d][0][0]  );
                        }
                        ll c = s[i]-'0';
                        if(s[i]==s[i+d]){
                            if(d==1)val =max(val , a[2]);
                            else{
                                //cout<<c<<
                                for(int x=0;x<100;x++){
                                    if(ans[i+1][i+d-1][x][c]!=-1){
                                        val = max(val , ans[i+1][i+d-1][x][c] + a[x+2]);
                                    }
                                }
                            }
                        }

                        ans[i][i+d][0][0]=val; ans[i][i+d][0][1]=val;
                    }

                }
            }
        }
        cout<<ans[0][n-1][0][0]<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}