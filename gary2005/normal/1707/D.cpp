/**
 *    author:  gary
 *    created: 16.07.2022 22:28:43
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e3+10;
int n,MOD;
int dp[MAXN][MAXN],comb[MAXN][MAXN],ans[MAXN],pre[MAXN][MAXN],suf[MAXN][MAXN],tmp[MAXN][MAXN],tmp2[MAXN][MAXN],f[MAXN];
vector<int> g[MAXN];
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
}
int inv(int A){return quick(A,MOD-2);}
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void dfs(int now,int pp){
    int cnt=0;
    for(auto it:g[now]) if(it!=pp) dfs(it,now);
    rb(i,1,n) tmp[0][i]=1;
    for(auto it:g[now])if(it!=pp){
        ++cnt;
        rb(i,1,n){
            tmp[cnt][i]=1ll*tmp[cnt-1][i]*pre[it][i]%MOD;
        }
    }
    rb(i,1,n) tmp2[cnt+1][i]=1;
    reverse(ALL(g[now]));
    int x=cnt;
    for(auto it:g[now]) if(it!=pp){
        rb(i,1,n){
            tmp2[x][i]=1ll*tmp2[x+1][i]*pre[it][i]%MOD;
        }
        --x;
    }
    reverse(ALL(g[now]));
    rb(i,1,n)
        dp[now][i]=tmp[cnt][i];
    x=0;
    for(auto it:g[now]) if(it!=pp){
        ++x;
        int sum=0;
        rb(i,1,n){
            add(sum,1ll*tmp[x-1][i]*tmp2[x+1][i]%MOD);
            add(dp[now][i+1],1ll*sum*dp[it][i+1]%MOD);
        }
    }
    pre[now][0]=0;
    rb(i,1,n) pre[now][i]=pre[now][i-1],add(pre[now][i],dp[now][i]);
    suf[now][n+1]=0;
    rl(i,n,1) suf[now][i]=suf[now][i+1],add(suf[now][i],dp[now][i]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>MOD;
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rb(i,0,n) comb[i][0]=1;
    rb(i,1,n) rb(j,1,n) comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
    dfs(1,0);
    rb(i,1,n-1){
        f[i]=1;
        for(auto it:g[1]) f[i]=1ll*f[i]*pre[it][i]%MOD;
    }
    // cout<<dp[3][1]<<endl;
    rb(i,1,n-1){
        ans[i]=f[i];
        rb(j,1,i-1){
            add(ans[i],MOD-(1ll*ans[j]*comb[i][j]%MOD));
        }
        cout<<ans[i]<<" ";
    }
    return 0;
}