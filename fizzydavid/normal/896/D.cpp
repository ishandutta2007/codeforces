//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
int mod;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
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
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}

ll qpow(ll x,ll k,ll md){return k==0?1:qpow(x*x%md,k>>1,md)*(k&1?x:1)%md;}
struct Combinactorial
{
	//Init: O(sqrt(mod)+nlog(mod))  Query: O(log(mod))
	static const int comb_mxn=200111;
	int mod,phi_mod;
	int pn,pr[20],ppw[20][comb_mxn];
	int fac[comb_mxn],pcnt[comb_mxn][20];
	void initmod(int x)
	{
		mod=x;
		pn=0;
		phi_mod=x;
		for(int i=2;i<=x;)
		{
			i=x/(x/i);
			if(x%i==0)
			{
				phi_mod=phi_mod/i*(i-1);
				while(x%i==0)
				{
					x/=i;
				}
				pr[pn]=i;
				ppw[pn][0]=1;
				for(int j=1;j<comb_mxn;j++)ppw[pn][j]=1ll*ppw[pn][j-1]*i%mod;
				pn++;
			}
			i++;
		}
		fac[0]=1;
		for(int i=1;i<comb_mxn;i++)
		{
			x=i;
			for(int j=0;j<pn;j++)
			{
				pcnt[i][j]=pcnt[i-1][j];
				while(x%pr[j]==0)x/=pr[j],pcnt[i][j]++;
			}
			fac[i]=1ll*fac[i-1]*x%mod;
		}
	}
	int C(int x,int y)
	{
		if(x<y)return 0;
		int ret=1ll*fac[x]*qpow(1ll*fac[y]*fac[x-y]%mod,phi_mod-1,mod)%mod;
		for(int i=0;i<pn;i++)ret=1ll*ret*ppw[i][pcnt[x][i]-pcnt[y][i]-pcnt[x-y][i]]%mod;
		return ret;
	}
}cmb;

int n;
ll solve(ll l)
{
	ll ret=0;
	for(int i=0;i<=n;i++)
	{
		if((i+l)%2==0)
		{
			int x=(i+l)/2;
			ret+=1ll*cmb.C(i,x)*cmb.C(n,i)%mod;
		}
	}
	return ret%mod;
}
int main()
{
	int l,r;
	cin>>n>>mod>>l>>r;
	cmb.initmod(mod);
	ll ans;
	if(l==r)
	{
		ans=solve(l);
		ans-=solve(l+2);
	}
	else
	{
		ans=solve(l)+solve(l+1);
		ans-=solve(r+1)+solve(r+2);
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}