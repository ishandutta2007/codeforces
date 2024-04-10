/**
 *    author:  gary
 *    created: 21.01.2022 20:54:29
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e3+1;
const int MOD=1e9+7;
int n;
int a[MAXN],b[MAXN];
int x[MAXN],y[MAXN];
int prefix[2][MAXN][3];
int dp[MAXN][MAXN],sum[MAXN][MAXN],f[MAXN][MAXN];
void work(){
    rb(i,0,n) rb(j,0,n) sum[i][j]=0;
    reverse(a+1,a+1+n);
    reverse(b+1,b+1+n);

    f[0][0]=1;
    rb(i,0,n) sum[i][0]=sum[0][i]=1;
    rb(i,1,n){
        x[i]=x[i-1];
        if(a[i-1]==1) x[i]=i-1;
    }
    rb(i,1,n){
        y[i]=y[i-1];
        if(b[i-1]==1) y[i]=i-1;
    }
    rb(i,1,n){
        rb(j,1,n){
            f[i][j]=(1ll*sum[i-1][j-1]+(x[i]&&y[j]? sum[x[i]-1][y[j]-1]:0)-(y[j]? sum[i-1][y[j]-1]:0)-(x[i]? sum[x[i]-1][j-1]:0)+MOD+MOD)%MOD;
            if(a[i]==0||b[j]==0) f[i][j]=0;
            sum[i][j]=((f[i][j]+sum[i-1][j])%MOD+sum[i][j-1])%MOD+MOD-sum[i-1][j-1];
            sum[i][j]%=MOD;
        }
    }

    rb(i,0,n) rb(j,0,n) sum[i][j]=0;
    reverse(a+1,a+1+n);
    reverse(b+1,b+1+n);
}
void solve(){
    cin>>n;
    rb(i,1,n){
        char c;
        cin>>c;
        a[i]=(c=='?'? 2:(c-'0')^(i&1));
    }
    rb(i,1,n){
        char c;
        cin>>c;
        b[i]=(c=='?'? 2:(c-'0')^(i&1));
    }
    work();
    // rb(i,1,n){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // rb(i,1,n){
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;
    rb(i,0,n) rb(j,0,n) dp[i][j]=sum[i][j]=0;
    dp[0][0]=1;
    rb(i,0,n) sum[i][0]=sum[0][i]=1;
    memset(prefix,0,sizeof(prefix));
    rb(i,1,n){
        rep(j,3) prefix[0][i][j]=prefix[0][i-1][j];
        prefix[0][i][a[i]]++;
        x[i]=x[i-1];
        if(a[i-1]==1) x[i]=i-1;
    }
    rb(i,1,n){
        rep(j,3) prefix[1][i][j]=prefix[1][i-1][j];
        prefix[1][i][b[i]]++;
        y[i]=y[i-1];
        if(b[i-1]==1) y[i]=i-1;
    }
    int answer=0;
    rb(i,1,n){
        rb(j,1,n){
            dp[i][j]=(1ll*sum[i-1][j-1]+(x[i]&&y[j]? sum[x[i]-1][y[j]-1]:0)-(y[j]? sum[i-1][y[j]-1]:0)-(x[i]? sum[x[i]-1][j-1]:0)+MOD+MOD)%MOD;
            if(a[i]==0||b[j]==0) dp[i][j]=0;
            sum[i][j]=((dp[i][j]+sum[i-1][j])%MOD+sum[i][j-1])%MOD+MOD-sum[i-1][j-1];
            sum[i][j]%=MOD;
            // cout<<i<<' '<<j<<" "<<prefix[0][n][2]-prefix[0][i][2]<<" "<<prefix[1][n][2]-prefix[1][j][2]<<endl;
            answer+=1ll*dp[i][j]*f[n-i+1][n-j+1]%MOD*abs(i-j)%MOD;
            answer%=MOD;
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<' '<<f[n-i+1][n-j+1]<<endl;
        }
    }
    cout<<answer<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}