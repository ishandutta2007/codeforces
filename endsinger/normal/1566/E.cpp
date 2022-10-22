#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
vector<int>e[N];
void dfs(int u,int f)
{
	a[u]=0;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dfs(v,u);
		a[u]+=!(a[v]);
	}
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	int s=0,t=0;
	for(int i=2;i<=n;i++)
		if(a[i])
			s++,t+=a[i]-1;
	if(a[1])
		t+=a[1];
	else if(s)
		t++;
	printf("%d\n",t);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}