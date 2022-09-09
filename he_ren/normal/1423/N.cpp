#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int MAXN = 1.3e4 + 5;
const int MAXM = 1e6 + 5;

struct Edge
{
	int next,to;
}e[MAXM<<1];
int head[MAXN], etot = 0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int sum[MAXN], val[MAXN], ew[MAXM];

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
	
	for(int i=1; i<=m; ++i) ew[i] = 1;
	for(int i=1; i<=etot; ++i)
		++sum[e[i].to];
	
	for(int u=1; u<=n; ++u)
	{
		vector<int> posi, nega;
		static bool has[MAXM * 2];
		
		for(int i=head[u]; i; i=e[i].next) if(e[i].to < u)
		{
			int v = e[i].to;
			has[sum[v]] = 1;
			if(val[v]) posi.push_back(i);
			else nega.push_back(i);
		}
		
		int use = 0;
		for(int i = -(int)nega.size(); i <= (int)posi.size(); ++i)
			if(!has[sum[u] + i]){ use = i; break;}
		
		sum[u] += use;
		if(use > 0)
		{
			for(int j=0; j<use; ++j)
			{
				int eid = posi[j];
				ew[(eid + 1) >> 1] = 2;
				val[e[eid].to] = 0;
			}
		}
		else if(use < 0)
		{
			use = -use;
			for(int j=0; j<use; ++j)
			{
				int eid = nega[j];
				ew[(eid + 1) >> 1] = 0;
				val[e[eid].to] = 1;
			}
		}
		
		for(int i=head[u]; i; i=e[i].next) if(e[i].to < i)
			has[sum[e[i].to]] = 0;
	}
	
	int keep = 0;
	for(int i=1; i<=n; ++i)
		if(val[i]) ++keep;
	
	printf("%d\n",keep);
	for(int i=1; i<=n; ++i)
		if(val[i]) printf("%d ",i);
	putchar('\n');
	
	for(int i=1; i<=m; ++i)
		printf("%d %d %d\n",e[i<<1].to, e[(i<<1)-1].to, ew[i]);
	return 0;
}