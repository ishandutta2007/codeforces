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
int g[10], gn;
void query(vector<int> v)
{
	printf("next");
	for (auto x : v) printf(" %d", x);
	puts("");
	fflush(stdout);
	int K;
	scanf("%d", &K); gn = K;
	for (int i=0; i<K; i++)
	{
		char s[10];
		scanf("%s", s);
		for (int j=0; j<strlen(s); j++)
		{
			g[s[j]-'0'] = i;
		}
	}
}
vector<int> group(int x)
{
	vector<int> ret;
	for (int i=0; i<10; i++) if (g[i]==g[x]) ret.PB(i);
	return ret;
}
int main()
{
	while (true)
	{
		query({0});
		query({0, 1});
		if (gn==2) break;
	}
	/*
	vector<int> v2 = {2};
	for (int i=0; i<c; i++)
	{
		vector<int> v = v2;
		bool ok = false;
		for (auto x : v) ok |= x==0;
		if (!ok&&i<c/2) v.PB(0);
		query(v);
		v2 = group(2);
		if (i<c/2&&g[0]==g[1]) break;
	}
	*/
	while (true)
	{
		vector<int> v;
		for (int i=0; i<10; i++) v.PB(i);
		query(v);
		if (gn==1)
		{
			puts("done");
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}