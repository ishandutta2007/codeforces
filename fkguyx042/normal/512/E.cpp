#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{int x,y;}An[100001];
int tot,i,j,m,n,p,k,f[1001][1001],vis[1001],Qus[1001],x,y,dis[1001];
Node T[1001];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n-3;i++) {
  	scanf("%d%d",&x,&y);
  	if (x>y) swap(x,y);
  	f[x][y]=1;
   }
  	for (i=2;i<=n;i++)
  	  for (j=n;j;j--) if (f[i][j])An[++tot].x=i,An[tot].y=j;
  	for (i=1;i<=n-3;i++)
 {  scanf("%d%d",&T[i].x,&T[i].y);
    if (T[i].x>T[i].y) swap(T[i].x,T[i].y);
    dis[i]=(T[i].x==1)?0:(T[i].y-T[i].x-1);
 }
   for (;;)
{  int Dis=n,id=-1;
   for (i=1;i<=n-3;i++) if (!vis[i]&&dis[i]<Dis) Dis=dis[i],id=i;
   if (id==-1) break;
   vis[id]=1;
   if (dis[id])
   {    for (i=T[id].x+1;i<T[id].y;i++) if (!Qus[i]) break;
        An[++tot].x=1,An[tot].y=i; Qus[i]=1;
        for (j=1;j<=n-3;j++) if (T[j].x<i&&T[j].y>i) dis[j]--;
   }
}
printf("%d\n",tot);
for (i=1;i<=tot;i++) printf("%d %d\n",An[i].x,An[i].y);
}