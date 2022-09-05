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
#define MN 100010
#define MM 511
int n,m,k,c[MM],col[MN],tk[MN],d[MM][MM];
vector<int>con[MN];
set<int>s[511];
void dfs(int x,int color)
{
    if(tk[x])return;
    tk[x]=color;s[col[x]].insert(color);
    for(int i=0;i<con[x].size();i++)dfs(con[x][i],color);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            d[i][j]=1<<28;
        }
        d[i][i]=0;
    }
    int tmp=1;
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        c[i]=x;
        while(x--)col[tmp]=i,tmp++;
    }
//  cout<<"d[][]:"<<endl;
//  for(int i=1;i<=k;i++){for(int j=1;j<=k;j++)cout<<d[i][j]<<" ";cout<<endl;}
    for(int i=1;i<=m;i++)
    {
        int a,b,cost;
        scanf("%d%d%d",&a,&b,&cost);
        if(cost==0)con[a].push_back(b),con[b].push_back(a);
        d[col[a]][col[b]]=d[col[b]][col[a]]=min(d[col[a]][col[b]],cost);
    }
    int id=0;
    for(int i=1;i<=n;i++)if(!tk[i]){id++;dfs(i,id);}
    bool ok=1;
    for(int i=1;i<=k;i++)if(s[i].size()>1){ok=0;puts("No");return 0;}
    puts("Yes");
//  for(int i=1;i<=k;i++){for(int j=1;j<=k;j++)cout<<d[i][j]<<" ";cout<<endl;}
    for(int l=1;l<=k;l++)
    {
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=k;j++)
            {
                d[i][j]=d[j][i]=min(d[i][l]+d[l][j],d[i][j]);
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            printf("%d ",d[i][j]==(1<<28)?-1:d[i][j]);
        }
        puts("");
    }
//  system("pause");
    return 0;
}