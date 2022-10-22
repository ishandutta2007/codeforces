#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> Edge[200005];

pair<int,int> dp[200005][2]; // pair<cnt,sum>
bool cmp(pair<int,int> &p1,pair<int,int> &p2)
{
    if(p1.first != p2.first) return p1.first > p2.first;
    else return p1.second < p2.second;
}
void Add(pair<int,int> &p1,pair<int,int> &p2)
{
    p1.first+=p2.first;
    p1.second+=p2.second;
}

void dfs(int x,int fa)
{
    dp[x][0]=make_pair(0,1);
    dp[x][1]=make_pair(1,Edge[x].size());
    for(auto &p : Edge[x])
    {
        if(p == fa) continue;
        dfs(p,x);
        Add(dp[x][1],dp[p][0]);
        if(cmp(dp[p][0],dp[p][1])) Add(dp[x][0],dp[p][0]);
        else Add(dp[x][0],dp[p][1]);
    }
}

bool Ans[200005];
void GetAns(int x,int fa,int col)
{
    Ans[x]=col;
    for(auto &p : Edge[x])
    {
        if(p == fa) continue;
        if(col==1) GetAns(p,x,0);
        else if(cmp(dp[p][0],dp[p][1])) GetAns(p,x,0);
        else GetAns(p,x,1);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }
    if(n==2)
    {
        printf("2 2\n1 1\n");
        return 0;
    }
    dfs(1,0);
    if(cmp(dp[1][0],dp[1][1]))
    {
        printf("%d %d\n",dp[1][0].first,dp[1][0].second);
        GetAns(1,0,0);
    }
    else
    {
        printf("%d %d\n",dp[1][1].first,dp[1][1].second);
        GetAns(1,0,1);
    }
    for(int i=1;i<=n;i++) printf("%d ",Ans[i] ? Edge[i].size() : 1);
    printf("\n");
}