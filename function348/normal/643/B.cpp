#include<cstdio>
#include<iostream>
using namespace std;
int n,k;
int v[101001];
int main()
{
	scanf("%d%d",&n,&k);
	if (k<=n||n==4) printf("-1\n");
	else
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		v[a]=v[b]=v[c]=v[d]=1;
		printf("%d %d ",a,c);
		for (int i=1;i<=n;i++)
		if (!v[i]) printf("%d ",i);
		printf("%d %d\n",d,b);

		printf("%d %d ",c,a);
		for (int i=1;i<=n;i++)
		if (!v[i]) printf("%d ",i);
		printf("%d %d\n",b,d);
	}
	return 0;
}