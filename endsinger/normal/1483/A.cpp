#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ans[N],c[N],s[N];
vector<int>a[N],v[N];
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		a[i].clear(),c[i]=0;
	for(int i=1;i<=m;i++)
	{
		ans[i]=0;
		scanf("%d",&s[i]);
		v[i].resize(s[i]);
		for(int j=0;j<s[i];j++)
		{
			scanf("%d",&v[i][j]);
			a[v[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i].size()<=(m+1)/2)
			for(auto x:a[i])
				ans[x]=i;
	int fl=0;
	for(int i=1;i<=m;i++)
	{
		if(s[i]==1&&!ans[i])
		{
			if(c[v[i][0]]<(m+1)/2)
				c[v[i][0]]++,ans[i]=v[i][0];
			else
				fl=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!ans[i])
		{
			int z=INT_MAX,p=0;
			for(auto x:v[i])
				if(c[x]<z)
					z=c[x],p=x;
			if(z>=(m+1)/2)
				fl=1;
			ans[i]=p;
			c[p]++;
		}
	}
	if(fl)
		puts("NO");
	else
	{
		puts("YES");
		for(int i=1;i<=m;i++)
			printf("%d ",ans[i]);
		puts("");
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}