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
struct tester
{
	vector<int> con[1011];
	int n;
	void gen(int N)
	{
		n = N;
		for (int i=1; i<n; i++)
		{
			int x = rand()%i+1, y = i+1;
			cerr<<x<<"-"<<y<<endl;
			con[x].PB(y);
			con[y].PB(x);
		}
	}
	bool f[1011];
	void dfs(int x, int d, int pre)
	{
		for (auto u : con[x])
		{
			if (u==pre) continue;
			if (d>0) f[u] = true, dfs(u, d-1, x); 
		}
	}
	void query(int a[], bitset<1011> &ret)
	{
		memset(f, 0, sizeof(f));
		for (int i=0; i<n; i++) dfs(i+1, a[i], -1);
		for (int i=0; i<n; i++) ret[i] = f[i+1];
	}
	void check(set<pair<int,int> > E)
	{
		for (auto e : E)
		{
			bool ok = false;
			for (auto y : con[e.FF+1])
			{
				ok |= y==e.SS+1;
			}
			assert(ok);
		}
	}
}T;

int n, K, a[1011];
bitset<1011> adj[1011], cur;
int dis[1011];
set<pair<int,int> > E;
void query()
{
#ifdef CHK
	T.query(a, cur);
#else
	printf("?");
	for (int i=0; i<n; i++) printf(" %d", a[i]);
	puts("");
	fflush(stdout);
	static char s[1011];
	scanf("%s", s);
	for (int i=0; i<n; i++) cur[i] = s[i]=='1';
#endif
}
void get_adj(vector<int> v)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++) adj[i][j] = 1;
	}
	for (int t=K; t>=0; t--)
	{
		memset(a, 0, sizeof(a));
		for (int i=0; i<v.size(); i++) a[v[i]] = (i>>t)&1;
		query();
		for (int i=0; i<v.size(); i++) if ((i>>t)&1) adj[v[i]] &= cur; else adj[v[i]] &= ~cur; 
	}
	for (auto i : v)
	{
		for (int j=0; j<n; j++)
		{
			if (adj[i][j]&&dis[j]==dis[i]+1)
			{
				E.insert(MP(min(i, j), max(i, j)));
			}
		}
	}
}
int main()
{
	srand(time(0));
#ifdef CHK
	n = 1000;
	T.gen(n);
#else
	scanf("%d", &n);
#endif
	while ((1<<K+1)<n) K++;
	int t = K;
	while (t>=0)
	{
		a[0] = 1<<t;
		query();
		bool ok = false;
		for (int i=1; i<n; i++)
		{
			dis[i] = cur[i]==0;
			ok |= dis[i];
		}
		if (ok) break;
		t--;
	}
	if (t<0)
	{
		for (int i=1; i<n; i++) E.insert(MP(0, i));
	}
	else
	{
		while (t>0)
		{
			t--;
			cerr<<"t="<<t<<endl;
			static int ndis[1011];
			a[0] = 0;
			for (int i=1; i<n; i++) if (dis[i]%3==0) a[i] = 1<<t; else a[i] = 0;
			query();
			for (int i=1; i<n; i++) if (dis[i]%3==1) ndis[i] = dis[i]*2+1-cur[i];
			
			for (int i=1; i<n; i++) if (dis[i]%3==1) a[i] = 1<<t; else a[i] = 0;
			query();
			for (int i=1; i<n; i++) if (dis[i]%3==2) ndis[i] = dis[i]*2+1-cur[i];
			
			a[0] = 1<<t;
			for (int i=1; i<n; i++) if (dis[i]%3==2) a[i] = 1<<t; else a[i] = 0;
			query();
			for (int i=1; i<n; i++) if (dis[i]%3==0) ndis[i] = dis[i]*2+1-cur[i];
			
			swap(dis, ndis);
		}
		vector<int> v;
		v.clear();
		for (int i=1; i<n; i++) if (dis[i]%4<2) v.PB(i);
		get_adj(v);
		v.clear();
		for (int i=1; i<n; i++) if (dis[i]%4>=2) v.PB(i);
		get_adj(v);
		for (int i=1; i<n; i++) if (dis[i]==0) E.insert(MP(0, i));
	}
	assert(E.size()==n-1);
	puts("!");
	for (auto e : E) printf("%d %d\n", e.FF+1, e.SS+1);
	fflush(stdout);
#ifdef CHK
	T.check(E);
#endif
	return 0;
}