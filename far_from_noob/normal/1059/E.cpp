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
ll a[100005];
ll p[100005][20];
ll presum[100005][20];
vll v[100005];
ll cnt[100005],val[100005];
ll b[100005];
ll po[20];

void dfs(ll node, ll root){
    fo1(i,19){
        if(p[node][i-1]==-1)break;
        p[node][i] = p[p[node][i-1]][i-1];
    }
    presum[node][0]=a[node];
    fo1(i,19){
        if(p[node][i]!=-1)presum[node][i]= presum[node][i-1] + presum[p[node][i-1] ][i-1];
    }
    ll cld =-1; ll la =0;
    b[node]=0;
    fo(i, v[node].size()){
        if(v[node][i]== root)continue;
        dfs(v[node][i] ,node);
        ll curr= m - val[v[node][i]];
        b[node] += b[v[node][i]];
        ll last=0;
        ll cnode= node;
        while(cnode!=0){
            fo(j,20){
                if(p[cnode][j]==-1){curr-=presum[cnode][j-1]; last+=po[j-1]; cnode= p[cnode][j-1]; break;}
                if(presum[cnode][j] >curr ){
                    if(j==0){cnode=0; break;}
                    else{
                        curr-=presum[cnode][j-1]; last+=po[j-1]; cnode= p[cnode][j-1];
                        break;
                    }
                }
            }
        }
        //cout<<v[node][i]<< " "<< last<<endl;
        last = min(last, k-cnt[v[node][i]]);
        if(last>la){cld= v[node][i]; la =last;}


    }
    if(cld ==-1){cnt[node]=1; val[node]=a[node]; b[node]++;}
    else{
        cnt[node] = 1+ cnt[cld];
        val[node]= a[node]+val[cld];
    }

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
        cin>>n>>k>>m;
        fo1(i,n){cin>>a[i]; if(a[i]>m){cout<<-1<<endl; return 0;}}
        fo(i,n+1)fo(j,20)p[i][j]=-1;

        p[1][0]=0;
        a[0]=0;

        fo1(i,n-1){
            cin>>p[i+1][0];
            v[i+1].pb(p[i+1][0]);
            v[p[i+1][0]].pb(i+1);
        }
        fo(i,20)po[i]=(ll)pow(2,i);
        dfs(1,1);

        //fo1(i,3)cout<<cnt[i]<<" "<<val[i]<<endl;
        //cout<<presum[2][0]<<presum[2][1]<<endl;
        cout<<b[1]<<endl;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}