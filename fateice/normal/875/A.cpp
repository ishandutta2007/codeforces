#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,x[1000],m;
inline bool check(int p)
{
	int k=p;
	while(p)
	  {
	   k+=p%10;
	   p/=10;
	  }
	return k==n;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=n-100;i<=n;i++)
	  if(check(i))
	    x[++m]=i;
	printf("%d\n",m);
	for(i=1;i<=m;i++)
	  printf("%d\n",x[i]);
	return 0;
}