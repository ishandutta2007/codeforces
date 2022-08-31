#include<bits/stdc++.h>
using namespace std;
int n,x[30],a[30]={0,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	for(i=1;i<=24;i++)
	  {
	   for(j=1;j<=n;j++)
	     if(x[j]!=a[(i+j-1)%24+1])
	       break;
	   if(j>n)
	     {
	      printf("YES\n");
	      return 0;
	     }
	  }
	a[2]++;
	for(i=1;i<=24;i++)
	  {
	   for(j=1;j<=n;j++)
	     if(x[j]!=a[(i+j-1)%24+1])
	       break;
	   if(j>n)
	     {
	      printf("YES\n");
	      return 0;
	     }
	  }
	printf("NO\n");
	return 0;
}