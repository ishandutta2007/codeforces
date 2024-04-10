/**
 *    author:  gary
 *    created: 06.05.2022 23:35:26
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
const int MAXN=1e3+10;
const int MOD=1e9+7;
const int B=60;
int dp[2][MAXN][2*MAXN][2];
bool zx[B],rx[B];
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int Solve(int n,LL r,LL z){
    memset(dp,0,sizeof(dp));
    rep(i,B){
        zx[i]=(z>>i)&1;
        rx[i]=(r>>i)&1;
    }
    dp[B&1][n+1][0][0]=1;
    rl(i,B-1,0){
        memset(dp[i&1],0,sizeof(dp[i&1]));
        rb(j,0,2*n){
            add(dp[i&1][1][min(2*n,(j<<1)+rx[i])][zx[i]],dp[(i+1)&1][n+1][j][0]);
        }
        rb(j,1,n){
            rb(k,0,2*n) 
                rep(f,2) 
                    if(dp[i&1][j][k][f]){
                        if(k)
                        add(dp[i&1][j+1][k-1][f^1],dp[i&1][j][k][f]);
                        add(dp[i&1][j+1][k][f],dp[i&1][j][k][f]);
                    }
        }
    }
    int ans=0;
    rb(i,0,2*n) add(ans,dp[0][n+1][i][0]);
    return ans;
}
int n;
LL l,r,z;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cerr<<sizeof(dp)/1024/1024<<endl;
    cin>>n>>l>>r>>z;
    cout<<(Solve(n,r,z)-Solve(n,l-1,z)+MOD)%MOD<<endl;
    return 0;
}