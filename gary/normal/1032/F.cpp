/**
 *    author:  gary
 *    created: 25.09.2021 14:44:10
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
const int MAXN=3e5+1;
int n;
vector<int> g[MAXN];
int dp[MAXN][2][2];
const int MOD=998244353;
void add(int & A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void dfs(int now,int pre){
    for(auto it:g[now]) if(it!=pre) dfs(it,now);
    int nw[2][2];
    memset(nw,0,sizeof(nw));
    nw[0][0]=1;
    for(auto it:g[now]) if(it!=pre){
        int nwnw[2][2];
        memset(nwnw,0,sizeof(nwnw));
        rep(i,2){
            rep(k,2)
            rep(j,2){
                rep(y,2){
                    if(j==0||y==0)
                    add(nwnw[i][k],1ll*nw[i][k]*dp[it][j][y]%MOD);
                    if(i&&j);
                    else{
                        add(nwnw[i|j][1],1ll*nw[i][k]*dp[it][j][y]%MOD);
                    }
                }
            }
        }
        rep(f,2) rep(g,2) nw[f][g]=nwnw[f][g];
    }
    rep(f,2) rep(g,2) dp[now][f^1][g]=nw[f][g];
}
int main(){
    scanf("%d",&n);
    rb(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
    int answer=0;
    add(answer,dp[1][0][0]);
    add(answer,dp[1][0][1]);
    add(answer,dp[1][1][0]);
    cout<<answer<<endl;
    return 0;
}