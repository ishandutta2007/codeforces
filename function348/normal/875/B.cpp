#include <cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,tot;
int c[301000];
int main()
{
	scanf("%d",&n);
	int k=n;
	printf("1 ");
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		c[x]=1;while (c[k]) k--;
		printf("%d ",i+1-(n-k));
	}
	return 0;
}