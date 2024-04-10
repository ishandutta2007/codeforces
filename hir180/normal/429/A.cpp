#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>edge[100005],res;
int nes[100005],a[100005],b[100005];
void dfs(int v,int u,int odd,int even,int depth)
{
	int x = depth%2==1?odd:even;
	if(nes[v] != x%2)
	{
		(depth%2==1?odd:even)+=1;
		res.push_back(v);
	}
	for(int i=0;i<edge[v].size();i++)
	{
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v,odd,even,depth+1);
	}
}
int main()
{
	scanf("%d",&n);
	
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++) nes[i] = (a[i]!=b[i]);
	dfs(1,-1,0,0,0);
	printf("%d\n",res.size());
	for(int i=0;i<res.size();i++)
	{
		printf("%d\n",res[i]);
	}
}