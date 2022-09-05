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
const int maxn = 500111;
const int inf = 1e7;
struct node
{
	int sz = 0; node *tl = NULL, *tr = NULL;
	int mn, mx, l_ask_r, r_ask_l;
	node (int arr[], int l, int r)
	{
		sz = r-l+1;
		if (sz==1)
		{
			mn = mx = arr[l];
		}
		else
		{
			int m = l+r>>1;
			tl = new node(arr, l, m);
			tr = new node(arr, m+1, r);
			update();
		}
	}
	void modify(int p, int v)
	{
		if (sz==1)
		{
			mn = mx = v;
			return;
		}
		if (p<=tl->sz) tl->modify(p, v);
		else tr->modify(p-tl->sz, v);
		update();
	}
	void update()
	{
		mn = min(tl->mn, tr->mn);
		mx = max(tl->mx, tr->mx);
		l_ask_r = tr->query(tl->mn, -inf);
		r_ask_l = tl->query(inf, tr->mx);
	}
	int query(int x, int y)
	{
		if (sz==1) return 0;
		if (x<=y) return 0;
		if (x<=mn||mx<=y) return 0;
		int l = min(x, tl->mn), r = max(y, tr->mx);
		int ret = l>r;
		if (x>tl->mx&&r==tr->mx) ret += r_ask_l; else ret += tl->query(x, r);
		if (y<tr->mn&&l==tl->mn) ret += l_ask_r; else ret += tr->query(l, y);
		return ret;
	}
	int get_ans()
	{
		return query(inf, -inf)+1;
	}
};
int n, q;
int a[maxn];
int main()
{
	getii(n, q);
	for (int i=1; i<=n; i++) geti(a[i]);
	node *rt = new node(a, 1, n);
	for (int i=1; i<=q; i++)
	{
		int x, v;
		getii(x, v);
		rt->modify(x, v);
		putsi(rt->get_ans());
	}
	return 0;
}