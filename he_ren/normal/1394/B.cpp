#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXD = 10 + 5;

struct Edge
{
	int next,to,w;
}e[MAXM];
int head[MAXN],etot=0, odeg[MAXN];
inline void add(int u,int v,int w)
{
	e[++etot]=(Edge){ head[u],v,w};
	head[u]=etot;
	++odeg[u];
}

bool can[MAXD][MAXD];
bitset<MAXN> a[MAXD][MAXD];

bool cant[MAXD][MAXD][MAXD][MAXD];

int ans = 0;

int d;
int chs[MAXD];

void dfs(int dep)
{
	if(dep<=0)
	{
		++ans;
		return;
	}
	
	for(int i=1; i<=dep; ++i) if(can[dep][i])
	{
		bool flag = 1;
		for(int j=dep+1; j<=d; ++j)
			if(cant[dep][i][j][chs[j]])
			{
				flag = 0;
				break;
			}
		if(!flag) continue;
		
		chs[dep]=i;
		dfs(dep-1);
	}
}

int main(void)
{

	int n,m;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	
	for(int i=1; i<=d; ++i)
		for(int j=1; j<=i; ++j)
			can[i][j] = 1;
	
	for(int u=1; u<=n; ++u)
	{
		int now = odeg[u];
		
		vector<pii> vec;
		for(int i=head[u]; i; i=e[i].next)
			vec.push_back(make_pair(e[i].w, e[i].to));
		sort(vec.begin(), vec.end());
		
		for(int i=1; i<=now; ++i)
		{
			int v = vec[i-1].second;
			if(!can[now][i]) continue;
			if(a[now][i][v])
			{
				can[now][i] = 0;
				continue;
			}
			a[now][i][v] = 1;
		}
	}
	
	for(int x=1; x<=d; ++x)
		for(int i=1; i<=x; ++i) if(can[x][i])
			for(int y=1; y<x; ++y)
				for(int j=1; j<=y; ++j) if(can[y][j])
					if((a[x][i] & a[y][j]).any())
						cant[x][i][y][j] = cant[y][j][x][i] = 1;
		
	dfs(d);
	printf("%d",ans);
	return 0;
}