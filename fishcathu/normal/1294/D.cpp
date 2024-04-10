#include<stdio.h>
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	int a[x]={0};
	for(int m,k=0;n--;)
	{
		scanf("%d",&m);
		int j=m%x;
		a[j]++;
		if(j==k)
		{
			int i=k+1,l=a[k]-1,r=a[k];
			for(;i<x&&a[i]!=l;i++);
			if(i<x)k=i;
			else
			{
				for(i=0;i<k&&a[i]!=r;i++);
				k=i;
			}
		}
		printf("%d\n",a[k]*x+k);
	}
	return 0;
}