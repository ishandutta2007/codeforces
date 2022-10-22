#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[200005],b[200005],ans;
bool vis[200005],in[200005],f[200005],flag;
vector<int> ed1[200005],ed2[200005];
void dfs(int x) 
{
	vis[x]=in[x]=true;
	for(int i=0;i<ed1[x].size();i++) 
	{
		if(in[ed1[x][i]]) 
		{
			flag=true;
			break;
		}
		if(!vis[ed1[x][i]]) dfs(ed1[x][i]);
	}
	in[x]=false;
}
bool vis1[200005],vis2[200005];
void dfs1(int x) 
{
	vis1[x]=true;
	f[x]=true;
	for(int i=0;i<ed1[x].size();i++) 
	{
		if(!vis1[ed1[x][i]]) dfs1(ed1[x][i]);
	}
}
void dfs2(int x) 
{
	vis2[x]=true;
	f[x]=true;
	for(int i=0;i<ed2[x].size();i++) 
	{
		if(!vis2[ed2[x][i]]) dfs2(ed2[x][i]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) 
	{
		scanf("%d%d",&a[i],&b[i]);
		ed1[a[i]].push_back(b[i]); 
		ed2[b[i]].push_back(a[i]);
	} 
	for(int i=1;i<=n;i++) if(!vis[i] && !flag) dfs(i);
	if(flag) 
	{
		printf("-1\n");
		return 0;
	}
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		bool tmp=!f[i];
		if(!f[i]) ans++;
		dfs1(i);
		dfs2(i);
		if(tmp) f[i]=false;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) 
	{
		if(f[i]) printf("E");
		else printf("A");
	}
	return 0;
}