/**
 *    author:  gary
 *    created: 14.05.2022 17:31:38
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
const int MAXN=5e4+10;
int dp[MAXN][1<<10];
int to[1<<10][10];
int n,m;
bool e[10][10];
const int MOD=998244353;
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m; 
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        e[u][v]=e[v][u]=1;
    }
    rep(mask,1<<10){
        rep(j,10){
            int &rest=to[mask][j];
            rep(k,10){
                if(e[j][k]){
                    if(j>k) rest|=1<<k;
                    else rest|=(mask)&(1<<k);
                }
            }
        }
    }
    dp[0][0]=1;
    rb(i,0,n-1){
        rep(mask,1<<10){
            if(dp[i][mask]){
                int val=dp[i][mask];
                rep(j,10) if((mask>>j)&1);
                else{
                    add(dp[i+1][to[mask][j]],val);
                }
            }
        }
    }
    int ans=0;
    rep(mask,1<<10) add(ans,dp[n][mask]);
    cout<<ans<<endl;
    return 0;
}