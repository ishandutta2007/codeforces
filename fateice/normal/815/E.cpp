#include<bits/stdc++.h>
#define L long long
using namespace std;
L n,m,x[10000],f[10000],g[10000],w;
int p,k;
inline void add(L a,L b)
{
	if(a)
	  if(x[p]==a)
	    f[p]+=b;
	  else if(x[p-1]==a)
	    f[p-1]+=b;
	  else
	    {
	     x[++p]=a;
	     f[p]=b;
	 	}
}
inline L ask(L a)
{
	while(x[k]<a)
	  k--;
	while(x[k]>a)
	  k++;
	return g[k];
}
inline L solve(L l,L r,L m)
{
	if((r-l>>1)==w)
	  {
	   m--;
	   if(!m)
	     return l+r>>1;
	  }
	if(ask(r-l>>1)>=m)
	  return solve(l,(l+r>>1)-1,m);
	else
	  return solve((l+r>>1)+1,r,m-ask(r-l>>1));
}
int main()
{
	//freopen("adr.in","r",stdin);
	//freopen("adr.out","w",stdout);
	int i,j;
	scanf("%lld%lld",&n,&m);
	if(m==1)
	  {
	   cout<<1;
	   return 0;
	  }
	else if(m==2)
	  {
	   cout<<n;
	   return 0;
	  }
	m-=2;
	p=1;
	x[1]=n-2;
	f[1]=1;
	for(i=1;;i++)
	  {
	   m-=f[i];
	   add(x[i]>>1,f[i]);
	   add(x[i]-1>>1,f[i]);
	   if(m<=0)
	     break;
	  }
	w=x[i]-1>>1;
	k=i;
	j=i;
	for(i=p;i>0;i--)
	  {
	   if((x[i]-1>>1)==w)
	     {
	      g[i]=1;
	      if(i<=j)
	        m+=f[i];
	     }
	   if((x[i]-1>>1)>=w)
	     g[i]+=ask(x[i]>>1)+ask(x[i]-1>>1);
	  }
	printf("%lld\n",solve(2,n-1,m));
	return 0;
}