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
int n;
struct basis
{
	int a[5][5];
	void input()
	{
		memset(a, 0, sizeof(a));
		int k;
		geti(k);
		for (int i=0; i<k; i++)
		{
			for (int j=0; j<n; j++)
			{
				geti(a[i][j]);
				a[i][j] = (a[i][j]+mod)%mod;
				assert(a[i][j]>=0);
			}
		}
		for (int i=0; i<n; i++)
		{
			int pivot = -1;
			for (int j=0; j<n; j++)
			{
				bool ok = a[j][i]>0;
				for (int k=0; k<i; k++) ok &= a[j][k]==0;
				if (ok) pivot = j;
			}
			if (pivot==-1) continue;
			swap(a[pivot], a[i]);
			ll inv = qpow(a[i][i], mod-2);
			for (int j=0; j<n; j++) a[i][j] = 1ll*a[i][j]*inv%mod;
			for (int j=0; j<n; j++)
			{
				if (i==j) continue;
				ll coef = (mod-a[j][i])%mod;
				for (int k=i; k<n; k++)
				{
					a[j][k] = (a[j][k]+1ll*coef*a[i][k])%mod;
				}
			}
		}
		/*
		cerr<<endl;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				cerr<<a[i][j]<<" ";
			}
			cerr<<endl;
		}
		*/
	}
	bool operator < (const basis &t) const
	{
		for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (a[i][j]!=t.a[i][j]) return a[i][j]<t.a[i][j];
		return false;
	}
};
map<basis, int> mp;
int tot;
int main()
{
	int M;
	getii(M, n);
	for (int i=1; i<=M; i++)
	{
		basis x;
		x.input();
		int &id = mp[x];
		if (id==0) id = ++tot;
		printf("%d ", id);
	}
	return 0;
}