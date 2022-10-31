#include<cstdio>
#include<iostream>
using namespace std;
const int N=60;
int n,d;
int a[N];
int f[500010],g[500010];
int main()
{
	scanf("%d%d",&n,&d);
	int w=0;f[0]=1;
	for (int i=1;i<=n;i++) 
	{
		int x;
		scanf("%d",&x);
		w+=x;
		for (int j=w;j>=x;j--) f[j]|=f[j-x];
	}
	int cnt=0;
	for (int i=0;i<=w;i++)
	if (f[i]) g[++cnt]=i;
	int ans=0,now=0,j=0;
	while (1)
	{
		while (g[j+1]<=now+d&&j<cnt) j++;
		if (g[j]==now) break;
		now=g[j],ans++;
	}
	printf("%d %d\n",now,ans);
	return 0;
}