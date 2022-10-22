/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 150005
#define B 2005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, f[maxn];
int dfn[maxn], out[maxn], tot, anc[maxn][22], dep[maxn], siz[maxn];
vector<int> G[maxn];
void dfs(int x, int fa)
{
	f[x] = fa;
	siz[x] = 1, dfn[x] = ++tot, dep[x] = dep[fa] + 1;
	anc[x][0] = fa; ru(i, 1, 20) anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for (auto V: G[x]) if(V ^ fa)
	{
		dfs(V, x);
		siz[x] += siz[V];
	}
	out[x] = tot;
}
int V[maxn], D[maxn], cnt;
int op[maxn], v[maxn], d[maxn];
int sum[maxn];
inline int qpow(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
inline int jump(int x, int d)
{
	rd(i, 17, 0) if((d >> i) & 1) x = anc[x][i];
	return x;
}
int val[maxn];
ll toleaf[maxn], invn;
inline void upd(int &x, int y)
{
	x += y;
	if(x >= mo) x -= mo;
 } 
inline void upd(ll &x, int y)
{
	x += y;
	if(x >= mo) x -= mo;
 } 
inline void work(int x, int fa)
{
	upd(toleaf[x], toleaf[fa]);
	upd(val[x], (ll)toleaf[x] * invn % mo);
	for (auto V: G[x]) if(V ^ fa) work(V, x);
	toleaf[x] = 0;
}

int hig[maxn], maxson[maxn], top[maxn], LOG[maxn], rt;
vector<int> up[maxn], down[maxn];
void dfs1(int x)
{
	dep[x] = dep[f[x]] + 1; anc[x][0] = f[x];
	for (int i = 1; i <= 20; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for (auto V: G[x]) if(V != f[x]) dfs1(V);
	for (auto V: G[x]) if(V != f[x]) if(hig[V] > hig[maxson[x]]) maxson[x] = V;
	hig[x] = hig[maxson[x]] + 1;
} 
void dfs2(int x, int p)
{
	top[x] = p;
	if(x == p)
	{
		for (int i = 1, now = x; i <= hig[x]; i++, now = f[now]) up[x].push_back(now);
		for (int i = 1, now = x; i <= hig[x]; i++, now = maxson[now]) down[x].push_back(now);
	}
	if(maxson[x]) dfs2(maxson[x], p); 
	for (auto V: G[x]) if(V != f[x] && V != maxson[x]) dfs2(V, V);
}
inline int query(int x, int k)
{
	if(!k) return x; 
	int y = top[anc[x][LOG[k]]], rem = k - (dep[x] - dep[y]);
	return rem >= 0 ? up[y][rem] : down[y][-rem];
}
int main()
{
	n = read(), q = read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0);
	ru(i, 2, n) LOG[i] = LOG[i >> 1] + 1;
	dfs1(1), dfs2(1, 1);
	int las = 0, S = 0; invn = qpow(n, mo - 2);
	ru(i, 1, q)
	{
		if(i % B == 0)
		{
			ll tmp = 0;
			ru(j, 1, n)
			{
				tmp += (ll)sum[j] * (n - siz[j]) % mo;
				toleaf[j] += mo - (ll)sum[j] * (n - siz[j]) % mo;
				for (auto V: G[j]) if(dep[V] > dep[j])
				{
					toleaf[V] += (ll)sum[j] * siz[V] % mo;
				}
				sum[j] = 0;
			}
			ru(j, 1, n) if(toleaf[j] >= mo) toleaf[j] %= mo;
			upd(S, tmp % mo * invn % mo);
			cnt = 0;
			work(1, 0);
			las = i;
		}
		op[i] = read(), v[i] = read();
		if(op[i] == 1)
		{
			d[i] = read();
			S = (S + d[i]) % mo;
			d[i] = (mo - d[i]) % mo;
			sum[v[i]] = (sum[v[i]] + d[i]) % mo;
			cnt++;
			V[cnt] = v[i], D[cnt] = d[i];
		}
		else
		{
			int ans = (S + val[v[i]]) % mo;
			ll tmp = 0;
			ru(j, 1, cnt) if(v[i] != V[j])
			{
				if(dfn[V[j]] <= dfn[v[i]] && dfn[v[i]] <= out[V[j]])
				{
					int pos = query(v[i], dep[v[i]] - dep[V[j]] - 1);
					tmp += (ll)D[j] * siz[pos];
				}
				else
				{
					tmp += (ll)D[j] * (n - siz[V[j]]);
				}
			}
			upd(ans, (ll)tmp % mo * invn % mo);
			printf("%d\n", ans);
		}
	}
	return 0;
}