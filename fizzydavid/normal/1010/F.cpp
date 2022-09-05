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

const int mod=998244353;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int proot=3;
const int FFTbitn=18;
const int FFTpmx=1<<FFTbitn;
const int FFTmx=FFTpmx+233;
int w_pre[FFTmx],fsz;
void FFTprecalc()
{
	w_pre[0]=1;
	int ww=qpow(proot,(mod-1)/FFTpmx);
	for(int i=1;i<=FFTpmx;i++)w_pre[i]=1ll*w_pre[i-1]*ww%mod;
}
void FFTinit(int sz){fsz=1;while(fsz<sz)fsz<<=1;assert(fsz<=FFTpmx);}
void FFT(int a[],int coef)
{
	typedef unsigned long long ull;
	static ull f_a[FFTmx];
	static int w[FFTmx];
	for(int i=0,j=0;i<fsz;i++)
	{
		f_a[j]=a[i]<0?a[i]+mod:a[i];
		for(int l=fsz>>1;(j^=l)<l;l>>=1);
	}
	const ull md2=1ull*mod*mod;
	for(int l=1;l<fsz;l<<=1)
	{
		int l2=l<<1,u=FFTpmx/l2;
		if(coef==1)for(int j=0,j2=0;j<l;j++,j2+=u)w[j]=w_pre[j2];
		else for(int j=0,j2=FFTpmx;j<l;j++,j2-=u)w[j]=w_pre[j2];
		for(int i=0;i<fsz;i+=l2)
		{
			for(int j=0;j<l;j++)
			{
				ull tmp=f_a[i+j+l]%mod*w[j];
				f_a[i+j+l]=f_a[i+j]+md2-tmp;
				f_a[i+j]+=tmp;
			}
		}
		if(l==(1<<16))for(int j=0;j<fsz;j++)f_a[j]%=mod;
	}
	for(int i=0;i<fsz;i++)a[i]=f_a[i]%mod;
	if(coef==-1)
	{
		int inv=qpow(fsz,mod-2);
		for(int i=0;i<fsz;i++)a[i]=1ll*a[i]*inv%mod;
	}
}
void polymul(int a[],int an,int b[],int bn,int c[],int cn=-1)
{
	static int mul_a[FFTmx],mul_b[FFTmx];
	if(cn==-1)cn=an+bn;
	an=min(an,cn);bn=min(bn,cn);
	if(1ll*an*bn<=4096)
	{
		for(int i=0;i<an+bn;i++)mul_a[i]=0;
		for(int i=0;i<an;i++)
			for(int j=0;j<bn;j++)
				mul_a[i+j]=(mul_a[i+j]+1ll*a[i]*b[j])%mod;
		for(int i=0;i<cn;i++)c[i]=mul_a[i];
		return;
	}
	FFTinit(an+bn);
	for(int i=0;i<fsz;i++)mul_a[i]=i<an?a[i]:0;
	for(int i=0;i<fsz;i++)mul_b[i]=i<bn?b[i]:0;
	FFT(mul_a,1);
	FFT(mul_b,1);
	for(int i=0;i<fsz;i++)mul_a[i]=1ll*mul_a[i]*mul_b[i]%mod;
	FFT(mul_a,-1);
	for(int i=0;i<cn;i++)c[i]=mul_a[i];
}
vector<int> polymul(const vector<int> &a,const vector<int> &b)
{
	vector<int> ret;
	if(!a.size()||!b.size())return ret;
	static int A[FFTmx],B[FFTmx];
	for(int i=0;i<a.size();i++)A[i]=a[i];
	for(int i=0;i<b.size();i++)B[i]=b[i];
	polymul(A,a.size(),B,b.size(),A);
	for(int i=0;i<a.size()+b.size()-1;i++)ret.PB(A[i]);
	return ret;
}
vector<int> polyadd(const vector<int> &v1,const vector<int> &v2)
{
	vector<int> ret;
	for(int i=0;i<max(v1.size(),v2.size());i++)ret.PB(((i<v1.size()?v1[i]:0)+(i<v2.size()?v2[i]:0))%mod);
	return ret;
}

