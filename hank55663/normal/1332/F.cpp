#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL dp[300005][4];
int mod=998244353;
vector<int> v[300005];
void dfs(int x,int f){
    dp[x][0]=1;
    dp[x][1]=1;
    dp[x][3]=1;
    if(v[x].size()==1&&x!=1){
        dp[x][0]=1;
        dp[x][1]=1;
        dp[x][3]=1;
        return ;
    }
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            dp[x][0]=dp[x][0]*(dp[it][0]+dp[it][1]+dp[it][2]+dp[it][3])%mod;
            dp[x][1]=dp[x][1]*(dp[it][0]+dp[it][1]+dp[it][2]+dp[it][3])%mod;
            dp[x][2]=(dp[x][3]*dp[it][1]%mod+dp[x][2]*(dp[it][0]+dp[it][1]+dp[it][2])%mod)%mod;
            dp[x][3]=dp[x][3]*(dp[it][0]+dp[it][2])%mod;
        }
    }
    dp[x][3]+=dp[x][2];
 //   printf("%d %d %d %d\n",dp[x][0],dp[x][1],dp[x][2],dp[x][3]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    printf("%lld\n",(dp[1][0]+dp[1][2]-1+mod)%mod);
}