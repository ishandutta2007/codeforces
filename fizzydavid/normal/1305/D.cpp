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
#define kill orzdjq
const int mod = 1e9+7;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 1011;
int n;
bool kill[maxn];
vector<int> con[maxn];
int query(int x, int y)
{
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	if (ret==-1) exit(0);
	return ret;
}
void dfs(int x, int pre)
{
	kill[x] = true;
	for (auto u : con[x])
	{
		if (u!=pre)
		{
			dfs(u, x);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		con[x].PB(y);
		con[y].PB(x);
	}

	while (true)
	{
		vector<int> v;
		for (int i=1; i<=n; i++)
		{
			if (!kill[i])
			{
				v.PB(i);
			}
		}
		if (v.size()==1)
		{
			printf("! %d\n", v[0]);
			fflush(stdout);
			exit(0);
		}
		else if (v.size()==2)
		{
			int ans = query(v[0], v[1]);
			printf("! %d\n", ans);
			fflush(stdout);
			exit(0);
		}
		else
		{
			for (auto x : v)
			{
				vector<int> nb;
				for (auto y : con[x])
				{
					if (!kill[y])
					{
						nb.PB(y);
					}
				}
				if (nb.size()>=2)
				{
					int c = query(nb[0], nb[1]);
					if (c!=x) dfs(x, c);
					else dfs(nb[0], x), dfs(nb[1], x);
					break;
				}
			}
		}
	}
	return 0;
}