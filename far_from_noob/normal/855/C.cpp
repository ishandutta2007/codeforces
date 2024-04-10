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
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}

vector<ll>v[100005];
ll dp[100005][11][3];
void fun(ll node, ll root ){
    fo(i,11)fo(j,3)dp[node][i][j]=0;
    dp[node][0][0]=k-1;
    dp[node][0][2]=m-k;
    dp[node][1][1]=1;
    fo(i,v[node].size()){
        if(v[node][i]==root)continue;
        fun(v[node][i], node);
        ll dpnode[11][3];
        fo(l,11)fo(j,3)dpnode[l][j]=dp[node][l][j];
        ll leaf=v[node][i];
        for(int j=10;j>=0;j--){
            dp[node][j][1]=0;
            for(int l=j-1;l>=0;l--){
                dp[node][j][1]+=(dpnode[l+1][1] * dp[leaf][j-1-l][0])%mod;
                dp[node][j][1]%=mod;
            }
            dp[node][j][0]=0;
            for(int l=j;l>=0;l--){
                dp[node][j][0]+=(dpnode[l][0] * ((dp[leaf][j-l][0] + dp[leaf][j-l][1] + dp[leaf][j-l][2])%mod))%mod;
                dp[node][j][0]%=mod;
            }
            dp[node][j][2]=0;
            for(int l=j;l>=0;l--){
                dp[node][j][2]+=(dpnode[l][2] * ((dp[leaf][j-l][0]+ dp[leaf][j-l][2])%mod))%mod;
                dp[node][j][2]%=mod;
            }

        }
    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m;
        fo(i,n-1){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        ll x;
        cin>>k>>x;
        fun(1,1);
        ll ans=0;
        fo(i,x+1)fo(j,3)ans+=dp[1][i][j],ans%=mod;
        cout<<ans;
        
    }

    return 0;
}