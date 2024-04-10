//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
const int maxn = 100111;
int n, m;
int f[maxn];
vector<pair<int,pair<int,int> > > E;
int gf(int x) {return f[x]==x?x:f[x]=gf(f[x]);}
int ex[1000111], ey[1000111], ew[1000111];
vector<pair<int,int> > v;
bool tree[1000111];
int ans[1000111];
vector<pair<int,int> > con[maxn];
int fa[20][maxn], fav[20][maxn], mini[20][maxn];
int lv[maxn];
void dfs(int x)
{
	for (int i=1; i<20; i++) fa[i][x] = fa[i-1][fa[i-1][x]];
	for (int i=1; i<20; i++) fav[i][x] = max(fav[i-1][x], fav[i-1][fa[i-1][x]]);
	for (int i=0; i<20; i++) mini[i][x] = 1e9;
	for (auto e : con[x])
	{
		int u = e.FF;
		if (u==fa[0][x]) continue;
		fav[0][u] = e.SS;
		fa[0][u] = x;
		lv[u] = lv[x]+1;
		dfs(u);
	}
}
int getlca(int x, int y)
{
	if (lv[x]>lv[y]) swap(x, y);
	for (int i=19; i>=0; i--) if (lv[y]-lv[x]>=(1<<i)) y = fa[i][y];
	if (x==y) return x;
	for (int i=19; i>=0; i--) if (fa[i][x]!=fa[i][y])
	{
		x = fa[i][x];
		y = fa[i][y];
	}
	return fa[0][x];
}
int getmx(int x, int p)
{
	int ret = 0;
	for (int i=19; i>=0; i--)
	{
		if (lv[x]-lv[p]>=(1<<i))
		{
			ret = max(ret, fav[i][x]);
			x = fa[i][x];
		}
	}
	return ret;
}
void upd(int &x, int v) {x=min(x,v);}
void minipath(int x, int p, int v)
{
	for (int i=19; i>=0; i--)
	{
		if (lv[x]-lv[p]>=(1<<i))
		{
			upd(mini[i][x], v);
			x = fa[i][x];
		}
	}
}
void afterwork()
{
	for (int i=19; i>0; i--)
	{
		for (int j=1; j<=n; j++)
		{
			upd(mini[i-1][j], mini[i][j]);
			upd(mini[i-1][fa[i-1][j]], mini[i][j]);
		}
	}
}
int main()
{
	for (int i=0; i<maxn; i++) f[i] = i;
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		ex[i] = x;
		ey[i] = y;
		ew[i] = w;
		v.PB(MP(w, i));
	}
	sort(v.begin(), v.end());
	for (auto t : v)
	{
		int id = t.SS;
		int x = ex[id];
		int y = ey[id];
		int w = ew[id];
		x = gf(x);
		y = gf(y);
		if (x!=y)
		{
			f[x] = y;
			tree[id] = true;
			con[x].PB(MP(y, w));
			con[y].PB(MP(x, w));
		}
	}
	lv[1] = 1;
	dfs(1);
	for (int i=1; i<=m; i++)
	{
		if (!tree[i])
		{
			int x = ex[i], y = ey[i];
			int p = getlca(x, y);
			ans[i] = max(getmx(x, p), getmx(y, p));
			minipath(x, p, ew[i]);
			minipath(y, p, ew[i]);
		}
	}
	afterwork();
	for (int i=1; i<=m; i++)
	{
		if (tree[i])
		{
			int x = ex[i], y = ey[i];
			if (fa[0][x]==y)
			{
				ans[i] = mini[0][x];
			}
			else
			{
				ans[i] = mini[0][y];
			}
		}
		else
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}