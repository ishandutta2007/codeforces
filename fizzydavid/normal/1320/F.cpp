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
int n, m, k;
const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
int getid(int x, int y, int z)
{
	assert(x>=0&&x<n&&y>=0&&y<m&&z>=0&&z<k);
	return x*m*k+y*k+z;
}
const int maxn = 200111;
int a[maxn];
vector<int> d[maxn];
void fail()
{
	puts("-1");
	exit(0);
}
bool in_range(int x, int y, int z) {return x>=0&&x<n&&y>=0&&y<m&&z>=0&&z<k;}
void del(int x, int y, int z);
void add1(int op, int x, int y, int z, int c);
void add(int op, int x, int y, int z, int c)
{
	if (!in_range(x, y, z))
	{
		if (c!=0) fail();
		return;
	}
//	cerr<<op<<" "<<x<<" "<<y<<" "<<z<<" "<<c<<" "<<a[getid(x, y, z)]<<endl;
	if (c==0)
	{
		int id = getid(x, y, z);
		if (a[id]>0) del(x, y, z);
		a[id] = 0;
		add1(op, x, y, z, c);
	}
	else
	{
		int id = getid(x, y, z);
		if (a[id]==0)
		{
			add1(op, x, y, z, c);
		}
		else if (a[id]>0&&a[id]!=c)
		{
			del(x, y, z);
			add1(op, x, y, z, c);
		}
		else
		{
			a[id] = c;
			d[id].PB(op);
		}
	}
}
void add1(int op, int x, int y, int z, int c)
{
	add(op, x+dx[op], y+dy[op], z+dz[op], c);
}
void del(int x, int y, int z)
{
	int id = getid(x, y, z);
	assert(a[id]>0);
	int c = a[id];
	a[id] = 0;
	for (auto t : d[id])
	{
		add1(t, x, y, z, c);
	}
}

int main()
{
	getiii(n, m, k);
	memset(a, -1, sizeof(a));
	for (int i=0; i<m; i++) for (int j=0; j<k; j++)
	{
		int x;
		geti(x);
		add(0,  0, i, j, x);
	}
	for (int i=0; i<m; i++) for (int j=0; j<k; j++)
	{
		int x;
		geti(x);
		add(1,  n-1, i, j, x);
	}
	for (int i=0; i<n; i++) for (int j=0; j<k; j++)
	{
		int x;
		geti(x);
		add(2,  i, 0, j, x);
	}
	for (int i=0; i<n; i++) for (int j=0; j<k; j++)
	{
		int x;
		geti(x);
		add(3,  i, m-1, j, x);
	}
	for (int i=0; i<n; i++) for (int j=0; j<m; j++)
	{
		int x;
		geti(x);
		add(4,  i, j, 0, x);
	}
	for (int i=0; i<n; i++) for (int j=0; j<m; j++)
	{
		int x;
		geti(x);
		add(5,  i, j, k-1, x);
	}
	for (int i=0; i<n*m*k; i++)
	{
		if (a[i]==-1) a[i] = 0;
		printf("%d ", a[i]);
	}
	return 0;
}