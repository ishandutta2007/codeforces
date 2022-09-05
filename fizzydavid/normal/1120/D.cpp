//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
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
const int maxn = 200111;
int n;
struct node
{
	int v, id;
	int go[2];
}a[maxn*5];
int tot;
int newnode(int v, int id)
{
	int p = ++tot;
	a[p].v = v;
	a[p].id = id;
	return p;
}
int merge(int p, int q)
{
	if (!p||!q) return p^q;
	if (a[p].v<a[q].v) swap(p, q);
	a[p].go[1] = merge(a[p].go[1], q);
	swap(a[p].go[0], a[p].go[1]);
	return p;
}
int pop(int p)
{
	return merge(a[p].go[0], a[p].go[1]);
}
vector<int> con[maxn];
int w[maxn];
int A[maxn], B[maxn];
bool ok[maxn];
int dom[maxn];
ll sum;
ll getsum(int p)
{
	if (!p) return 0;
	return a[p].v+getsum(a[p].go[0])+getsum(a[p].go[1]);
}
void dfs(int x, int pre=-1)
{
//	cerr<<"dfs:"<<x<<" "<<pre<<endl;
	bool leaf = 1;
	for (auto u : con[x])
	{
		if (u==pre) continue;
		dfs(u, x);
		leaf = 0;
		A[x] = merge(A[x], A[u]);
	}
	if (!leaf)
	{
		if (w[x]<=a[A[x]].v)
		{
			sum += getsum(A[x])-a[A[x]].v;
			ok[x] = 1;
			int tmp = a[A[x]].v, cur = a[A[x]].id;
			if (w[x]<a[A[x]].v)
			{
				A[x] = pop(A[x]);
				if (!A[x]||a[A[x]].v<tmp) ok[cur] = 0;
			}
			else
			{
				A[x] = pop(A[x]);
				if (!A[x]||a[A[x]].v<tmp) dom[cur] = x;
			}
			A[x] = newnode(w[x], x);
		}
	}
	else
	{
		A[x] = newnode(w[x], x);
		ok[x] = 1;
	}
}
void dfs2(int x, int pre)
{
	if (dom[x]) ok[x] &= ok[dom[x]];
	for (auto u : con[x])
	{
		if (u==pre) continue;
		dfs2(u, x);
	}
}
vector<int> v;
void getv(int p)
{
	if (p) v.PB(a[p].id); else return;
	getv(a[p].go[0]); getv(a[p].go[1]);
}
int main()
{
	geti(n);
	for (int i=1; i<=n; i++) geti(w[i]);
	for (int i=1; i<n; i++)
	{
		int x, y;
		getii(x, y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs(1);
//	for (int i=1; i<=n; i++) cerr<<ok[i]<<" "; cerr<<endl;
	sum += getsum(A[1]);
	dfs2(1, -1);
	int cnt = 0;
	for (int i=1; i<=n; i++) cnt += ok[i];
	putsii(sum, cnt);
	for (int i=1; i<=n; i++) if (ok[i]) puti(i);
	return 0;
}