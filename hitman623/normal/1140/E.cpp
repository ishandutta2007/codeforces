#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        998244353 
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
int dp[200005][2];
int totalWays(int N,int M,int X){
    if (X == 1) dp[0][0] = 1,dp[0][1]=0; 
    else dp[0][1] = 0,dp[0][0]=0;
    if (X == 1){
        dp[1][0] = 0; 
        dp[1][1] = M - 1; 
    } 
    else { 
        dp[1][0] = 1; 
        dp[1][1] = (M - 2); 
    } 
    for (int i=2;i<N;i++){ 
        dp[i][0] = dp[i - 1][1]; 
        dp[i][1] = (dp[i - 1][0] * (M - 1) + dp[i - 1][1] * (M - 2))%hell; 
    } 
    return dp[N - 1][0]; 
} 
int n,k;
int sol(vi v){
    int m=sz(v);
    int cur=0;
    while(cur<m and v[cur]==-1) cur++;
    if(cur==m) return expo(k-1,m-1,hell)*k%hell;
    int ans=expo(k-1,cur,hell);
    if(cur==m) return ans;
    int last=cur;
    cur++;
    while(cur<m){
        if(v[cur]!=-1){
            ans=ans*totalWays(cur-last+1,k,v[cur]==v[last])%hell;
            last=cur;
        }
        cur++;
    }
    cur=cur-last-1;
    if(cur>=0) ans=ans*expo(k-1,cur,hell)%hell;
    return ans;
}
vi v1,v2;
void solve(){
    cin>>n>>k;
    rep(i,1,n+1){
        int x;
        cin>>x;
        if(i%2) v1.pb(x);
        else v2.pb(x);
    }
    cout<<sol(v1)*sol(v2)%hell<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}