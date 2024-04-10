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
//ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
ll qmul(ll x,ll y,ll md)
{
	x=(x%md+md);y=(y%md+md);
	ll t=x*y-ll((long double)1.0*x/md*y+0.5)*md;
	return (t%md+md)%md;
}
ll qpow(ll x,ll k,ll md){return k==0?1:qmul(qpow(qmul(x,x,md),k>>1,md),k&1?x:1,md);}
namespace F
{
	bool miller_rabin(ll x,ll p,ll N,ll a)//N=x*2^p
	{
		ll bs=qpow(a,x,N);
		if(bs==1)return true;
		for(int i=0;i<p;i++)
		{
			if(bs==N-1)return true;
			bs=qmul(bs,bs,N);
		}
		return false;
	}
	bool is_prime(ll N)
	{
		if(N==2)return true;
		if(N%2==0||N==1||N==0)return false;
		ll tmp=N-1,p=0;
		while(tmp%2==0)tmp/=2,p++;
		for(int _t=0;_t<16;_t++)if(!miller_rabin(tmp,p,N,rand()%(N-1)+1))return false;
		return true;
	}
	ll get_fac(ll a,ll b,ll N)
	{
		ll x=a;
		for(int l=1;;l<<=1)
		{
			ll nx=x;
			for(int j=0;j<l;j++)
			{
				nx=(qmul(nx,nx,N)+b)%N;
				ll g=__gcd(abs(x-nx),N);
				if(g!=1)return g;
			}
			x=nx;
		}
	}
	vector<ll> get_facs(ll N)
	{
		vector<ll> ret;
		if(N==1)return ret;
		if(is_prime(N))ret.PB(N);
		else
		{
			ll p;
			while((p=get_fac(rand()%N,rand()%N,N))==N);
			ret=get_facs(p);
			vector<ll> ret2=get_facs(N/p);
			for(int i=0;i<ret2.size();i++)ret.PB(ret2[i]);
		}
		return ret;
	}
	vector<ll> get_pfacs(ll N)
	{
		vector<ll> v=get_facs(N);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		return v;
	}
};
int q;
map<ll,vector<pair<ll,int> > > qr;
bool ANS[10011];
ll dis[100111];
set<pair<ll,int> > st;
bool vis[100111];
void solve(ll K,vector<pair<ll,int> > v)
{
	vector<ll> pr=F::get_pfacs(K);
//	cerr<<"solve:"<<K<<endl;
//	for(int i=0;i<pr.size();i++)cerr<<pr[i]<<" ";cerr<<endl;
	ll M;
	if(pr.size()>=3)
	{
		M=pr[0];
		memset(dis,31,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[0]=0;
		st.clear();
		st.insert(MP(0,0));
		while(st.size()>0)
		{
			int x=st.begin()->SS;
			st.erase(st.begin());
			if(vis[x])continue;
			vis[x]=0;
			for(int i=1;i<pr.size();i++)
			{
				int u=(x+pr[i])%M;
				ll w=min(ll(4e18),dis[x]+pr[i]);
				if(w<dis[u])
				{
					dis[u]=w;
					st.insert(MP(w,u));
				}
			}
		}
//		for(int i=0;i<M;i++)cerr<<dis[i]<<" ";cerr<<endl;
	}
	for(int i=0;i<v.size();i++)
	{
		ll x=v[i].FF,id=v[i].SS;
		bool &ans=ANS[id];
		if(pr.size()==0)ans=false;
		else if(pr.size()==1)ans=x%pr[0]==0;
		else if(pr.size()==2)
		{
			ll p=pr[0],q=pr[1];
			ll cnt=qmul((x%p),qpow(q,p-2,p),p);
			ans=1.0*cnt*q<=2.0*x&&cnt*q<=x;
		}
		else
		{
			ans=dis[x%M]<=x;
		}
	}
}
int main()
{
	geti(q);
	for(int i=1;i<=q;i++)
	{
		ll n,k;
		getii(n,k);
		qr[k].PB(MP(n,i));
	}
	foreach(it,qr)
	{
		solve(it->FF,it->SS);
	}
	for(int i=1;i<=q;i++)puts(ANS[i]?"YES":"NO");
	return 0;
}