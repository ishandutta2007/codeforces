#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,x;
int ans1,ans2;
int a[110];
int main()
{
	scanf("%d",&n);
	int p=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			if (j<=m/2) ans1+=x;
			if (j>(m+1)/2) ans2+=x;
			if (j*2-1==m) a[++p]=x;
		}
	}
	sort(a+1,a+1+p,greater<int>());
	for (int i=1;i<=p;i++)
	if (i%2==1) ans1+=a[i];else ans2+=a[i];
	printf("%d %d\n",ans1,ans2);
	return 0;
}