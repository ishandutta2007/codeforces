#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
vector<int> G[105];
int dis[105][105];
void dfs(int u,int f,int d,int p)
{
	dis[p][u]=dis[u][p]=d;
	for(auto v:G[u])	if(v^f)	dfs(v,u,d+1,p);
}
char d[105][105][105];
bool check(vector<pair<int,int>> Ed)
{
	for(int i=1;i<=n;++i)	G[i].clear();
	for(auto E:Ed)
	{
		int u=E.first,v=E.second;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i)	dfs(i,i,0,i);
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				if(d[i][j][k]=='1')
				{
					if(dis[i][k]^dis[j][k])	return false;
				}
				else
				{
					if(dis[i][k]==dis[j][k])	return false;
				}
			}
		}
	}
	return true;
}
struct unionFindSet{
	int fa[10005];
	void makeSet(int up){for(int i=0;i<=up;++i)	fa[i]=i;}
	int findSet(int x){return x==fa[x]?x:fa[x]=findSet(fa[x]);}
	void unionSet(int x,int y)
	{
		int xx=findSet(x),yy=findSet(y);
		if(xx==yy)	return ;
		fa[yy]=xx;
	}
}ufs;
int trans(int x,int y){if(x>y)	swap(x,y);return (x-1)*n+y;}
bool vis[10005];
vector<int> ed[10005];
void Solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	for(int j=i+1;j<=n;++j)	scanf("%s",d[i][j]+1);
	ufs.makeSet(n*n);
	for(int i=1;i<=n;++i)	for(int j=i+1;j<=n;++j)	for(int k=1;k<=n;++k)	if(d[i][j][k]=='1')	ufs.unionSet(trans(i,k),trans(j,k));
	for(int i=1;i<=n*n;++i)	vis[i]=false;
	for(int i=1;i<=n*n;++i)	ed[i].clear();
	for(int i=1;i<=n*n;++i)	ed[ufs.findSet(i)].push_back(i);
	vector<pair<int,int>> Ans;
	#define mp make_pair
	for(int i=1;i<=n*n;++i)
	{
		if(int(ed[i].size())!=n-1)	continue;
		static bool pos[105];
		memset(pos,false,sizeof pos);
		static vector<pair<int,int>> E;
		E.clear();
		for(auto e:ed[i])
		{
			int u=(e+n-1)/n,v=e%n;
			if(!v)	v=n;
			pos[u]=true,pos[v]=true;
			E.push_back(mp(u,v));
		}
		for(int j=1;j<=n;++j)	if(!pos[j])	goto fail;
		if(check(E))
		{
			Ans=E;
			break;
		}
		fail:;
	}
	if(Ans.size())
	{
		puts("Yes");
		for(auto e:Ans)	printf("%d %d\n",e.first,e.second);
	}
	else	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}