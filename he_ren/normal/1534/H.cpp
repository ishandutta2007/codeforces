#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

inline int ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int f[MAXN];
vector<pii> sf[MAXN];

void dfs_up(int u,int fa)
{
	vector<pii> &vec = sf[u];
	vec.clear();
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_up(v,u);
		vec.push_back(make_pair(f[v], v));
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	f[u] = 1;
	for(int i=0; i<(int)vec.size(); ++i)
		f[u] = max(f[u], vec[i].first + i);
}

int ans = 0;

void dfs_down(int u,int fa)
{
	f[u] = 1;
	vector<pii> &vec = sf[u];
	if(!vec.size()) return;
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	vector<int> pre(vec.size()), suf(vec.size());
	for(int i=0; i<(int)vec.size(); ++i)
	{
		f[u] = max(f[u], pre[i] = suf[i] = vec[i].first + i);
		if(i)
			ans = max(ans, vec[i].first + vec[0].first + i - 1),
			pre[i] = max(pre[i], pre[i-1]);
	}
	ans = max(ans, vec[0].first + (int)vec.size() - 1);
	
	for(int i=(int)suf.size()-2; i>=0; --i)
		suf[i] = max(suf[i], suf[i+1]);
	
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int v = vec[i].second;
		if(v == fa) continue;
		int x = i? pre[i-1]: -inf;
		int y = i+1<(int)vec.size()? suf[i+1] - 1: -inf;
		
		sf[v].push_back(make_pair(max(1, max(x,y)), u));
		dfs_down(v,u);
	}
}

vector<int> ab;

int dfs_ask(int u)
{
	vector<pii> &vec = sf[u];
	if(!vec.size())
	{
		int res = ask(u);
		if(res == u) return ab.push_back(u), 0;
		return res;
	}
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int v = vec[i].second;
		int res = dfs_ask(v);
		if(!res) return 0;
		if(res != u) return res;
	}
	return ab.push_back(u), 0;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_up(1,0);
	dfs_down(1,0);
	
	printf("%d\n",ans);
	fflush(stdout);
	
	int p;
	scanf("%d",&p);
	
	dfs_up(p,0);
	
	vector<pii> &vec = sf[p];
	for(int i=0; i<(int)vec.size() && (int)ab.size() < 2; ++i)
	{
		int v = vec[i].second;
		dfs_ask(v);
	}
	ab.resize(2, p);
	
	printf("! %d %d",ab[0],ab[1]);
	fflush(stdout);
	return 0;
}