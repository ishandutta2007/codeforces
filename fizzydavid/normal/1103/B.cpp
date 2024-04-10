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
char s[10];
bool get()
{
	scanf("%s", s);
	if (s[0]=='x') return 1;
	else if (s[0]=='y') return 0;
	else exit(0);
}
const int mx = 1000000000;
void query(int l, int r)
{
	if (r==2)
	{
		puts("? 2 1");
		fflush(stdout);
		if (get())
		{
			puts("! 1");
		}
		else
		{
			puts("! 2");
		}
	}
	else
	{
		while (l<r)
		{
			int m = l+r>>1;
			printf("? %d %d\n", l-1, m);
			fflush(stdout);
			if (get()) r = m;
			else l = m+1;
		}
		printf("! %d\n", l);
	}
	fflush(stdout);
}
void solve()
{
	for (int i=0; i<30; i++)
	{
		int l = 1<<i, r = min(mx, l*2);
		printf("? %d %d\n", l, r);
		fflush(stdout);
		if (get())
		{
			query(l+1, r);
			return;
		}
	}
}
int main()
{
	while (true)
	{
		scanf("%s", s);
		if (s[0]=='e'||s[0]=='m')
		{
			return 0;
		}
		solve();
	}
	return 0;
}