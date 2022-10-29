#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define fi first
#define se second
using namespace std;
vector<pair<int,int> >v[2005];
long long F[2005][2005][2][2],size[2005][2005],sum[2005][2005];
int i,j,m,n,p,k,Q[200005],s[2],vis[2005],cost[2005];
int x,y,w,Max[2],V[2005][2005][2][2];
long long dis[2][2005],b[2005];
long long Size(int x,int y,int z,int f){return size[z][f]-size[x][y];}
long long Sum( int x,int y,int z,int f){return sum[z][f]-sum[x][y]; }
long long dfs(int x,int y,int f,int Now)
{
       if (x>Max[0]||y>Max[1]) return 0;
       if (V[x][y][f][Now]) return F[x][y][f][Now];
       V[x][y][f][Now]=1;
       long long &z=F[x][y][f][Now];
       if (f) z=dfs(x,y+1,f,Now||Size(x,y+1,x,y))+Sum(x,y+1,x,y);
       else z=dfs(x+1,y,f,Now||Size(x+1,y,x,y))+Sum(x+1,y,x,y);
       if (Now) z=max(z,-dfs(x,y,f^1,0));
       return z;
}
void spfa(int x)
{
     Q[Q[0]=1]=s[x];
     dis[x][Q[1]]=0;
     int l,i;
     for (l=1;l<=Q[0];++l)
     {
          int p=Q[l];
          for (i=0;i<v[p].size();++i)
          {
                int k=v[p][i].fi,cp=v[p][i].se;
                if (dis[x][k]>dis[x][p]+cp)
                {
                   dis[x][k]=dis[x][p]+cp;
                   if (!vis[k]) vis[k]=1,Q[++Q[0]]=k;
                }
          }
          vis[p]=0;
     }
     for  (i=1;i<=n;++i) b[i]=dis[x][i];
     sort(b+1,b+n+1);
     b[0]=unique(b+1,b+n+1)-(b+1);
     for (i=1;i<=n;i++)
      dis[x][i]=lower_bound(b+1,b+b[0]+1,dis[x][i])-b;
     Max[x]=b[0];
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s[0],&s[1]);
    for (i=1;i<=n;++i) scanf("%d",&cost[i]);
    for (i=1;i<=m;++i)
    { 
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
    }
    memset(dis,60,sizeof(dis));
    spfa(0);
    spfa(1);
    for (i=1;i<=n;++i) size[dis[0][i]][dis[1][i]]++,
    sum[dis[0][i]][dis[1][i]]+=cost[i];
    for (i=Max[0];i;--i)
     for (j=Max[1];j;--j)
       size[i][j]+=size[i][j+1]+size[i+1][j]-size[i+1][j+1],
       sum[i][j]+=sum[i][j+1]+sum[i+1][j]-sum[i+1][j+1];
    long long ans=dfs(1,1,0,0);
    if (ans==0) printf("Flowers\n");
    else if (ans>0) printf("Break a heart\n");
    else printf("Cry\n");
}