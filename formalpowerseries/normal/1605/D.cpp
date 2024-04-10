#include<bits/stdc++.h>
using namespace std;
vector<int> G[200005];
int n,col[200005],ans[200005],used[200005];
void dfs(int now,int pre)
{
	col[now]=1-col[pre];
	for(auto st:G[now])	if(st!=pre)	dfs(st,now);
}
void Solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	G[i].clear(),col[i]=-1,ans[i]=0,used[i]=false;
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs(1,0);
	int c0=0,c1=0;
	vector<int> Z,O;
	for(int i=1;i<=n;++i)
	{
		if(col[i])	++c1,O.push_back(i);
		else	++c0,Z.push_back(i);
	}
	if(c0>c1)	Z.swap(O),swap(c0,c1);
	for(int i=0;i<20;++i)
	{
		if((c0>>i)&1)
		{
			int p=(1<<(i+1))-1,q=(1<<i);
			for(int j=p;j>=q;--j)
			{
				int st=Z.back();
				Z.pop_back();
				ans[st]=j;
				used[j]=true;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(used[i])	continue;
		int st=O.back();
		O.pop_back();
		ans[st]=i;
	}
	for(int i=1;i<=n;++i)	printf("%d%c",ans[i],i==n?'\n':' ');
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}