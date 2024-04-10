#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int n,t,a[100005][2];
long long dp[100005][2];
vector<int> vec[100005];
void dfs(int x,int fa)
{
    dp[x][0]=dp[x][1]=0;
    for(int i=0;i<vec[x].size();i++)
    {
        int y=vec[x][i];
        if(y==fa) continue;
        dfs(y,x);
        dp[x][0]+=max(dp[y][0]+abs(a[x][0]-a[y][0]),dp[y][1]+abs(a[x][0]-a[y][1]));
        dp[x][1]+=max(dp[y][0]+abs(a[x][1]-a[y][0]),dp[y][1]+abs(a[x][1]-a[y][1]));
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i][0],&a[i][1]);
            vec[i].clear();
        }
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        dfs(1,0);
        printf("%lld\n",max(dp[1][0],dp[1][1]));
    }
}