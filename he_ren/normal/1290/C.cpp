#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;
const int MAXP = MAXM*2;

int n,m;
int fa[MAXP],size[MAXP],must[MAXP];
int find(int u){ return fa[u]==u? u: fa[u]=find(fa[u]);}
inline void connect(int u,int v)
{
	int fu=find(u), fv=find(v);
	if(fu==fv) return;
	size[fv]+=size[fu];
	fa[fu]=fv;
}

char s[MAXM];
vector<int> g[MAXN];
bool chs[MAXP];

int main(void)
{
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1; i<=m; ++i)
	{
		int d;
		scanf("%d",&d);
		while(d--)
		{
			int x;
			scanf("%d",&x);
			g[x].push_back(i);
		}
	}
	
	for(int i=1; i<=m; ++i)
	{
		fa[i<<1] = i<<1;
		fa[i<<1|1] = i<<1|1;
		size[i<<1|1] = 1;
		chs[i<<1]=1;
		must[i<<1] = must[i<<1|1] = -1;
	}
	
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		if(g[i].size()==1)
		{
			int u=g[i][0];
			int u0 = find(u<<1);
			int u1 = find(u<<1|1);
			if(s[i]=='1')
			{
				if(chs[u1])
				{
					ans-=size[u1]; ans+=size[u0];
					chs[u1]=0; chs[u0]=1;
				}
				must[u0]=1; must[u1]=0;
			}
			if(s[i]=='0')
			{
				if(chs[u0])
				{
					ans+=size[u1]; ans-=size[u0];
					chs[u1]=1; chs[u0]=0;
				}
				must[u0]=0; must[u1]=1;
			}
		}
		else if(g[i].size()==2)
		{
			int u=g[i][0], v=g[i][1];
			int u0 = find(u<<1), u1 = find(u<<1|1);
			int v0 = find(v<<1), v1 = find(v<<1|1);
			if(s[i]=='0') swap(u0,u1);
			
			if(chs[u0] != chs[v0])
			{
				if(chs[u0])
				{
					ans+=size[u1]; ans-=size[u0];
					chs[u1]=1; chs[u0]=0;
				}
				else
				{
					ans-=size[u1]; ans+=size[u0];
					chs[u1]=0; chs[u0]=1;
				}
			}
			connect(u0,v0);
			connect(u1,v1);
			if(must[v0]==-1) must[v0]=must[u0];
			if(must[v1]==-1) must[v1]=must[u1];
			if(chs[v1]) swap(u0,u1), swap(v0,v1);
			
			if((must[v0]!=1 && size[v0]>size[v1]) || must[v1]==1)
			{
				ans-=size[v0]; ans+=size[v1];
				chs[v0]=0; chs[v1]=1;
			}
		}
		/*
		printf("\n[%d]:\n",(int)g[i].size());
		for(int i=1; i<=m; ++i)
		{
			printf("%d: ",i);
			int u0 = find(i<<1);
			int u1 = find(i<<1|1);
			printf("%d(%d) %d(%d) ",u0>>1,u0&1,u1>>1,u1&1);
			printf("\t%d %d",chs[u1],must[u1]);
			printf("\n");
		}
		*/
		printf("%d\n",ans);
	}
	return 0;
}