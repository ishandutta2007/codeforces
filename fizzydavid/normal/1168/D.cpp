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
//My i/o stream
struct fastio
{
	char s[100000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 100000, stdin);
		if (len==0) return EOF; else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while (c==' '||c=='\n') c=get();
		if (it>0) it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0; bool ng=0; char c; c=_buff.get();
	while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
	if (c=='-') ng=1, c=_buff.get();
	while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
	return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
	if (x<0) putchar('-'), x=-x;
	register short a[20]={}, sz=0;
	while (x) a[sz++]=x%10, x/=10;
	if(sz==0) putchar('0');
	for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 150111;
int n, q;
struct SGT
{
	struct node
	{
		int mx, lz;
		void addlz(int L)
		{
			lz += L;
			mx += L;
		}
	};
	vector<node> a;
	int n;
	void init(int _n)
	{
		n = _n;
		a.resize(n*4);
	}
	#define ls p<<1
	#define rs p<<1|1
	void pushdown(int p)
	{
		if (a[p].lz)
		{
			a[ls].addlz(a[p].lz);
			a[rs].addlz(a[p].lz);
			a[p].lz = 0;
		}
	}
	void update(int p)
	{
		a[p].mx = max(a[ls].mx, a[rs].mx);
	}
	void add(int x, int y, int v, int l, int r, int p)
	{
		if (r<x||y<l) return;
		if (x<=l&&r<=y)
		{
			a[p].addlz(v);
			return;
		}
		pushdown(p);
		int m = l+r>>1;
		add(x, y, v, l, m, ls);
		add(x, y, v, m+1, r, rs);
		update(p);
	}
	void add(int x, int y, int v) {add(x, y, v, 1, n, 1);}
	
	int query(int x, int y, int l, int r, int p)
	{
		if (x<=l&&r<=y) return a[p].mx;
		pushdown(p);
		int m = l+r>>1;
		if (x<=m&&m<y) return max(query(x, y, l, m, ls), query(x, y, m+1, r, rs));
		else if (x<=m) return query(x, y, l, m, ls);
		else return query(x, y, m+1, r, rs);
	}
	int query(int x, int y) {return query(x, y, 1, n, 1);}
	
	int querynxt(int x, int v, int l, int r, int p)
	{
		if (r<x||a[p].mx<v) return n+1;
		if (x<=l&&l==r) return l;
		pushdown(p);
		int m = l+r>>1;
		int ret = querynxt(x, v, l, m, ls);
		if (ret!=n+1) return ret; else return querynxt(x, v, m+1, r, rs);
	}
	int querynxt(int x, int v) {return querynxt(x, v, 1, n, 1);}
	
	int querypre(int x, int v, int l, int r, int p)
	{
		if (x<l||a[p].mx<v) return 0;
		if (r<=x&&l==r) return r;
		pushdown(p);
		int m = l+r>>1;
		int ret = querypre(x, v, m+1, r, rs);
		if (ret!=0) return ret; else return querypre(x, v, l, m, ls);
	}
	int querypre(int x, int v) {return querypre(x, v, 1, n, 1);}
	
