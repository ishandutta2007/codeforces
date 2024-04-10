#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,x[300010],a,b,p=1e9;
inline int sol(int a,int b)
{
	int i,j=0,k=0;
	for(i=1;i<=n;i++)
	  {
	   if(x[i]==1000)
	     a--;
	   else
	     b--;
	   if(x[i]==1000 && a>=0 || x[i]==2000 && b>=0)
	     k+=x[i],j+=x[i]/10;
	   else
	     k+=x[i]-min(x[i],j),j-=min(x[i],j);
	  }
	return k;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&x[i]);
	   m+=x[i];
	  }
	for(i=1;i<=n;i++)
	  {
	   m-=x[i]/10*11;
	   if(m<0)
	     break;
	   if(x[i]==1000)
	     a++;
	   else
	     b++;
	  }
	p=min(p,sol(a,b));
	p=min(p,sol(a+1,b));
	p=min(p,sol(a-1,b+1));
	printf("%d\n",p);
	return 0;
}