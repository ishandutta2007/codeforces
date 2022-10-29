#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int i,j,m,n,p,k,x,y,Q[3005],vis[3005];
int dis[3005][3005],s1,t1,s2,t2,l1,l2,ans;
vector<int>v[3005];
void bfs(int x)
{
      int i,j;
      Q[Q[0]=1]=x;
      memset(vis,0,sizeof(vis));
      vis[x]=1;
      int l;
      for (l=1;l<=Q[0];++l)
      {
           p=Q[l];
           for (i=0;i<v[p].size();++i)
           {
                k=v[p][i];
                if (!vis[k])
                {
                  vis[k]=1;
                  dis[x][k]=dis[x][p]+1;
                  Q[++Q[0]]=k;
                }
           }
      }
}
int main()
{
     scanf("%d%d",&n,&m);
     for (i=1;i<=m;++i)
     {
         scanf("%d%d",&x,&y);
         v[x].push_back(y);
         v[y].push_back(x);
     }
     for (i=1;i<=n;++i) bfs(i);
     scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
     if (dis[s1][t1]>l1||dis[s2][t2]>l2) printf("-1\n");
     else 
     {
           ans=dis[s1][t1]+dis[s2][t2];
           for (i=1;i<=n;++i)
             for (j=1;j<=n;++j)
                if (dis[s1][i]+dis[i][j]+dis[j][t1]<=l1)
                  if (dis[s2][i]+dis[i][j]+dis[j][t2]<=l2)
                     ans=min(ans,dis[s1][i]+dis[i][j]+dis[j][t1]+dis[s2][i]+dis[j][t2]);
           swap(s2,t2);
           for (i=1;i<=n;++i)
             for (j=1;j<=n;++j)
                if (dis[s1][i]+dis[i][j]+dis[j][t1]<=l1)
                  if (dis[s2][i]+dis[i][j]+dis[j][t2]<=l2)
                     ans=min(ans,dis[s1][i]+dis[i][j]+dis[j][t1]+dis[s2][i]+dis[j][t2]);
           printf("%d\n",m-ans);
     }
}