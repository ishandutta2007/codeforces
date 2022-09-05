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

const int mod = 1e9+7;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n, m;
vector<int> con[100111];
map<pair<int,int>,pair<int,int> > go;
void match(int x, int y, int d)
{
//	cerr<<x<<"-"<<y<<" "<<d<<endl;
	go[MP(x,d)] = MP(y, d+1);
	go[MP(y,d)] = MP(x, d+1);
}
pair<int,int> seg[100111];
void dfs(int x, int p=-1)
{
	for (auto u : con[x])
	{
		if (u==p) continue;
		int d;
		if (seg[x].FF>0)
		{
			seg[x].FF--;
			match(x, u, seg[x].FF);
			seg[u] = MP(seg[x].FF, seg[x].FF+1);
		}
		else if (seg[x].SS<m)
		{
			match(x, u, seg[x].SS);
			seg[u] = MP(seg[x].SS, seg[x].SS+1);
			seg[x].SS++;
		}
		else assert(false);
		dfs(u, x);
	}
	go[MP(x, seg[x].SS)] = MP(x, seg[x].FF);
}
int main()
{
	geti(n);
	if (n==1)
	{
		puts("1");
		puts("1 0");
		return 0;
	}
	for (int i=1; i<n; i++)
	{
		int x, y;
		getii(x, y);
		con[x].PB(y);
		con[y].PB(x);
	}
	for (int i=1; i<=n; i++) m = max(m, int(con[i].size()));
	for (int i=1; i<=n; i++)
	{
		if (con[i].size()==1)
		{
			dfs(i);
			break;
		}
	}
	vector<pair<int,int> > ans;
	int x = 1, y = 0;
	while (true)
	{
		ans.PB(MP(x, y));
		auto np = go[MP(x, y)];
		x = np.FF; y = np.SS;
		if (x==1&&y==0) break;
	}
	putsi(ans.size());
	for (auto p : ans) putsii(p.FF, p.SS);
	return 0;
}