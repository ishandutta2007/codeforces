#include<bits/stdc++.h>
using namespace std;
int n,m,q,p,x[1000010],a[1000010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k=0;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	  {
	   for(j=a[i-1]+1;j<=a[i];j++)
	     if(j-m>0)
	       k-=x[j-m];
	   if(k<q-1)
	     {
		  k++;
		  x[a[i]]++;
		 }
	   else
	     p++;
	  }
	cout<<p;
	return 0;
}