#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge
{
	int next,to,w,c;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int w,int c)
{
	e[++etot] = (Edge){ head[u],v,w,c};
	head[u]=etot;
}

ll rem = 0;
vector<int> val[3], cnt[3];

int size[MAXN];
void dfs_size(int u,int fa)
{
	size[u] = 0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		
		dfs_size(v,u);
		size[u] += size[v];
		
		val[e[i].c].push_back(e[i].w);
		cnt[e[i].c].push_back(size[v]);
		
		rem += (ll)e[i].w * size[v];
	}
	if(!size[u]) size[u] = 1;
}

void solve(void)
{
	int n;
	ll s;
	scanf("%d%lld",&n,&s);
	etot = 0;
	for(int i=1; i<=n; ++i) head[i] = 0;
	for(int i=1; i<n; ++i)
	{
		int u,v,w,c;
		scanf("%d%d%d%d",&u,&v,&w,&c);
		add(u,v,w,c); add(v,u,w,c);
	}
	
	val[1].clear(); val[2].clear();
	cnt[1].clear(); cnt[2].clear();
	
	rem = 0;
	dfs_size(1,0);
	if(rem <= s)
	{
		printf("0\n");
		return;
	}
	
	vector<ll> eff[3];
	
	ll need = rem - s;
	for(int k=1; k<=2; ++k)
	{
		eff[k].push_back(0);
		vector<int> &val = ::val[k], &cnt = ::cnt[k];
		
		priority_queue<pli> q;
		
		for(int i=0; i<(int)val.size(); ++i)
			q.push(make_pair((ll)(val[i]+1)/2 * cnt[i], i));
		
		ll now = 0;
		while(now < need && !q.empty())
		{
			pli top = q.top(); q.pop();
			
			now += top.first;
			eff[k].push_back(now);
			
			int x = top.second;
			val[x]/=2;
			if(val[x]) q.push(make_pair((ll)(val[x]+1)/2 * cnt[x], x));
		}
	}
	
	int ans = inf;
	for(int i=0; i<(int)eff[1].size(); ++i)
	{
		ll more = need - eff[1][i];
		int pos = lower_bound(eff[2].begin(),eff[2].end(),more) - eff[2].begin();
		if(pos >= (int)eff[2].size()) continue;
		
		ans = min(ans, i + pos*2);
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}

/*
1
5 50
1 3 100
1 5 10
2 3 123
5 4 55
*/