#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
int n,res[111111];
bool init[111111],goal[111111],vis[111111];
vector<int>con[111111];
int dfs(int x,bool ec,bool oc,bool lv)
{
    vis[x]=1;
    if(init[x]^goal[x])
    {
        if(lv&1&&!oc)res[x]=1,oc^=1;else if(lv!=1&&!ec)res[x]=1,ec^=1;
    }
    else
    {
        if(lv&1&&oc)res[x]=1,oc^=1;else if(lv!=1&&ec)res[x]=1,ec^=1;
    }
    for(int i=0;i<con[x].size();i++)
    {
        if(!vis[con[x][i]])dfs(con[x][i],ec,oc,lv^1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        con[x].push_back(y);con[y].push_back(x);
    }
    for(int i=1;i<=n;i++)scanf("%d",&init[i]);
    for(int i=1;i<=n;i++)scanf("%d",&goal[i]);
    dfs(1,0,0,1);
    int cnt=0;
    for(int i=1;i<=n;i++)if(res[i]&1)cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++)if(res[i]&1)printf("%d\n",i);
//  system("pause");
    return 0;
}