#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,x[60010],a[60010],p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,k=0;
	scanf("%d",&n);
	m=(L)n*(n+1)/2;
	for(i=n;i;i--)
	  if(k+i<=m/2)
	    {
	     k+=i;
	     a[++p]=i;
	    }
	printf("%d\n",m&1);
	printf("%d ",p);
	for(i=p;i>0;i--)
	  printf("%d ",a[i]);
	return 0;
}