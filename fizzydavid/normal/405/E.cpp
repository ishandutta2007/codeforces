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
int n,m;
bool vis[100100];
vector<pair<int,int> >con[100100];
int dfs(int x)
{
    queue<int>q,up;
    for(int i=0;i<con[x].size();i++){if(!vis[con[x][i].second])q.push(con[x][i].first);vis[con[x][i].second]=1;}
    while(!q.empty())
    {
        int u=q.front();q.pop();
        int v1=dfs(u);
        if(v1==0)up.push(u);
        else printf("%d %d %d\n",x,u,v1);
    }
    while(up.size()>1)
    {
        int v1=up.front();
        up.pop();
        int v2=up.front();
        up.pop();
        printf("%d %d %d\n",v1,x,v2);
    }
    if(up.size()!=0){int u=up.front();up.pop();return u;}
    else return 0;
}
int main()
{
    scanf("%d %d",&n,&m);
    if(m&1)
    {
        cout<<"No solution";
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            con[x].push_back(make_pair(y,i));
            con[y].push_back(make_pair(x,i));
        }
        dfs(1);
    }
    return 0;
}