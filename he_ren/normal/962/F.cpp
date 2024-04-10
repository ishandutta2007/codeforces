#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef unsigned int uint;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

struct Edge
{
	int next,from,to;
}e[MAXM*2];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],u,v};
	head[u]=etot;
}

struct BCC
{
	int size;
	vector<int> e;
	BCC(){ size=0; e.clear();}
}bcc[MAXM];
int bcnt=0;

int dfn[MAXN],low[MAXN],cur=0;
void tarjan(int u,int fa)
{
	static int nbcc[MAXN];
	static stack<int> sta;
	
	dfn[u]=low[u]=++cur;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		if(!dfn[v])
		{
			sta.push(i);
			tarjan(v,u);
			chk_min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				++bcnt;
				int ne;
				do
				{
					ne=sta.top(); sta.pop();
					int nu=e[ne].from, nv=e[ne].to;
					
					if(nbcc[nu]!=bcnt) nbcc[nu]=bcnt, ++bcc[bcnt].size;
					if(nbcc[nv]!=bcnt) nbcc[nv]=bcnt, ++bcc[bcnt].size;
					bcc[bcnt].e.push_back((ne+1)>>1);
				}while(ne!=i);
			}
		}
		else if(dfn[v]<dfn[u])
			sta.push(i),
			chk_min(low[u],dfn[v]);
	}
}

vector<int> ans;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	for(int i=1; i<=n; ++i)
		if(!dfn[i]) tarjan(i,0);
	
	for(int i=1; i<=bcnt; ++i)
	{
		if(bcc[i].size != (int)bcc[i].e.size()) continue;
		for(uint j=0; j<bcc[i].e.size(); ++j)
			ans.push_back(bcc[i].e[j]);
	}
	
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(uint i=0; i<ans.size(); ++i)
		printf("%d ",ans[i]);
	return 0;
}