const int maxn=100111;

int n;
vector<int> con0[maxn],con[maxn];
int sz[maxn],top[maxn],csz[maxn];
vector<int> F[maxn],G[maxn];
bool cmp_with_size(int x,int y){return sz[x]>sz[y];}
void dfs(int x,int pre=-1)
{
	sz[x]=1;
	for(int i=0;i<con0[x].size();i++)
	{
		int u=con0[x][i];
		if(u==pre)continue;
		dfs(u,x);
		sz[x]+=sz[u];
		con[x].PB(u);
	}
	sort(con[x].begin(),con[x].end(),cmp_with_size);
	csz[x]=sz[x];
	if(con[x].size()>0)csz[x]-=sz[con[x][0]];
}
typedef pair<vector<int>,vector<int> > PVV;
PVV solve(const vector<int> &v)
{
	vector<int> retK,retB;
	if(v.size()==1)
	{
		retB.resize(csz[v[0]]+1);
		retB[csz[v[0]]]=1;
//		cerr<<"solve:"<<endl;for(int i=0;i<v.size();i++)cerr<<v[i]<<" ";cerr<<endl;
//		cerr<<"retK=";for(auto r:G[v[0]])cerr<<r<<" ";cerr<<endl;
//		cerr<<"retB=";for(auto r:retB)cerr<<r<<" ";cerr<<endl;
		return MP(G[v[0]],retB);
	}
	int alls=0;
	for(int i=0;i<v.size();i++)alls+=csz[v[i]];
	int m=0,curs=csz[v[0]];
	while(m+2<v.size()&&curs*2<=alls)curs+=csz[v[++m]];
	vector<int> v0,v1;
	for(int i=0;i<v.size();i++)if(i<=m)v0.PB(v[i]);else v1.PB(v[i]);
	PVV L=solve(v0),R=solve(v1);
	
	vector<int> tmp;tmp.resize(curs);
	for(int i=0;i<R.SS.size();i++)tmp.PB(R.SS[i]);
	tmp.swap(R.SS);
	
	retK=polymul(L.FF,R.FF);
	retB=polyadd(polymul(R.FF,L.SS),R.SS);
//	cerr<<"solve:"<<endl;for(int i=0;i<v.size();i++)cerr<<v[i]<<" ";cerr<<endl;
//	cerr<<"retK=";for(auto r:retK)cerr<<r<<" ";cerr<<endl;
//	cerr<<"retB=";for(auto r:retB)cerr<<r<<" ";cerr<<endl;
	
	return MP(retK,retB);
}
void dfs2(int x,int tp)
{
//	cerr<<"dfs:"<<x<<" "<<tp<<endl;
	G[x].clear();
	G[x].PB(1);
	for(int i=1;i<con[x].size();i++)
	{
		int u=con[x][i];
		dfs2(u,u);
		G[x]=polymul(G[x],F[u]);
	}
	if(con[x].size()>0)dfs2(con[x][0],tp);
	if(x==tp)
	{
		vector<int> v;
		int p=x;
		while(true)
		{
			v.PB(p);
			if(con[p].size()==0)break;
			p=con[p][0];
		}
		reverse(v.begin(),v.end());
		PVV pp=solve(v);
		F[x]=polyadd(pp.FF,pp.SS);
//		cerr<<"---F "<<x<<endl;
//		for(int i=0;i<F[x].size();i++)cerr<<F[x][i]<<" ";cerr<<endl;
	}
}

int main()
{
	FFTprecalc();
	ll K;
	getii(n,K);K%=mod;
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con0[x].PB(y);
		con0[y].PB(x);
	}
	dfs(1);
	dfs2(1,1);
	vector<int> v=F[1];
//	for(int i=0;i<v.size();i++)cerr<<v[i]<<" ";cerr<<endl;
	assert(v.size()>=n);
	ll cur=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=cur*v[n-i]%mod;
		cur=cur*(K+i)%mod;
		cur=cur*qpow(i,mod-2)%mod;
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}