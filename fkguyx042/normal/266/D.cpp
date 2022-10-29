#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 205
using namespace std;
struct Node{
	 int x,y,w;
}Q[N],B[N*N];
int i,j,m,n,p,k,a[N][N],x,y,w,ans;
inline bool cmp(Node a,Node b)
{
	 if (a.x!=b.x) return a.x<b.x;
	 return a.y<b.y;
}
void work(int x)
{
	 int i,j;
	 for (i=1;i<=n;++i) Q[i]=(Node){a[i][B[x].x],a[i][B[x].y],0};
	 sort(Q+1,Q+n+1,cmp);
	 j=n;
	 ans=min(ans,Q[j].x*2);
	 for (i=n-1;i>=1;--i)
	   if (Q[i].x<Q[j].x&&Q[i].y>Q[j].y)
	     ans=min(ans,Q[i].x+Q[j].y+B[x].w),j=i;
	 ans=min(ans,Q[j].y*2);
}
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=1;i<=n;++i) 
	   for (j=1;j<=n;++j) if (i==j) a[i][j]=0; else a[i][j]=1e9+7;
	 for (i=1;i<=m;++i)
	 {
	 	 scanf("%d%d%d",&x,&y,&w);
	 	 a[x][y]=a[y][x]=w;
	 	 B[i]=(Node){x,y,w};
	 }
	 for (k=1;k<=n;++k)
	   for (i=1;i<=n;++i)
	     for (j=1;j<=n;++j) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	 ans=(int)2e9+7;
	 for (i=1;i<=m;++i) work(i);
	 printf("%.10lf\n",ans/2.);
}