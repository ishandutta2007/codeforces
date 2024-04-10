#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
vector<int> v[1000005];
vector<int> d[2000005];
int in[1000005];
int t=0;
int dp[1000005];
int dp2[1000005];
int has[1000005];
int k;
int dfs(int x,int sum){
    int Min=1e9;
    in[x]=++t;
    if(v[x].empty()){
        d[sum].pb(t);
        return sum;
    }
    int Max=0;
    dp[x]=0;
    dp2[x]=0;
    for(auto it:v[x]){
        Min=min(Min,dfs(it,sum+1));
        dp2[x]+=dp2[it];
        Max=max(Max,dp[it]-dp2[it]);
    }
    dp2[x]+=d[sum+k].end()-lower_bound(d[sum+k].begin(),d[sum+k].end(),in[x]);
    dp[x]+=Max;
    dp[x]+=dp2[x];
    //printf("%d %d %d\n",x,dp[x],dp2[x]);
    if(Min>sum+k-1)
    dp2[x]=0;
    return Min;
    //printf("%d %d %d %d %d\n",Max,x,dp[x],t,in[x]);
}
int main(){
    int n;
    scanf("%d %d",&n,&k);
    for(int i=2;i<=n;i++){
        int p;
        scanf("%d",&p);
        v[p].pb(i);
    }
    dfs(1,0);
    int ans=dp[1];
    for(int i=0;i<k;i++){
        ans+=d[i].size();
    }
    printf("%d\n",ans);
}