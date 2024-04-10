#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;
int n,m,w[200010],f[5000000],l[5000000],r[5000000],p,q;
L t;
inline int sum(int i,int j,int k,int ll,int rr)
{
	if(ll<=j && k<=rr)
	  return f[i];
	else
	  {
	   int p=0;
	   if(ll<=(j+k>>1))
	     p+=sum(l[i],j,j+k>>1,ll,rr);
	   if(rr>(j+k>>1))
	     p+=sum(r[i],(j+k>>1)+1,k,ll,rr);
	   return p;
	  }
}
inline int sum(int i,int j,int k,int u)
{
	if(j<i || u<k)
	  return 0;
	return sum(w[j],1,p,k,u)-sum(w[i-1],1,p,k,u);
}
inline L C(int n)
{
	return (L)n*(n-1)>>1;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,u,ll,rr;
	scanf("%d%d",&n,&m);
	for(p=1;p<n;p<<=1);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&j);
	   w[i]=++q;
	   f[q]=f[w[i-1]]+1;
	   for(k=q,u=w[i-1],ll=1,rr=p;ll<rr;)
	     if(j<=(ll+rr>>1))
	       {
			r[k]=r[u];
			k=l[k]=++q;
			u=l[u];
			f[k]=f[u]+1;
			rr=(ll+rr>>1);
		   }
		 else
		   {
			l[k]=l[u];
			k=r[k]=++q;
			u=r[u];
			f[k]=f[u]+1;
			ll=(ll+rr>>1)+1;
		   }
	  }
	while(m--)
	  {
	   scanf("%d%d%d%d",&i,&j,&k,&u);
	   t=C(n);
	   t-=C(i-1)+C(j-1)+C(n-k)+C(n-u);
	   t+=C(sum(1,i-1,1,j-1))+C(sum(1,i-1,u+1,n))+C(sum(k+1,n,1,j-1))+C(sum(k+1,n,u+1,n));
	   printf("%I64d\n",t);
	  }
	return 0;
}