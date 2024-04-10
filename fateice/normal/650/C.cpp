#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,a[1000010],x[1000010],y[1000010],f[1000010],p[1000010];
struct orz
{
	int a,x,y,p;
}t[1000010];
inline bool cmp(orz a,orz b)
{
	return a.a<b.a;
}
inline int fa(int i)
{
	return i==f[i]?i:(f[i]=fa(f[i]));
}
inline void connect(int i,int j)
{
	i=fa(i);
	j=fa(j);
	f[i]=j;
}
int main()
{
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    {
	     scanf("%d",&t[(i-1)*m+j].a);
	     t[(i-1)*m+j].x=i;
	     t[(i-1)*m+j].y=j;
	     t[(i-1)*m+j].p=(i-1)*m+j;
		}
	sort(t+1,t+n*m+1,cmp);
	for(i=1;i<=n+m;i++)
	  f[i]=i;
	for(i=1;i<=n*m;i=j)
	  {
	   for(j=i+1;j<=n*m && t[j].a==t[i].a;j++);
	   for(k=i;k<j;k++)
	     connect(t[k].x,t[k].y+n);
	   for(k=i;k<j;k++)
	     {
		  l=fa(t[k].x);
	      p[l]=max(p[l],max(x[t[k].x],y[t[k].y]));
		 }
	   for(k=i;k<j;k++)
	     {
		  a[t[k].p]=p[f[t[k].x]]+1;
		  x[t[k].x]=a[t[k].p];
		  y[t[k].y]=a[t[k].p];
		 }
	   for(k=i;k<j;k++)
	     {
		  f[t[k].x]=t[k].x;
		  p[t[k].x]=0;
		  f[t[k].y+n]=t[k].y+n;
		  p[t[k].y+n]=0;
		 }
	  }
	for(i=1;i<=n;i++)
	  {
	   for(j=1;j<=m;j++)
	     printf("%d ",a[(i-1)*m+j]);
	   printf("\n");
	  }
	return 0;
}