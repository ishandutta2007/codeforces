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

void manacher(char s[], int n, int len[])
{
	pair<int,int> p = MP(0, 0);
	for (int i=1; i<=n; i++)
	{
		int h = 0;
		if (i<=p.SS)
		{
			h = min(p.SS-i, len[p.SS+p.FF-i]);
		}
		while (i+h+1<=n&&i-h-1>=1&&s[i+h+1]==s[i-h-1]) h++;
		len[i] = h;
		if (i+h>p.SS) p = MP(i-h, i+h);
	}
}
const int maxn = 2000111;
int Tn, n;
char _s[maxn], s[maxn];
int len[maxn];
int main()
{
	scanf("%d", &Tn);
	while (Tn--)
	{
		scanf("%s", _s+1);
		n = strlen(_s+1);
		for (int i=1; i<=2*n+1; i++) s[i] = '*';
		for (int i=1; i<=n; i++)
		{
			s[i+i] = _s[i];
		}
		manacher(s, n+n+1, len);
		int L = 0, mx = 0, mxl, mxr, mxt;
		while (L<n&&_s[L+1]==_s[n-L]) L++;
//		for (int i=1; i<=n*2+1; i++) putchar(s[i]); puts("");
//		for (int i=1; i<=n*2+1; i++) cerr<<len[i]<<" "; cerr<<endl;
		for (int i=1; i<=n*2+1; i++)
		{
			int l = (i-len[i])/2+1, r = (i+len[i])/2;
			if (l<=L+1||r>=n-L)
			{
				int t = min(l-1, n-r);
				if (len[i]+t*2>mx)
				{
					mx = len[i]+t*2;
					mxl = l, mxr = r, mxt = t;
				}
			}
		}
//		cerr<<mxl<<" "<<mxr<<" "<<mxt<<endl;
		for (int i=1; i<=n; i++)
		{
			if (i<=mxt||i>=n-mxt+1||i>=mxl&&i<=mxr) putchar(_s[i]);
		}
		puts("");
	}
	return 0;
}