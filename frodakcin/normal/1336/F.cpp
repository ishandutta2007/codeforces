#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

using ll = long long;

const int MN=1.5e5+10;
const int MS=3e7;
int N, M, K, d[MN], p[MN][20], vp[MN], pre[MN], post[MN], rm[MN], top, nd[MN], ctr, tot, t[MN], e[MN];
std::vector<int> up[MN], a[MN], b[MN], c[MN], pts, g[MN];
ll ans1, ans2, ans3;
struct QRY{public: int a, b;};
std::vector<QRY> q[MN];

void dfs(int n=1)
{
	pre[n] = ctr++;
	for(int i=0;p[n][i]&&p[p[n][i]][i];++i)
		p[n][i+1]=p[p[n][i]][i];
	for(int x:a[n])
		if(x!=p[n][0])
			p[x][0]=n,d[x]=d[n]+1,dfs(x);
	post[n] = ctr;
}
int mu(int x, int d)
{
	for(int i=0;d;d>>=1,++i)
		if(d&1)
			x=p[x][i];
	return x;
}
int lca(int x, int y)
{
	if(d[y]<d[x]) std::swap(x,y);
	if(d[y]!=d[x]) y=mu(y, d[y]-d[x]);
	if(x==y) return x;
	for(int i=19;i>=0;--i)
		if(p[x][i]!=p[y][i])
			x=p[x][i],y=p[y][i];
	return p[x][0];
}
bool anc(int x, int y) {return pre[x]<=pre[y] && post[y]<=post[x];}
int bit[MN];
void chg(int x, int v)
{
	for(++x;x<=N;x+=-x&x)
		bit[x-1]+=v;
	tot+=v;
}
int cnt(int x)
{
	int f=0;
	for(++x;x>0;x-=-x&x)
		f+=bit[x-1];
	return f;
}
int cnt2(int x) {return cnt(x)-cnt(x-1);}
void dfs1(int n=1)
{
	if(d[n]>=K)
		for(int x:up[n])
			ans1 += tot-cnt(x-1), chg(d[n]-K, 1);
	for(int x:a[n])
		if(x!=p[n][0])
			dfs1(x);
	if(d[n]>=K)
	{
		int vk = cnt2(d[n]-K);
		chg(d[n]-K, -vk);
		vk -= rm[n];
		assert(vk >= 0);
		if(d[n]==K) assert(!vk);
		if(vk) chg(d[n]-K-1, vk);
	}
}
struct stn
{
public:
	int c[2], v;
	stn() {c[0]=c[1]=-1; v=0;}
} st[MS];
int X;
void upd(int *n, int l, int r, int q, int v)
{
	if(!~*n) *n=X++;
	if(r-l>1)
	{
		int m=l+(r-l)/2;
		if(q<m) upd(st[*n].c, l, m, q, v);
		else upd(st[*n].c+1, m, r, q, v);
		st[*n].v=st[st[*n].c[0]].v+st[st[*n].c[1]].v;
	}
	else
		st[*n].v+=v;
}
int qry(int n, int l, int r, int ql, int qr)
{
	if(!~n) return 0;
	if(ql <= l&&r <= qr) return st[n].v;
	else
	{
		int m=l+(r-l)/2, f=0;
		if(ql < m) f+=qry(st[n].c[0], l, m, ql, qr);
		if(m < qr) f+=qry(st[n].c[1], m, r, ql, qr);
		return f;
	}
}
void dfs2(int n)
{
	for(int x:c[n])
	{
		if(d[x]==top) continue;
		if(d[x]+d[n]-2*top < K) continue;
		int o;
		if(d[n]-top >= K) o=mu(x, d[x]-top-1);
		else o=mu(x, d[x]+d[n]-2*top-K);
		ans2 += qry(nd[n], 0, N, pre[o], post[o]);
		upd(nd+n, 0, N, pre[x], 1);
		g[n].push_back(x);
	}
	for(int y:b[n])
	{
		t[y]=t[n];
		dfs2(y);
		if(g[n].size()<g[y].size())
			std::swap(g[n], g[y]), std::swap(nd[n], nd[y]);
		for(int x:g[y])
		{
			if(d[x]+d[n]-2*top < K) continue;
			int o;
			if(d[n]-top >= K) o=mu(x, d[x]-top-1);
			else o=mu(x, d[x]+d[n]-2*top-K);
			ans2 += qry(nd[n], 0, N, pre[o], post[o]);
			g[n].push_back(x);
		}
		for(int x:g[y])
			if(d[x]+d[n]-2*top >= K)
				upd(nd+n, 0, N, pre[x], 1);
		g[y].clear(), nd[y]=-1;
	}
}
void dfs3(int n)
{
	if(d[n]-top>=K)
		for(int x:c[n])
		{
			int o=mu(n, d[n]-top-K);//can be optimized but at this point its not the bottleneck
			ans3 += qry(e[0], 0, N, pre[o], post[o]), upd(e, 0, N, pre[n], 1);
			if(t[x]) ans3 -= qry(e[t[x]], 0, N, pre[o], post[o]), upd(e+t[x], 0, N, pre[n], 1);
		}
	for(int x:b[n])
		dfs3(x);
}
int main(void)
{
	memset(nd, -1, sizeof nd);
	memset(e, -1, sizeof e);
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0,x,y;i+1<N;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	dfs();
	for(int i=0,x,y;i<M;++i)
	{
		scanf("%d%d", &x, &y);
		int z=lca(x,y);
		//printf("LCA(%d, %d) = %d\n", x, y, z);
		if(d[x]+d[y]-2*d[z]<K) continue;
		if(d[x]-d[z]>=K) up[x].push_back(d[z]), ++rm[mu(x, d[x]-d[z]-K)];
		if(d[y]-d[z]>=K) up[y].push_back(d[z]), ++rm[mu(y, d[y]-d[z]-K)];
		q[z].push_back({x,y});
	}
	dfs1();
	for(int i=1;i<=N;++i) ans1 -= (ll)rm[i]*(rm[i]-1)/2;
	for(int i=1;i<=N;++i)
		if(!q[i].empty())
		{
			top=d[i];
			for(auto x:q[i])
				pts.push_back(x.a), pts.push_back(x.b);
			std::sort(pts.begin(), pts.end(), [](int a, int b){return pre[a]<pre[b];});
			pts.resize(std::distance(pts.begin(), std::unique(pts.begin(), pts.end())));
			for(int i=pts.size()-1;i>0;--i)
				pts.push_back(lca(pts[i-1], pts[i]));
			std::sort(pts.begin(), pts.end(), [](int a, int b){return pre[a]<pre[b];});
			pts.resize(std::distance(pts.begin(), std::unique(pts.begin(), pts.end())));

			int j=-1;
			assert(pts[0] == i);
			for(int x:pts)
				if(!~j) j=x;
				else
				{
					while(!anc(j, x)) j = vp[j];
					vp[x]=j, b[j].push_back(x);
					j=x;
				}
			for(auto x:q[i])
				c[x.a].push_back(x.b), c[x.b].push_back(x.a);
			j=1;
			for(int x:b[i])
			{
				t[x]=j++;
				dfs2(x);
				g[x].clear(), nd[x]=-1;
			}
			assert(!(ans2&1));
			dfs3(i);
			for(int x:pts)
			{
				if(d[x]-top>=K)
					for(int y:c[x])
					{
						upd(e, 0, N, pre[x], -1);
						if(t[y]) upd(e+t[y], 0, N, pre[x], -1);
					}
				b[x].clear(), c[x].clear(), vp[x]=0;
			}
			for(int x:pts) t[x]=0;
			pts.clear();
		}
	//printf("Breakdown: %lld %lld/2 %lld\n", ans1, ans2, ans3);
	printf("%lld\n", ans1+ans2/2+ans3);
	return 0;
}