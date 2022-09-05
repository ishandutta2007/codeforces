//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod = 1e9+7;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 400111;
struct BIT
{
	ll a[maxn];
	int ti[maxn], curt;
	void clear()
	{
		curt++;
	}
	void add(int x, ll v)
	{
		for (int i=x; i<maxn; i+=i&(-i))
		{
			if (ti[i]!=curt) ti[i] = curt, a[i] = 0;
			a[i] += v;
		}
	}
	ll query(int x)
	{
		ll ret = 0;
		for (int i=x; i; i-=i&(-i))
		{
			if (ti[i]!=curt) ti[i] = curt, a[i] = 0;
			ret += a[i];
		}
		return ret;
	}
}B0, B1;
struct data
{
	vector<pair<int,pair<int,int> > > line;
	vector<pair<int, pair<int, ll*> > > qry;
	vector<pair<pair<int, int>, pair<int, ll*> > > qry2;
	void add_line(int l, int r, int h) //(x, y) l<=x<=r y=h
	{
		line.PB(MP(h, MP(l, r)));
	}
	void add_query(int r, int a, int b, ll *it) //(x, y) x<=r a<=y<=b-x   y>=a x+y<=b
	{
		int h = b-r;
		qry.PB(MP(h, MP(b, it)));
		qry2.PB(MP(MP(h, -1), MP(r, it)));
		qry2.PB(MP(MP(a, 1), MP(r, it)));
	}
	void solve()
	{
//		cerr<<"solve:"<<endl;
//		for (auto x : line) cerr<<x.FF<<","<<x.SS.FF<<","<<x.SS.SS<<endl;
//		for (auto x : qry) cerr<<x.FF<<","<<x.SS.FF<<endl;
		
		sort(line.begin(), line.end());
		sort(qry.begin(), qry.end());
		sort(qry2.begin(), qry2.end());
		reverse(line.begin(), line.end());
		reverse(qry.begin(), qry.end());
		reverse(qry2.begin(), qry2.end());
		
		int it;
		it = 0; B0.clear(); B1.clear();
		for (auto X : qry)
		{
			while (it<line.size()&&line[it].FF>=X.FF)
			{
				int l = line[it].SS.FF+line[it].FF;
				int r = line[it].SS.SS+line[it].FF;
				B1.add(l, 1);
				B0.add(l, -(l-1));
				B1.add(r+1, -1);
				B0.add(r+1, (l-1)+r-l+1);
				it++;
			}
			*X.SS.SS += B0.query(X.SS.FF)+1ll*B1.query(X.SS.FF)*X.SS.FF;
		}
		it = 0; B0.clear(); B1.clear();
		for (auto X : qry2)
		{
			while (it<line.size()&&line[it].FF>=X.FF.FF)
			{
				int l = line[it].SS.FF;
				int r = line[it].SS.SS;
				B1.add(l, 1);
				B0.add(l, -(l-1));
				B1.add(r+1, -1);
				B0.add(r+1, (l-1)+r-l+1);
				it++;
			}
			*X.SS.SS += X.FF.SS*(B0.query(X.SS.FF)+1ll*B1.query(X.SS.FF)*X.SS.FF);
		}
	}
}D[maxn];
int go[maxn][26], pre[maxn], len[maxn], tot=1;
vector<int> son[maxn];
int hson[maxn], top[maxn], sz[maxn];
int append(int p, int c)
{
	int np = ++tot;
	len[np] = len[p]+1;
	while (p&&!go[p][c]) go[p][c] = np, p = pre[p];
	if (!p)
	{
		pre[np] = 1;
		return np;
	}
	int q = go[p][c];
	if (len[q]==len[p]+1) pre[np] = q;
	else
	{
		int nq = ++tot;
		len[nq] = len[p]+1;
		for (int i=0; i<26; i++) go[nq][i] = go[q][i];
		pre[nq] = pre[q];
		pre[q] = pre[np] = nq;
		while (p&&go[p][c]==q) go[p][c] = nq, p = pre[p];
	}
	return np;
}
int n;
char s[maxn];
int st[maxn];
void dfs(int x)
{
	sz[x] = 1;
	for (auto u : son[x])
	{
		dfs(u);
		sz[x] += sz[u];
		if (sz[u]>sz[hson[x]]) hson[x] = u;
	}
}
void dfs2(int x, int tp)
{
	top[x] = tp;
	if (hson[x]) dfs2(hson[x], tp);
	for (auto u : son[x])
	{
		if (u!=hson[x]) dfs2(u, u);
	}
}
void add_suffix(int id)
{
	int x = st[id];
	while (x)
	{
		D[top[x]].add_line(len[pre[top[x]]]+1, len[x], id);
		x = pre[top[x]];
	}
}
void prework()
{
	st[n+1] = 1;
	for (int i=n; i>=1; i--)
	{
		st[i] = append(st[i+1], s[i]-'a');
	}
	
//	for (int i=1; i<=tot; i++) cerr<<pre[i]<<","<<len[i]<<" "; cerr<<endl;
//	for (int i=1; i<=n; i++) cerr<<st[i]<<" "; cerr<<endl;
	
	for (int i=2; i<=tot; i++) son[pre[i]].PB(i);
	dfs(1);
	dfs2(1, 1);
	
	for (int i=1; i<=n; i++)
	{
		add_suffix(i);
	}
}

int q;
ll ans[maxn];
void add_query(int l, int r, ll *it)
{
	int x = st[l];
	while (x)
	{
		int L = len[pre[top[x]]]+1;
		if (L<=r-l+1)
		{
			D[top[x]].add_query(min(r-l+1, len[x]), l, r+1, it);
		}
		x = pre[top[x]];
	}
}

void solve()
{
	for (int i=1; i<=tot; i++) D[i].solve();
}

int main()
{
	scanf("%s", s+1);
	n = strlen(s+1);
	prework();
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		add_query(l, r, &ans[i]);
	}
	solve();
	for (int i=1; i<=q; i++) printf("%I64d\n", ans[i]);
	return 0;
}