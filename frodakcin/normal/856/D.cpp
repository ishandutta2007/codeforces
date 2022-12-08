#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 2e5+10;
const int MM = 2e5+10;
const int MV = 1e4+10;

struct Qry
{
	public:
		int a,b,c;
};

struct bit: public std::vector<int>
{
	public:
		int sz;
		void init(int _sz)
		{
			sz=_sz;
			assign(sz*4, 0);
		}
		bit(int _sz=0): sz(_sz), std::vector<int>(_sz*4, 0) {}
		void upd(int n, int v)
		{
			assert(0<=n&&n<sz);
			for(++n;n<=sz;n+=-n&n)
				at(n-1)+=v;
		}
		int qry(int n)
		{
			assert(0<=n&&n<=sz);
			int v=0;
			for(;n;n-=-n&n)
				v+=at(n-1);
			return v;
		}
		int qry(int l, int r) {return qry(r)-qry(l);}
};


int N, M, dp[MN], p[MN][20], s[MN], d[MN], h[MN], l[MN], t[MN], lv[MN];
std::vector<int> a[MN];
std::vector<Qry> q[MN];
bit hv[MN];

int dfs1(int n=1)
{
	for(int i=0;p[n][i]&&p[p[n][i]][i];++i)
		p[n][i+1]=p[p[n][i]][i];
	s[n]=1;
	for(int x:a[n])
		if(x!=p[n][0])
			d[x]=d[n]+1, p[x][0]=n, s[n]+=dfs1(x);
	return s[n];
}

void dfs2(int n=1)
{
	for(int x:a[n])
		if(x!=p[n][0])
		{
			if(s[x]*2>s[n]) // >= ok too
			{
				h[n]=x;
				if(!~t[n]) t[n]=n, l[n]=0;
				t[x]=t[n], l[x]=l[n]+1;
			}
			dfs2(x);
		}
	if(~t[n] && !~h[n])
		hv[t[n]].init(l[n]);
}

int mu(int a, int b)
{
	for(int i=0;b;++i)
		if(b>>i&1)
			a=p[a][i], b^=1<<i;
	return a;
}

int lca(int a, int b)
{
	if(d[a]<d[b]) std::swap(a,b);
	a=mu(a, d[a]-d[b]);
	if(a==b) return a;
	for(int i=19;i>=0;--i)
		if(p[a][i]!=p[b][i])
			a=p[a][i], b=p[b][i];
	return p[a][0];
}

void upd(int n, int v, bool hc)
{
	lv[n]+=v;
	if(!hc && ~h[n])
		hv[t[n]].upd(l[n], v);
}

int get(int n)
{
	if(~h[n])
		return dp[h[n]]+hv[t[n]].qry(l[n], l[n]+1);
	else
		return lv[n];
}

int qup(int n, int g) // qry up, n exclusive, g inclusive 
{
	int f=0;
	for(;d[n]>g;)
	{
		if(~t[n] && t[n]!=n)
			if(d[t[n]]>g) // equality shouldn't matter
				f+=hv[t[n]].qry(l[n]), n=t[n];
			else
				return f+hv[t[n]].qry(g-d[t[n]], l[n]);
		else
			f+=lv[p[n][0]]-dp[n], n=p[n][0];
	}
	return f;
}

void dfs(int n=1)
{
	for(int x:a[n])
		if(x!=p[n][0])
			dfs(x);
	dp[n]=lv[n];
	for(auto x:q[n])
	{
		int v=lv[n]+x.c;
		for(int u:{x.a, x.b})
			if(u!=n)
			{
				assert(get(u)==lv[u]); // get is deprecated by just using lv
				v+=lv[u];
				v+=qup(u, d[n]+1);
				v-=dp[mu(u, d[u]-d[n]-1)];
			}
		ckmax(dp[n], v);
	}
	//printf("%d: %d\n", n, dp[n]);
	if(n!=1) // root
		upd(p[n][0], dp[n], h[p[n][0]]==n);
}

int main()
{
	memset(h, -1, sizeof h);
	memset(t, -1, sizeof t);
	memset(l, -1, sizeof l);
	scanf("%d%d", &N, &M);
	for(int i=2,u;i<=N;++i)
		scanf("%d", &u), a[u].push_back(i), a[i].push_back(u);
	dfs1();
	dfs2();
	//for(int i=1;i<=N;++i) printf("%2d: %2d %2d %2d\n", i, d[i], p[i][0], s[i]);
	//for(int i=1;i<=N;++i) printf("%2d: %2d %2d %2d\n", i, h[i], t[i], l[i]);
	for(int i=0, a, b, c;i<M;++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		int l=lca(a,b);
		//printf("lca(%d, %d) = %d\n", a, b, l);
		q[l].push_back({a,b,c});
	}
	dfs();
	printf("%d\n", dp[1]);
	return 0;
}