	void build(int ia[], int l, int r, int p)
	{
		a[p].lz = 0;
		if (l==r)
		{
			a[p].mx = ia[l];
			return;
		}
		int m = l+r>>1;
		build(ia, l, m, ls);
		build(ia, m+1, r, rs);
		update(p);
	}
	void build(int ia[]) {build(ia, 1, n, 1);}
}T[26], T2[maxn];
vector<int> con[maxn];
int dfn[maxn], dfnr[maxn], dtot, sz[maxn], son[maxn], id[maxn], top[maxn];
int fa[maxn][20], cnt[maxn][26], ia[26][maxn];
vector<int> ia2[maxn];
int dep[maxn], maxdep;
char s[maxn];
void dfs(int x)
{
	maxdep = max(maxdep, dep[x]);
	dfn[x] = ++dtot;
	sz[x] = 1;
	for (int i=1; i<20; i++) fa[x][i] = fa[fa[x][i-1]][i-1];
	for (auto u : con[x])
	{
		for (int i=0; i<26; i++) ia[i][dtot+1] = ia[i][dfn[x]]+(s[u]=='a'+i); //dfn[u] = dtot+1 
		dep[u] = dep[x]+1;
		dfs(u);
		sz[x] += sz[u];
		if (sz[u]>sz[son[x]]) son[x] = u;
		for (int i=0; i<26; i++) cnt[x][i] = max(cnt[x][i], cnt[u][i]+(s[u]=='a'+i));
	}
	dfnr[x] = dtot;
}
void dfs2(int x, int tp)
{
	int sum = 0;
	for (int i=0; i<26; i++) sum += cnt[x][i];
	top[x] = tp;
	if (top[x]==x) id[x] = 1, ia2[x].PB(0); else id[x] = id[fa[x][0]]+1;
	ia2[top[x]].PB(-(maxdep-dep[x]-sum));
	if (son[x]) dfs2(son[x], tp);
	for (auto u : con[x])
	{
		if (u==son[x]) continue;
		dfs2(u, u);
	}
}
int CNT;
void add_route(int x, int l, int v)
{
	while (x)
	{
		if (id[x]<=l)
		{
			CNT -= T2[top[x]].a[1].mx>0;
			T2[top[x]].add(1, id[x], v);
			CNT += T2[top[x]].a[1].mx>0;
			l -= id[x];
			x = fa[top[x]][0];
		}
		else
		{
			CNT -= T2[top[x]].a[1].mx>0;
			T2[top[x]].add(id[x]-l+1, id[x], v);
			CNT += T2[top[x]].a[1].mx>0;
			return;
		}
	}
}
void add_letter(int x, int c, int v)
{
	c -= 'a';
	int curmx = T[c].query(dfn[x], dfnr[x])+(v>0);
	T[c].add(dfn[x], dfnr[x], v);
	int l, r;
	r = T[c].querynxt(dfnr[x]+1, curmx);
	l = T[c].querypre(dfn[x]-1, curmx);
	int p = x, len = 0;
	for (int i=19; i>=0; i--)
	{
		if (fa[p][i]&&dfn[fa[p][i]]>l&&dfnr[fa[p][i]]<r)
		{
			len += 1<<i;
			p = fa[p][i];
		}
	}
	add_route(fa[x][0], len, v);
}
int main()
{
	getii(n, q);
	for (int i=2; i<=n; i++)
	{
		int p;
		geti(p);
		char c = getreal();
		s[i] = c;
		con[p].PB(i);
		fa[i][0] = p;
	}
	dfs(1);
	dfs2(1, 1);
	for (int i=1; i<=n; i++) if (top[i]==i)
	{
		T2[i].init(ia2[i].size()-1);
		T2[i].build(&ia2[i][0]);
		CNT += T2[i].a[1].mx>0;
	}
	bool ok = true;
	for (int i=1; i<=n; i++) if (con[i].size()==0&&dep[i]!=maxdep) ok = false;
	for (int i=0; i<26; i++)
	{
		T[i].init(n);
		T[i].build(ia[i]);	
	}
	
	for (int i=1; i<=q; i++)
	{
		if (!ok)
		{
			puts("Fou");
			continue;
		}
		int x;
		geti(x);
		char c = getreal();
		if (s[x]!='?') add_letter(x, s[x], -1);
		s[x] = c;
		if (c!='?') add_letter(x, s[x], 1);
		if (ok&&CNT==0)
		{
			int ans = 0, sum = 0;
			int a[26];
			for (int j=0; j<26; j++) a[j] = T[j].a[1].mx, sum += a[j];
			for (int j=0; j<26; j++) ans += (j+1)*(maxdep-sum+a[j]);
			printf("Shi %d\n", ans);
		}
		else
		{
			puts("Fou");
		}
	}
	return 0;
}