#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 105

using namespace std;
int i,j,m,n,p,k,ans,f[N][N];
struct Node{int x,y;}a[N];
inline bool cmp(Node a,Node b) 
{ 
   return a.x<b.x; 
}
const int inf=(int)1e9;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y);
	a[0].x=-inf;
	sort(a+1,a+n+1,cmp);
	for (i=0;i<=n;++i) for (j=0;j<=n;++j) f[i][j]=-inf;
	f[0][0]=0;
	for (i=1;i<=n;++i)
 {
 	  for (j=0;j<i;++j)
 	  {	  	
 	  	  int last=min(a[i].x,max(a[i-1].x,a[j].x+a[j].y));	  	  
 	  	  if (a[i].x+a[i].y>a[j].x+a[j].y) f[i][i]=max(f[i][i],f[i-1][j]+last-a[i-1].x);
 	  	  else f[i][j]=max(f[i][j],f[i-1][j]+last-a[i-1].x);
 	  }
 	  int id=0;
 	  for (j=i-1;j>=0;--j)
 	  {
 	      for (k=0;k<=j;++k)
 	      {
 	      	  if (j==0&&k==0)
 	      	    j=0;
 	      	   int last=a[k].x+a[k].y;
 	      	   last=min(a[i].x,max(a[j].x,last));
 	      	   int before=max(last,a[i].x-a[i].y);
 	      	   int now=k; if (a[now].x+a[now].y<a[id].x+a[id].y) now=id;
 	      	   f[i][now]=max(f[i][now],f[j][k]+(a[i].x-before)+(last-a[j].x));
 	      }
 	      if (a[id].x+a[id].y<a[j].x+a[j].y) id=j;
 	  }
 }
   for (i=0;i<=n;++i) ans=max(ans,f[n][i]+max(a[n].x,a[i].x+a[i].y)-a[n].x);
   printf("%d\n",ans);
}