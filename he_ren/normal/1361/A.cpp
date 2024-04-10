#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
const int MAXM = 5e5 + 5;

struct Edge
{
	int next,to;
}e[MAXM<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int a[MAXN];

struct Node
{
	int id,a;
}p[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.a < q.a;}

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
	{
		scanf("%d",&a[i]);
		p[i]=(Node){i,a[i]};
	}
	
	sort(p+1,p+n+1,cmp);
	
	for(int k=1; k<=n; ++k)
	{
		int u = p[k].id;
		
		vector<int> t;
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			if(a[v] == a[u]){ printf("-1"); return 0;}
			if(a[v] < a[u]) t.push_back(a[v]);
		}
		
		sort(t.begin(), t.end());
		t.resize(unique(t.begin(),t.end()) - t.begin());
		
		if((int)t.size() != a[u]-1){ printf("-1"); return 0;}
	}
	
	for(int i=1; i<=n; ++i)
		printf("%d ",p[i].id);
	return 0;
}