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
int n;
int b[111], c[111], a[111], A[111], op[111];
vector<int> v[111];
pair<int,int> calc(int x[], int n)
{
	int B=0, C=0;
	for (int j=1; j<=n; j++)
	{
		B += x[j]*(x[j]-1)*(x[j]-2)/6;
		if (j+2<=n) C += x[j]*x[j+1]*x[j+2];
	}
	return MP(B, C);		
}
bool check(int A[], int m)
{
	if (m==n)
	{
		int x[111];
		for (int j=1; j<=n; j++) x[j] = A[j];
		for (int i=0; i<=n; i++)
		{
			auto p = calc(x, n);
			if (p.FF!=b[i]||p.SS!=c[i]) return false;
			x[op[i+1]]++;
		}
	}
	else
	{
		int x[111];
		for (int j=1; j<=m; j++) x[j] = A[j];
		auto pre = calc(x, m);
		for (int i=1; i<=n; i++)
		{
			x[op[i]]++;
			auto cur = calc(x, m);
			if (op[i]>=1&&op[i]<=m-2)
			{
				if (cur.FF-pre.FF!=b[i]-b[i-1]||cur.SS-pre.SS!=c[i]-c[i-1]) return false;
			}
			pre = cur;
		}
	}
	return true;
}

void dfs(int x)
{
	if (!check(A, x-1)) return;
	if (x==n+1)
	{
		putchar('!');
		for (int i=1; i<=n; i++) printf(" %d", A[i]);
		puts("");
		fflush(stdout);
		exit(0);
	}
	for (auto u : v[x])
	{
		A[x] = u;
		dfs(x+1);
	}
}
int main()
{
	scanf("%d", &n);
	scanf("%d%d", &b[0], &c[0]);
	for (int i=1; i<=n; i++)
	{
		op[i] = i<n?i:1;
		printf("+ %d\n", op[i]);
		fflush(stdout);
		scanf("%d%d", &b[i], &c[i]);
	}
	for (int i=1; i<n; i++)
	{
		if (b[i]>b[i-1])
		{
			for (int j=2; j<=n; j++)
			{
				if (((j+1)*j*(j-1)-j*(j-1)*(j-2))/6==b[i]-b[i-1])
				{
					v[i].PB(j);
					break;
				}
			}
		}
		else
		{
			v[i].PB(0);
			v[i].PB(1);
		}
	}
	for (int i=0; i<=n; i++) v[n].PB(i);
	dfs(1);
	return 0;
}