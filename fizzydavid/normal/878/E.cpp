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
const int mod=1e9+7;
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
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
ll pw2[100111];
const ll lmx=1e18;
ll mnprod(ll x,ll y){return 1.0*x*y>lmx?lmx:x*y;}
struct number
{
	ll x,r;
	int cnt;
	number(ll X=0,ll R=0,int Cnt=0){x=X;r=R;cnt=Cnt;}
	number operator*(const number &t)
	{
		return number((pw2[cnt+1]*t.x+x)%mod,min(mnprod(1ll<<min(cnt+1,60),t.r)+r,lmx),cnt+t.cnt+1);
	}
};
int tol[100111];
number tolv[100111];
ll a[100111],sum[100111],ans[100111],suf[100111];
int n,m;
vector<pair<int,int> > que[100111];
pair<int,ll> getp(int x,int k)
{
	if(tol[x]<k)return MP(x,0);
	else
	{
		pair<int,ll> ret=getp(tol[x],k);
		sum[x]=(sum[x]+ret.SS)%mod;
		tol[x]=ret.FF;
		return MP(tol[x],sum[x]);
	}
}
int main()
{
	pw2[0]=1;
	for(int i=1;i<100005;i++)pw2[i]=(pw2[i-1]+pw2[i-1])%mod;
	getii(n,m);
	for(int i=1;i<=n;i++)geti(a[i]);
	for(int i=n;i>=1;i--)suf[i]=(suf[i+1]*2+a[i])%mod;
	for(int i=1;i<=m;i++)
	{
		int l,r;
		getii(l,r);
		que[l].PB(MP(r,i));
	}
	for(int i=1;i<=n;i++)
	{
		tol[i]=i-1;
		tolv[i]=number(a[i]%mod,a[i],0);
		while(tol[i]&&tolv[i].r>=0)
		{
			tolv[i]=tolv[tol[i]]*tolv[i];
			tol[i]=tol[tol[i]];
		}
		sum[i]=tolv[i].x;
	}
//	for(int i=1;i<=n;i++)cerr<<tol[i]<<" "<<tolv[i].x<<","<<tolv[i].r<<","<<tolv[i].cnt<<endl;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<que[i].size();j++)
		{
			int x=que[i][j].FF;
			pair<int,ll> p=getp(x,i);
			ans[que[i][j].SS]=((p.SS*2+suf[i]-suf[p.FF+1]*pw2[p.FF+1-i])%mod+mod)%mod;
		}
	}
	for(int i=1;i<=m;i++)putsi(ans[i]);
	return 0;
}