#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
LL n,m,now;
int pre[1000010],nxt[1000010];
void dfs(LL n,LL m)
{
	if (now>=100000) return;
	if (m==0||n==1)
	{
		printf("%I64d ",n);
		now++;
		return;
	}
	for (int i=1;1LL*i*i<=n&&i>=1;i=nxt[i]) 
	if (n%i==0) 
	{
		dfs(i,m-1);
		if (now>=100000) return;
	}
	for (int i=sqrt(n-1);i>=1;i=pre[i])
	if (n%i==0)
	{ 
		dfs(n/i,m-1);
		if (now>=100000) return;
	}
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	if (n==1) 
	{
		printf("1\n");
		return 0;
	}
	if (m>=100000)
	{
		for (int i=1;i<=100000;i++) printf("1 ");
		return 0;
	}
	
	for (int i=1;1LL*i*i<=n;i++)
	if (n%i==0) nxt[i-1]=i,pre[i+1]=i;
	
	for (int i=1000000;i>=1;i--) if (!nxt[i]) nxt[i]=nxt[i+1];
	for (int i=1;i<=1000000;i++) if (!pre[i]) pre[i]=pre[i-1];
	dfs(n,m);
	return 0;
}