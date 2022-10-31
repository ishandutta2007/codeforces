#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> G[50000];
vector<int>g[50000];
int dp[50000][501];
int n,k;
void dfs(int a,int b){
    for(int i=0;i<G[a].size();i++){
        if(b!=G[a][i]){
            g[a].push_back(G[a][i]);
            dfs(G[a][i],a);
        }
    }
}
long long ret=0;
void solve(int a){
    for(int i=0;i<g[a].size();i++)solve(g[a][i]);
    for(int i=0;i<g[a].size();i++){
        for(int j=0;j<k;j++){
            dp[a][j+1]+=dp[g[a][i]][j];
        }
    }
    dp[a][0]=1;
    for(int i=1;i+i<=k;i++){
        long long S=0;
        long long T=0;
        long long now=0;
        for(int j=0;j<g[a].size();j++){
            S+=dp[g[a][j]][i-1];
            T+=dp[g[a][j]][k-i-1];
            now+=(long long)dp[g[a][j]][i-1]*dp[g[a][j]][k-i-1];
        }
    //  printf("%lld ",S*T-now);
        ret+=(S*T-now)/((i+i==k)?2:1);
    }
    ret+=dp[a][k];
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    n=a;
    k=b;
    for(int i=0;i<a-1;i++){
        int c,d;
        scanf("%d%d",&c,&d);
        G[c-1].push_back(d-1);
        G[d-1].push_back(c-1);
    }
    dfs(0,-1);
    solve(0);
    printf("%I64d\n",ret);
}