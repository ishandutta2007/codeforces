#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N],b[N],c[N],n,m;
int dfs(int p)
{
	if(p==n+1)
		return 1;
	int x=b[p];
	if(a[x])
	{
		a[x]--;
		c[p]=x;
		if(dfs(p+1))
			return 1;
		a[x]++;
	}
	int k=-1;
	for(int i=x-1;i>=0;i--)
	{
		if(a[i])
		{
			k=i;
			break;
		}
	}
	if(k==-1)
		return 0;
	c[p]=k;
	a[k]--;
	for(int i=9;i>=1;i--)
		while(a[i]--)
			c[++p]=i;
	return 1;
}
int main()
{
	while(1)
	{
		char c=getchar();
		if(c=='\n')
			break;
		n++;
		a[c-'0']++;	
	}
	while(1)
	{
		char c=getchar();
		if(c=='\n')
			break;
		b[++m]=c-'0';
	}
	if(m>n)
	{
		for(int i=9;i>=0;i--)
		{
			while(a[i]--)
				printf("%d",i);
		}
		return 0;
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%d",c[i]);
	return 0;
}