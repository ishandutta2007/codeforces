#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int prime[1000005],tot;
bool vis[1000005];
void linear_shaker()
{
	for(int i=2;i<=1000000;i++)
	{
		if(!vis[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=1000000;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int a[150005];
int b[150005];
int c[150005],cnt=0;
int n;
bool cal(int x)
{
	for(int i=2;i<=n;i++)
	{
		if(a[i]%x&&b[i]%x) return 0;
	}
	return 1;
}
int main ()
{
	scanf("%d",&n);
	linear_shaker();
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=1;i<=tot;i++)
	{
		if(a[1]%prime[i]==0||b[1]%prime[i]==0) c[++cnt]=prime[i];
		while(a[1]%prime[i]==0) a[1]/=prime[i];
		while(b[1]%prime[i]==0) b[1]/=prime[i];
	}
	if(a[1]>1) c[++cnt]=a[1];
	if(b[1]>1) c[++cnt]=b[1];
	for(int i=1;i<=cnt;i++)
	{
		if(cal(c[i])) return printf("%d\n",c[i]),0;
	}
	printf("-1\n");
	return 0;
}