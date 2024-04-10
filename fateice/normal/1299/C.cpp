#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,a[1000010],y[1000010],p;
double x[1000010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&a[i]);
	   x[++p]=a[i];
	   y[p]=1;
	   while(p>1 && x[p]<x[p-1])
	     {
          x[p-1]=(x[p]*y[p]+x[p-1]*y[p-1])/(y[p-1]+y[p]);
          y[p-1]+=y[p];
          p--;
         }
      }
    for(i=1;i<=p;i++)
      for(j=1;j<=y[i];j++)
        printf("%.12lf\n",x[i]);
	return 0;
}