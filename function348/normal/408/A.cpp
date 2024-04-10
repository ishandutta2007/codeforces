#include<cmath>
#include<iostream>
#include<cstdio>
int n,a[110];
int main()
{
	int min=1<<30;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++){
		int k=a[i]*15;
		for (int j=0;j<a[i];j++)
		{
			int x;
			scanf("%d",&x);
			k+=x*5;
		}
		min= k<min?k:min
		;
	}
	printf("%d\n",min);
}