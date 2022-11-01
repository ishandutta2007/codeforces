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
ll maxi[100005][30];
ll mini[100005][30];
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
        cin>>n>>q;

        ll a[n+1],b[n+1];
        fo1(i,n)cin>>a[i];

        fo1(i,n)cin>>b[i];

        ll p1[n+1],p2[n+1],c[n+1],p3[n+1];
        p1[0]=0;p2[0]=0;c[0]=0,p3[0]=0;
        fo1(i,n){
            p1[i]= p1[i-1]+a[i];
            p2[i]=p2[i]+b[i];
            c[i]=b[i]-a[i];
            p3[i]=p3[i-1]+c[i];
        }

        fo1(i,n)maxi[i][0]= max(0,c[i]);
        fo1(i,n)mini[i][0]=min(0,c[i]);

        ll l = log2(n);
        //cout<<l<<endl;
        ll po[20];
        fo(i,20)po[i]=(ll)pow(2,i);

        fo1(j,l){
            fo1(i,n){
                if(i+ po[j]-1>n){maxi[i][j]=-1; mini[i][j]=-1;continue;}

                maxi[i][j] = max(maxi[i][j-1 ] , p3[i+po[j-1]-1] - p3[i-1] + maxi[i+po[j-1]][j-1]);
                mini[i][j]= min(mini[i][j-1 ] , p3[i+po[j-1]-1] - p3[i-1] + mini[i+po[j-1]][j-1]);

            }
        }
        //cout<<maxi[6][1];

        fo(j,q){
            ll s , r;

            cin>>s>>r;
            ll s1=s;
            ll d= r-s+1;
            ll mymax=0,mymin=0;
            ll temp=0;
            for(int i=l;i>=0;i--){
                if(po[i]<=d){
                    mymax= max(mymax , temp + maxi[s][i]);
                    mymin = min(mymin , temp + mini[s][i]);
                    temp+= p3[s + po[i]-1] -p3[s-1];
                    s+=po[i];
                    d-=po[i];
                }
                //cout<<s<<endl;


                if(s>r)break;
            }
            //cout<<mymax 
            if(mymin <0 || p3[r]-p3[s1-1]!=0)cout<<-1<<endl;
            else cout<<mymax<<endl;

        }





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}