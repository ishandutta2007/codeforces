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

const int mod = 998244353;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n, m;
ll a[66], coef = 1;
ll A[20][1<<17], B[1<<17], C[1<<17];
void dfs(int x, ll msk)
{
	if (x>=m)
	{
		A[__builtin_popcountll(msk>>17)][msk&((1<<17)-1)]++;
	}
	else
	{
		dfs(x+1, msk);
		if (a[x]) dfs(x+1, msk^a[x]);
	}
}
void dfs2(int x, ll msk)
{
	if (x>=m||x>=17)
	{
		B[msk]++;
	}
	else
	{
		dfs2(x+1, msk);
		if (a[x]) dfs2(x+1, msk^a[x]);
	}
}
void FWT(ll a[],int n,int coef)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			if(!((j>>i)&1))
			{
				ll tmp=a[j+(1<<i)];
				a[j+(1<<i)]=(a[j]-a[j+(1<<i)]+mod)%mod;
				a[j]=(a[j]+tmp)%mod;
			}
		}
	}
	ll inv=qpow(1<<n,mod-2);
	if(coef==-1)for(int i=0;i<(1<<n);i++)a[i]=a[i]*inv%mod;
}
ll ans[66];
int main()
{
	getii(n, m);
	for (int i=1; i<=n; i++)
	{
		ll x;
		geti(x);
		bool f = false;
		for (int j=m-1; j>=0; j--)
		{
			if ((x>>j)&1)
			{
				if (a[j]) x ^= a[j];
				else
				{
					a[j] = x;
					f = true;
					break;
				}
			}
		}
		if (!f)
		{
			coef = coef*2%mod;
		}
	}
	dfs(17, 0);
	dfs2(0, 0);
	FWT(B, 17, 1);
	for (int i=0; i<20; i++)
	{
		FWT(A[i], 17, 1);
		for (int j=0; j<(1<<17); j++) C[j] = 1ll*A[i][j]*B[j]%mod;
		FWT(C, 17, -1);
		for (int j=0; j<(1<<17); j++) ans[__builtin_popcount(j)+i] += C[j];
	}
	for (int i=0; i<=m; i++)
	{
		ans[i] = (ans[i]%mod+mod)%mod;
		ans[i] = 1ll*ans[i]*coef%mod;
		cout<<ans[i]<<" ";
	}
	return 0;
}

/*
const int mod = 1e9+7;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 100111;
int n;
ll inv[maxn], fac[maxn], ifac[maxn];
ll C(int x, int y) {return fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
int main()
{
	inv[1] = 1;
	for (int i=2; i<maxn; i++) inv[i] = mod-(mod/i)*inv[mod%i]%mod;
	fac[0] = 1;
	for (int i=1; i<maxn; i++) fac[i] = fac[i-1]*i%mod;
	ifac[0] = 1;
	for (int i=1; i<maxn; i++) ifac[i] = ifac[i-1]*inv[i]%mod;
	
	return 0;
}
*/