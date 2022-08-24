#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,a[100010],x[100010],y[100010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	  x[i]=x[i-1]|a[i];
	for(i=n;i>0;i--)
	  y[i]=y[i+1]|a[i];
	for(i=1;i<=n;i++)
	  if(x[n]-(x[i-1]|y[i+1])>=k)
	    k=x[n]-(x[i-1]|y[i+1]),j=i;
	swap(a[1],a[j]);
	for(i=1;i<=n;i++)
	  printf("%d ",a[i]);
	return 0;
}