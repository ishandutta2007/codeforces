/**
 *    author:  gary
 *    created: 17.05.2022 18:34:41
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
const int MOD=1e9+7;
int n,m;
char c[3003][3003];
int dp[3003][3003];
int solve(mp A,mp B){
    memset(dp,0,sizeof(dp));
    dp[A.first][A.second]=1;
    rb(i,1,n) rb(j,1,m){
        if(c[i][j]=='#') dp[i][j]=0;
        (dp[i+1][j]+=dp[i][j])%=MOD;
        (dp[i][j+1]+=dp[i][j])%=MOD;
    }
    return dp[B.first][B.second];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rb(i,1,n) rb(j,1,m) cin>>c[i][j];
    cout<<(1ll*solve(II(1,2),II(n-1,m))*solve(II(2,1),II(n,m-1))%MOD-1ll*solve(II(2,1),II(n-1,m))*solve(II(1,2),II(n,m-1))%MOD+MOD)%MOD<<endl;
    return 0;
}