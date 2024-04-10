#include <cstdio>
#include <cstring>
#include <vector>

template<typename T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}

const int MN = 1e5+10, INF = 0x3f3f3f3f;

int N, M, s[MN], m[MN][2], t, b, d;
bool r[MN], red[MN];
std::vector<int> a[MN], v[MN];
struct info
{
	public:
		int n,b,d;
};
std::vector<info> g[MN];

int dfs(int n, int p=0)
{
	s[n]=1;
	for(auto x:a[n])
		if(x!=p&&!r[x])
			s[n]+=dfs(x, n);
	return s[n];
}
int find(int n, int ms, int p=0)
{
	for(auto x:a[n])
		if(!r[x]&&x!=p&&s[x]*2>ms)
			return find(x, ms, n);
	return n;
}
void dfs2(int n, int p=0)
{
	for(auto x:a[n])
		if(!r[x]&&x!=p)
			++d, dfs2(x, n), --d;
	g[n].push_back({t,b,d});
}
void centroid(int n=1)
{
	n = find(n, dfs(n));
	v[n].reserve(a[n].size());
	for(auto x:a[n])
		if(!r[x])
		{
			t=n, b=v[n].size(), d=1;
			dfs2(x, n);
			v[n].push_back(INF);
		}
	r[n]=1;
	for(auto x:a[n])
		if(!r[x])
			centroid(x);
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0,u,v;i+1<N;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	centroid();
	memset(m, 0x3f, sizeof m);
	for(int i=0,t=1,n=1;i<=M;++i)
	{
		if(t==1)
		{
			for(auto x:g[n])
			{
				int &q=v[x.n][x.b];
				if(x.d<q)
				{
					if(m[x.n][0]==q) m[x.n][0]=x.d;
					else for(int i=0,u=x.d;i<2;++i) if(u<m[x.n][i]) std::swap(u, m[x.n][i]);
					q=x.d;
				}
			}
			red[n]=1;
			m[n][0]=0;
		}
		else
		{
			int f=m[n][0];
			for(auto x:g[n])
				if(x.d)
					ckmin(f, m[x.n][v[x.n][x.b]==m[x.n][0]]+x.d);
			printf("%d\n", f);
		}
		if(i<M) scanf("%d%d", &t, &n);
	}
	return 0;
}