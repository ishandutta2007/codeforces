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
const int mod=1e9+7;
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
char s[1000111];
char a[1000111];
char b[1000111];
int mt[30];
bool hs[30];
int n, k;
bool OK;
void output()
{
	bool hs[30] = {};
	for (int i=0; i<k; i++)
	{
		if (mt[i]!=-1) hs[mt[i]] = 1;
	}
	int it = 0;
	for (int i=0; i<k; i++)
	{
		while (hs[it]) it++;
		if (mt[i]==-1) mt[i] = it, hs[it] = 1;
	}
	puts("YES");
	for (int i=0; i<k; i++) putchar('a'+mt[i]);
	puts("");
	OK = 1;
}
void dfs(int x, bool fa, bool fb)
{
	if (OK) return;
	if (x==n) output();
	if (OK) return;
	if (!fa&&!fb) output();
	if (OK) return;
	for (int i=0; i<k; i++)
	{
		if (fa&&'a'+i<a[x]) continue;
		if (fb&&'a'+i>b[x]) continue;
		int c = s[x]-'a';
		if (mt[c]!=-1&&mt[c]!=i) continue;
		bool tmp = 0;
		if (mt[c]==-1)
		{
			if (hs[i]) continue;
			tmp = 1;
			mt[c] = i;
			hs[i] = 1;
		}
		dfs(x+1, fa&('a'+i==a[x]), fb&('a'+i==b[x]));
		if (tmp)
		{
			mt[c] = -1;
			hs[i] = 0;
		}
	}
}
void solve()
{
	scanf("%d", &k);
	scanf("%s", s);
	scanf("%s", a);
	scanf("%s", b);
	n = strlen(s);
	memset(mt, -1, sizeof(mt));
	memset(hs, 0, sizeof(hs));
	OK = 0;
	dfs(0, 1, 1);
	if (!OK) puts("NO");
}
int main()
{
	int Tn;
	scanf("%d", &Tn);
	while (Tn--)
	{
		solve();
	}
	return 0;
}