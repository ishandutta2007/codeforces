#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,ans;
LL a[20],s[20];
int fa[20],d[20];
void chk1()
{
	for (int i=1;i<=n;i++) s[i]=a[i];
	for (int i=2;i<=n;i++)
	{
		if (s[fa[i]]%a[i]==0) s[fa[i]]/=a[i];else return;
	}
	int res=n+d[1];
	for (int i=1;i<=n;i++)
	if (d[i]==1) res--;
	ans=min(ans,res);
}
void chk2()
{
	for (int i=2;i<=n;i++) s[i]=a[i];
	int res=n;
	for (int i=2;i<=n;i++) 
	if (fa[i]!=1)
	{
		if (s[fa[i]]%a[i]==0) s[fa[i]]/=a[i];else return;
	}
	else res+=d[i];
	for (int i=2;i<=n;i++)
	if (d[i]==1) res--;
	ans=min(ans,res);
}
void dfs(int p,int kd)
{
	if (p==1)
	{
		if (kd==1) chk1();
		if (kd==2) chk2();
	}
	for (int i=1;i<p;i++)
	{
		fa[p]=i;
		dfs(p-1,kd);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,greater<LL>());
	for (int i=1;i<=n;i++)
	{
		LL tmp=a[i];
		for (int j=2;1LL*j*j<=tmp;j++)
		while (tmp%j==0) d[i]++,tmp/=j;
		if (tmp!=1) d[i]++;
	}
	ans=1000;
	dfs(n,1);
	for (int i=n;i>=1;i--) a[i+1]=a[i],d[i+1]=d[i];
	n++;
	dfs(n,2);
	printf("%d\n",ans);
	return 0;
}