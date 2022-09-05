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
const int maxn = 200111;
int n, m;
int mex[maxn], a[maxn];
bool hs[maxn];
int xsum[maxn];
vector<int> con[maxn];
void dfs(int x)
{
	if (mex[x]!=-1) return; 
	for (auto u : con[x])
	{
		dfs(u);
	}
	for (auto u : con[x]) hs[mex[u]] = 1;
	mex[x] = 0;
	while (hs[mex[x]]) mex[x]++;
	for (auto u : con[x]) hs[mex[u]] = 0;
	xsum[mex[x]] ^= a[x];
}
void output_ans(int L)
{
	static int ans[maxn];
	for (int i=1; i<=n; i++) ans[i] = a[i];
	int x = -1;
	for (int i=1; i<=n; i++)
	{
		if (mex[i]==L)
		{
			if ((xsum[L]^a[i])<a[i])
			{
				x = i;
				break;
			}
		}
	}
	ans[x] = xsum[L]^a[x];
	for (auto u : con[x])
	{
		if (!hs[mex[u]])
		{
			hs[mex[u]] = true;
			ans[u] = xsum[mex[u]]^a[u];
		}
	}
	for (int i=1; i<=n; i++) puti(ans[i]);
}
int main()
{
	getii(n, m);
	for (int i=1; i<=n; i++) geti(a[i]);
	for (int i=1; i<=m; i++)
	{
		int x, y;
		getii(x, y);
		con[x].PB(y);
	}
	memset(mex, -1, sizeof(mex));
	for (int i=1; i<=n; i++)
	{
		if (mex[i]==-1) dfs(i); 
	}
	for (int i=n; i>=0; i--)
	{
		if (xsum[i]!=0)
		{
			puts("WIN");
			output_ans(i);
			return 0;
		}
	}
	puts("LOSE");
	return 0;
}