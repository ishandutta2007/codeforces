#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using ll = long long;

const int MN = 1e5+10;

int N, s[MN], C;
ll K, min, max;
bool used[MN];
std::vector<int> a[MN], left;
struct Sub
{
	public:
		int n,s;
		bool operator < (const Sub& o) const {return s < o.s;}
};
std::priority_queue<Sub> q;
struct Pairing
{
	public:
		int d, u, v;
		bool operator < (const Pairing& o) const {return d < o.d;}
};
std::vector<Pairing> rem[MN];
struct Match
{
	public:
		int u,v;
};
std::vector<Match> f;

int dfs(int n, int p=0)
{
	s[n]=1;
	for(int x:a[n])
		if(x!=p)
			s[n]+=dfs(x,n);
	return s[n];
}

int get_centroid(int n, int ms, int p=0)
{
	for(int x:a[n])
		if(x!=p && s[x]*2>=ms)
			return get_centroid(x, ms, n);
	return n;
}

void match(int u, int v)
{
	f.push_back({u,v});
	used[u]=used[v]=1;
}

int top;
int dfs2(int n, int p, int d=1)
{
	int u=-1;
	for(int x:a[n])
		if(x!=p)
		{
			int v = dfs2(x, n, d+1);
			if(!~v) continue;
			if(~u)
				rem[top].push_back({d, u, v}), u=-1;
			else
				u=v;
		}
	if(~u)
		return rem[top].push_back({d,u,n}), -1;
	else
		return n;
}

int pick(int n, int p, int d)
{
	int o = used[n]?-1:n;
	for(int x:a[n])
		if(x!=p)
		{
			int r=pick(x, n, d-1);
			if(r==-2) return -2;
			if(r==-1) continue;
			if(~o && d==0)
				return match(o, r), -2;
			o=r;
		}
	return o;
}

void dfs3(int n, int p=0)
{
	if(!used[n]) left.push_back(n);
	for(int x:a[n])
		if(x!=p)
			dfs3(x, n);
}

int main()
{
	scanf("%d%lld", &N, &K);
	for(int i=0,u,v;i+1<N;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	C=get_centroid(1, dfs(1));
	dfs(C);
	for(int i=1;i<=N;++i)
		if(i!=C)
			min+=s[i]&1, max+=s[i];
	if(K < min || 1&(K^min) || max < K)
		return printf("NO\n"), 0;
	for(int x:a[C])
	{
		top=x;
		dfs2(x, C);
		std::sort(rem[x].begin(), rem[x].end());
		q.push({x, s[x]});
	}
	for(;K < max;)
	{
		auto v=q.top(); q.pop();
		assert(!rem[v.n].empty());
		auto x=rem[v.n].back(); rem[v.n].pop_back();
		if(max - 2*x.d > K)
			match(x.u, x.v), max -= 2*x.d;
		else
		{
			pick(v.n, C, (max-K>>1)-1);
			break;
		}
		q.push({v.n, v.s-2});
	}
	dfs3(C);
	for(int i=0, L=left.size()/2;i<L;++i)
		match(left[i], left[i+L]);
	printf("YES\n");
	for(auto x:f)
		printf("%d %d\n", x.u, x.v);
	return 0;
}