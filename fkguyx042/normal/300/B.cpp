#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,x,A,B,C,tot,k;
int vis[101],a[101][101],Que[101],Q[4][101];
int bfs(int x,int c)
{  Que[1]=x; int l=1,r=1; int i;
vis[x]=1; 
for (;l<=r;l++)
{ int p=Que[l];
   if (c) printf("%d ",p);
  for (i=1;i<=n;i++)
   if (!vis[i]&&a[p][i])
   {  Que[++r]=i;
     vis[i]=1;
}
}
return r;
}
int main()
{ scanf("%d%d",&n,&m);
   for (i=1;i<=m;i++)
   { scanf("%d%d",&x,&k);
     a[x][k]=a[k][x]=1; }
  for (i=1;i<=n;i++)
  if (!vis[i])
  { vis[i]=1;
    tot++;
    x=bfs(i,0);
    if (x>3){ printf("-1\n"); return 0;}
    else Q[x][++Q[x][0]]=i;
}
if (Q[1][0]>=Q[2][0]&&(Q[1][0]-Q[2][0])%3==0)  {
memset(vis,0,sizeof(vis));
 for (i=1;i<=Q[3][0];i++)
  {  bfs(Q[3][i],1);
    printf("\n"); }
 for (i=1;i<=Q[2][0];i++)
 {  bfs(Q[1][i],1); bfs(Q[2][i],1); printf("\n"); }
 for (i=Q[2][0]+1;i<=Q[1][0];)
 {  for (j=0;++j<=3;)
      bfs(Q[1][i++],1);
}
}else { printf("-1\n"); return 0;}
}