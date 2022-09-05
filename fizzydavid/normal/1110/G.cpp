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
const int maxn = 500111;
int Tn, n;
vector<int> con[maxn];
bool f[maxn];
void adde(int x, int y)
{
	con[x].PB(y);
}
void dele(int x, int y)
{
	for (int i=0; i<con[x].size(); i++)
	{
		if (con[x][i]==y)
		{
			con[x].erase(con[x].begin()+i);
			break;
		}
	}
}
vector<int> v;
void dfs(int x, int pre)
{
	v.PB(f[x]);
	for (auto u : con[x])
	{
		if (u==pre) continue;
		dfs(u, x);
	}
}
int main()
{
	geti(Tn);
	while (Tn--)
	{
		geti(n);
		for (int i=1; i<=n; i++) con[i].clear();
		for (int i=1; i<n; i++)
		{
			int x, y;
			getii(x, y);
			adde(x, y);
			adde(y, x);
		}
		for (int i=1; i<=n; i++) f[i] = getreal()=='W';
		bool OK = 0;
		for (int i=1; i<=n; i++)
		{
			if (con[i].size()>=4)
			{
				OK = 1;
				break;
			}
		}
		if (!OK)
		{
			for (int i=1; i<=n&&!OK; i++)
			{
				if (con[i].size()==3)
				{
					int cnt_leaf = 0;
					for (auto u : con[i])
					{
						if (con[u].size()==1)
						{
							cnt_leaf++;
							if (f[u]) OK = 1;
						}
					}
					if (cnt_leaf<=1)
					{
						OK = 1;
						break;
					}
					int x = -1, y = -1;
					for (auto u : con[i])
					{
						if (con[u].size()==1)
						{
							if (x==-1) x = u; else y = u;
						}
					}
					dele(y, i);
					dele(i, y);
					f[x] = 1;
				}
			}
		}
		if (!OK)
		{
			for (int i=1; i<=n; i++)
			{
				if (con[i].size()==1)
				{
					v.clear();
					dfs(i, -1);
					if (v.size()==3)
					{
						OK |= v[0]+v[1]+v[2]>=2;
					}
					else if (v.size()>=4)
					{
						for (int j = 1; j+1<v.size(); j++)
						{
							if (v[j]) OK = 1;
						}
						if (v[0]&&v.back()&&v.size()%2==1) OK = 1;
					}
				}
			}
		}
		if (OK) puts("White"); else puts("Draw");
	}
	return 0;
}