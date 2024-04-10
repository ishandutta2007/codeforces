#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;
int n,m,x[300010],f[300010],a[300010],p;
L w;
inline void up()
{
	int i=p;
	while(i>1 && x[f[i]]>x[f[i>>1]])
	  {
	   swap(f[i],f[i>>1]);
	   i>>=1;
	  }
}
inline void down()
{
	int i=1,j;
	while((i<<1)<=p)
	  {
	   if((i<<1)==p || x[f[i<<1]]>x[f[i<<1|1]])
	     j=i<<1;
	   else
	     j=i<<1|1;
	   if(x[f[i]]<x[f[j]])
	     {
		  swap(f[i],f[j]);
		  i=j;
		 }
	   else
	     break;
	  }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n+m;i++)
	  {
	   if(i<=n)
	     {
	      scanf("%d",&x[i]);
	      f[++p]=i;
	      up();
		 }
	   if(i>m)
	     {
		  a[f[1]]=i;
		  w+=(L)x[f[1]]*(i-f[1]);
		  f[1]=f[p--];
		  down();
		 }
	  }
	cout<<w<<"\n";
	for(i=1;i<=n;i++)
	  printf("%d ",a[i]);
	return 0;
}