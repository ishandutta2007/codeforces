#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;
const int q=1000000007;
int n,f[100010],x[100010],y[100010],t[200010],p;
struct point
{
	int x,y,p;
}w[100010];
inline bool cmp(point a,point b)
{
	return a.x<b.x;
}
inline bool cmp2(point a,point b)
{
	return a.y<b.y;
}
inline int fa(int i)
{
	return f[i]==i?i:f[i]=fa(f[i]);
}
inline void unit(int i,int j)
{
	i=fa(i);
	j=fa(j);
	if(i==j)
	  y[i]++;
	else
	  {
	   f[j]=i;
	   x[i]+=x[j];
	   y[i]+=y[j]+1;
	  }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d%d",&w[i].x,&w[i].y);
	   w[i].p=i;
	   f[i]=i;
	   x[i]=1;
	  }
	sort(w+1,w+n+1,cmp);
	for(i=2;i<=n;i++)
	  if(w[i].x==w[i-1].x)
	    unit(w[i].p,w[i-1].p);
	sort(w+1,w+n+1,cmp2);
	for(i=2;i<=n;i++)
	  if(w[i].y==w[i-1].y)
	    unit(w[i].p,w[i-1].p);
	t[0]=1;
	for(i=1;i<=2*n;i++)
	  t[i]=t[i-1]*2%q;
	p=1;
	for(i=1;i<=n;i++)
	  if(fa(i)==i)
	    if(y[i]==x[i]-1)
	      p=(L)p*(t[x[i]+1]-1)%q;
	    else
	      p=(L)p*t[x[i]*2-y[i]]%q;
	printf("%d\n",p);
	return 0;
}