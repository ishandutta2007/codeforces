/**
 *    author:  gary
 *    created: 01.10.2021 09:07:37
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
const int MAXN=4e3+1;
LL dp[MAXN][MAXN];
int g[MAXN][2];
int siz[MAXN];
int a[MAXN],n;
int root;
int m;
int solve(int l,int r){
    if(l>r) return 0;
    int mn=l;
    rb(i,l,r) if(a[i]<a[mn]) mn=i;
    g[mn][0]=solve(l,mn-1);
    g[mn][1]=solve(mn+1,r);
    return mn;
}
void dfs(int now){
    if(g[now][0]==0&&g[now][1]==0){
        siz[now]=1;
        dp[now][1]=1ll*(m-1)*a[now];
        dp[now][0]=0;
        return ;
    }
    if(g[now][0]==0){
        dfs(g[now][1]);
        rb(j,0,n) dp[now][j]=dp[g[now][1]][j];
        siz[now]=siz[g[now][1]]+1;
    }
    else
    if(g[now][1]==0){
        dfs(g[now][0]);
        rb(j,0,n) dp[now][j]=dp[g[now][0]][j];
        siz[now]=siz[g[now][0]]+1;
    }
    else{
        dfs(g[now][0]);
        dfs(g[now][1]);
        siz[now]=siz[g[now][0]]+siz[g[now][1]]+1;
        rb(j,0,siz[g[now][0]])
            rb(k,0,siz[g[now][1]]){
                check_max(dp[now][j+k],dp[g[now][0]][j]+dp[g[now][1]][k]-2ll*j*k*a[now]);
            }
    }
    rl(i,siz[now],1){
        check_max(dp[now][i],dp[now][i-1]-2ll*(i-1)*a[now]+1ll*(m-1)*a[now]);
    }
}
int main(){
    cin>>n>>m;
    rb(i,1,n) rb(j,0,n) dp[i][j]=-1e18;
    rb(i,1,n) cin>>a[i];
    root=solve(1,n);
    dfs(root);
    cout<<dp[root][m]<<endl;
    return 0;
}