#include<bits/stdc++.h>
using namespace std;
int n,m,x[1010];
double y[1010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&x[i]);
	   y[i]=m;
	   for(j=1;j<i;j++)
	     if(abs(x[i]-x[j])<=2*m)
	       y[i]=max(y[i],y[j]+sqrt(4*m*m-abs(x[i]-x[j])*abs(x[i]-x[j])));
	   printf("%.8lf ",y[i]);
	  }
	return 0;
}