#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=2e5+5;
int n,du[N],head[N],tot,ans;

vector<int> agg[N];

struct Edge
{
	int v,ne;
}e[N*2];

inline void add(int u,int v);
inline void dfs(int u,int fa,int last);

int main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		du[u]++,du[v]++;
		add(u,v);
		add(v,u);
		ans=max(ans,max(du[u],du[v]));
	}
	printf("%d\n",ans);
	dfs(1,-1,0);
	for(int i=1;i<=ans;++i)
	{
		printf("%d ",agg[i].size());
		for(int j=0;j<agg[i].size();++j)
			printf("%d ",agg[i][j]);
		printf("\n");
	}
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

inline void dfs(int u,int fa,int last)
{
	int j=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		if(j==last)
			j++;
		agg[j].push_back((i+1)/2);
		dfs(v,u,j);
		++j;
	}
	return;
}