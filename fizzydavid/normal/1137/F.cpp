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
const int maxn = 400111;
struct data
{
	int a[maxn];
	void add(int x, int v)
	{
		for (int i=x; i; i-=i&(-i)) a[i] += v;
	}
	int query(int x)
	{
		int ret = 0;
		for (int i=x; i<maxn; i+=i&(-i)) ret += a[i];
		return ret;
	}
}D;
void update_ans(int x, int v, int coef)
{
	D.add(x, v*coef);
}
struct LCT
{
	struct node
	{
		bool rev;
		int p;
		int fa, go[2], sz;
	}a[maxn];
	#define ls a[p].go[0]
	#define rs a[p].go[1]
	#define getdir(p) (a[a[p].fa].go[0]==p?0:(a[a[p].fa].go[1]==p?1:-1))
	void pushdown(int p)
	{
		if (a[p].rev)
		{
			swap(ls, rs);
			if (ls) a[ls].rev ^= 1;
			if (rs) a[rs].rev ^= 1;
			a[p].rev = 0;
		}
		if (ls) a[ls].p = a[p].p;
		if (rs) a[rs].p = a[p].p;
	}
	void pushroute(int p)
	{
		if (getdir(p)!=-1) pushroute(a[p].fa);
		pushdown(p);
	}
	void update(int p)
	{
		a[p].sz = a[ls].sz+a[rs].sz+1;
	}
	void rotate(int p, int d)
	{
		int q = a[p].go[d], r = a[q].go[d^1];
		if (getdir(p)!=-1) a[a[p].fa].go[getdir(p)] = q;
		a[q].go[d^1] = p;
		a[p].go[d] = r;
		a[q].fa = a[p].fa;
		a[p].fa = q;
		a[r].fa = p;
		update(p);
	}
	void splay(int p, int t=0)
	{
		pushroute(p);
		while (getdir(p)!=-1&&a[p].fa!=t)
		{
			int q = a[p].fa, r = a[q].fa;
			int dq = getdir(p), dr = getdir(q);
			if (dr==-1||r==t) rotate(q, dq);
			else
			{
				if (dq==dr) rotate(r, dr), rotate(q, dq);
				else rotate(q, dq), rotate(r, dr);
			}
		}
		update(p);
	}
	void up(int x, int p)
	{
		splay(x);
		a[x].go[1] = 0;
		update(x);
		update_ans(a[x].p, a[x].sz, -1);
		while (a[x].fa)
		{
			int fa = a[x].fa;
			splay(fa);
			a[fa].go[1] = 0;
			update(fa);
			update_ans(a[fa].p, a[fa].sz, -1);
			a[fa].go[1] = x;
			splay(x);
		}
		update_ans(p, a[x].sz, 1);
		a[x].p = p;
		a[x].rev ^= 1;
	}
}T;
int n, q, tot;
vector<int> con[maxn];
void dfs(int x, int pre=-1)
{
	T.a[x].sz = 1;
	for (auto u : con[x])
	{
		if (u==pre) continue;
		T.a[u].fa = x;
		dfs(u, x);
	}
}
int query(int x)
{
	T.splay(x);
	int p = T.a[x].p;
	return n-(D.query(p)-T.a[T.a[x].go[1]].sz-1);
}
int main()
{
	getii(n, q);
	for (int i=1; i<n; i++)
	{
		int x, y;
		getii(x, y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs(1);
	for (int i=2; i<=n; i++) T.up(i, i-1);
	tot = n;
	for (int i=1; i<=q; i++)
	{
		char c = getreal();
		if (c=='u')
		{
			int x;
			geti(x);
			T.up(x, tot++);
		}
		else if (c=='w')
		{
			int x;
			geti(x);
			putsi(query(x));
		}
		else if (c=='c')
		{
			int x, y;
			getii(x, y);
			int qx = query(x), qy = query(y);
			if (qx<qy) putsi(x); else putsi(y); 
		}
	}
	return 0;
}