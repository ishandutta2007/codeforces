#include<cstdio>
using namespace std;
int main()
{
	int n,a[1001],b,d[1001][2],j=1,k;	
	scanf("%d",&n);
	int c[100000],ans1=0;
	for(int i=1;i<=n;i++) c[i]=0;
	for(int i=1;i<=n;i++)
	{	
		scanf("%d",&b);
		c[i]=b;
		a[b]++;
	}
	for(int i=1;i<=1000;i++)
	{
		if(a[i]!=0) 
		{
			d[j][0]=i;
			d[j][1]=a[i];
			j++;
		}
	}
	for(k=1;k<j;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i]==d[k][0]&&d[k][1]>1)
			{
				c[i]=0;
				d[k][1]--;
			 } 
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=0)
		{
			ans1++;
		 } 
	}
	printf("%d\n",ans1);
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=0)
		{
			printf(" %d\n",c[i]);	
		}
	}
	return 0;
}