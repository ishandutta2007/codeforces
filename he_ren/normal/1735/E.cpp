#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int inf = 0x3f3f3f3f;

template<const int MAXN,const int MAXM>
struct Max_Flow
{
	struct Edge
	{
		int next,to,flow;
	}e[MAXM<<1];
	int head[MAXN], etot;
	inline void add_one(int u,int v,int flow)
	{
		e[++etot] = (Edge){ head[u],v,flow};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int flow)
	{
		add_one(u,v,flow); add_one(v,u,0);
	}
	
	int n,s,t;
	int dep[MAXN], cur[MAXN];
	void clear(int _n=MAXN-1){ etot=-1; memset(head,-1,(_n+1)<<2);}
	void init(int _n,int _s,int _t){ n=_n; s=_s; t=_t;}
	Max_Flow(void){ clear();}
	inline bool bfs(void)
	{
		memset(dep,-1,(n+1)<<2); memcpy(cur,head,(n+1)<<2);
		queue<int> q;
		dep[s] = 0; q.emplace(s);
		while(q.size())
		{
			int u = q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
				if(dep[v] == -1)
				{
					dep[v] = dep[u] + 1; q.emplace(v);
					if(v == t) return 1;
				}
			}
		}
		return 0;
	}
	inline int dfs(int u,int maxf)
	{
		if(u == t || !maxf) return maxf;
		int res = 0, f;
		for(int &i=cur[u]; ~i; i=e[i].next)
			if(e[i].flow && dep[e[i].to] == dep[u]+1 && (f = dfs(e[i].to, min(maxf, e[i].flow))))
			{
				e[i].flow -= f; e[i^1].flow += f;
				res += f; maxf -= f;
				if(!maxf) return res;
			}
		return res;
	}
	inline int dinic(void)
	{
		int res = 0;
		while(bfs()) res += dfs(s, inf);
		return res;
	}
	inline int getmatch(int u)
	{
		for(int i=head[u]; ~i; i=e[i].next)
			if(e[i^1].flow) return e[i].to;
		return 0;
	}
};

Max_Flow<MAXN * 2, MAXN * 10> mf;

int a[MAXN], b[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i)
		scanf("%d",&b[i]);
	
	static int dsc[MAXN], bak[MAXN];
	int dcnt = 0;
	for(int i=1; i<=n; ++i)
		dsc[++dcnt] = b[i];
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	
	auto getid = [&] (ll x) -> int
	{
		if(x > dsc[dcnt]) return 0;
		int pos = lower_bound(dsc+1,dsc+dcnt+1,x) - dsc;
		if(pos > dcnt || dsc[pos] != x)
			return 0;
		else
			return pos;
	};
	
	for(int i=1; i<=dcnt; ++i)
		bak[i] = 0;
	for(int i=1; i<=n; ++i)
		++bak[getid(b[i])];
	
	int S = n + dcnt + 1, T = S + 1;
	mf.init(T, S, T);
	
	int ans = -1;
	auto chkans = [&] (ll k)
	{
		if(ans != -1) return;
		
		mf.clear(T);
		for(int i=1; i<=n; ++i)
			mf.add_edge(S, i, 1);
		for(int i=1; i<=dcnt; ++i)
			mf.add_edge(n+i, T, bak[i]);
		
		for(int i=1; i<=n; ++i)
		{
			auto add = [&] (ll oth)
			{
				int j = getid(oth);
				if(j) mf.add_edge(i, n+j, 1);
			};
			add(a[i] + k);
			add(a[i] - k);
			add(k - a[i]);
		}
		
		if(mf.dinic() == n)
			ans = k;
	};
	
	for(int i=1; i<=n; ++i)
	{
		chkans(a[1] + b[i]);
		chkans(abs(a[1] - b[i]));
	}
	
	if(ans == -1)
	{
		printf("NO\n");
		return;
	}
	
	ll p1 = 0, p2 = ans;
	static ll h[MAXN];
	for(int i=1; i<=n; ++i)
	{
		ll oth = dsc[mf.getmatch(i) - n];
		if(abs(p1 - a[i] - p2) == oth) h[i] = p1 - a[i];
		else h[i] = p1 + a[i];
		assert(abs(h[i] - p2) == oth);
	}
	
	ll mn = min(0ll, *min_element(h+1, h+n+1));
	p1 -= mn; p2 -= mn;
	for(int i=1; i<=n; ++i)
		h[i] -= mn;
	
	printf("YES\n");
	for(int i=1; i<=n; ++i)
		printf("%lld ",h[i]);
	printf("\n");
	printf("%lld %lld\n",p1,p2);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}