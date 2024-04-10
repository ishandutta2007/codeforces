#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
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
int Tn, n;
int f[100111];
int pre[100111];
vector<vector<int> > P;
vector<int> getlis(vector<int> v)
{
	vector<pair<int,int> > st;
	P.clear();
	for (int i=0; i<v.size(); i++)
	{
		int it = lower_bound(st.begin(), st.end(), MP(v[i], 0))-st.begin();
		if (it==st.size())
		{
			st.PB(MP(v[i], i)), P.PB(vector<int>());
			P.back().PB(v[i]);
		}
		else
		{
			st[it]=MP(v[i], i);
			P[it].PB(v[i]);
		}
		if (it==0) pre[i] = -1;
		else pre[i] = st[--it].SS;
	}
	int p = st.back().SS;
	vector<int> ret;
	while (p!=-1)
	{
		ret.PB(p);
		p = pre[p];
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int main()
{
	for (int i=1, j=1; i<=100000; j++, i+=j)
	{
		for (int t=i; t<=i+j&&t<=100000; t++) f[t] = j;
	}
	geti(Tn);
	while (Tn--)
	{
		geti(n);
		int x;
		vector<int> v;
		for (int i=0; i<n; i++)
		{
			geti(x);
			v.PB(x);
		}
		vector<vector<int> > G;
		while (v.size()>0)
		{
			vector<int> nv;
			vector<bool> used;
			used.resize(v.size());
			vector<int> v0 = getlis(v);
			vector<int> V;
			if (v0.size()>f[v.size()])
			{
				for (auto x:v0) V.PB(v[x]), used[x]=1;
				G.PB(V);
				for (int i=0; i<v.size(); i++) if(!used[i]) nv.PB(v[i]);
				v.swap(nv);
			}
			else
			{
				for (int i=0; i<P.size(); i++)
				{
					G.PB(P[i]);
				}
				break;
			}
		}
		putsi(G.size());
		for (int i=0; i<G.size(); i++)
		{
			puti(G[i].size());
			for (auto x:G[i]) puti(x);
			puts("");
		}
	}
	return 0;
}