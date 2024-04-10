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
ll qpow(ll x,ll k){return k==0?1:qpow(x*x%mod,k>>1)*(k&1?x:1)%mod;}
vector<int> fac[200111];
int ANS;
int mu[200111],phi[200111],iphi[200111];
int p[20011],pn;
bool np[200111];
int sumv[200111],sumdv[200111],tab[200111];
int d[200111],a[200111];
void update(int &x,int v)
{
	x+=v;
	x=x>=mod?x-mod:x;
	x=x<0?x+mod:x;
}
void add(int v,int d,int coef)
{
//	cerr<<"add:"<<v<<" "<<d<<" "<<coef<<endl;
	ll t=1ll*d*phi[v]%mod;
	for(int i=0;i<fac[v].size();i++)
	{
		update(sumv[fac[v][i]],coef*phi[v]);
		update(sumdv[fac[v][i]],coef*t);
	}
}
int query(int v,int d)
{
//	cerr<<"query:"<<v<<" "<<d<<endl;
	int ret=0;
	for(int i=0;i<fac[v].size();i++)
	{
		int g=fac[v][i];
		update(ret,1ll*(1ll*sumv[g]*d%mod+sumdv[g])%mod*tab[g]%mod);
	}
	return 1ll*ret*phi[v]%mod;
}
void prework()
{
	for(int i=1;i<=200000;i++)
	{
		for(int j=i;j<=200000;j+=i)
		{
			fac[j].PB(i);
		}
	}
	np[1]=phi[1]=mu[1]=1;
	for(int i=2;i<=200000;i++)
	{
		if(!np[i])
		{
			p[pn++]=i;
			phi[i]=i-1;
			mu[i]=-1;
		}
		for(int j=0;j<pn&&p[j]*i<=200000;j++)
		{
			np[p[j]*i]=1;
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];
				mu[i*p[j]]=0;
				break;
			}
			else
			{
				phi[i*p[j]]=phi[i]*(p[j]-1);
				mu[i*p[j]]=-mu[i];
			}
		}
	}	
	for(int i=1;i<=200000;i++)iphi[i]=qpow(phi[i],mod-2);
	for(int i=1;i<=200000;i++)
	{
		for(int j=0;j<fac[i].size();j++)
		{
			update(tab[i],fac[i][j]*1ll*iphi[fac[i][j]]%mod*mu[i/fac[i][j]]);
		}
	}
}
int n;
vector<int>con[200111];
bool ban[200111];
int sz[200111],v[200111],vn;
int pdfs(int x,int pre=-1)
{
	sz[x]=1;v[vn++]=x;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||ban[u])continue;
		pdfs(u,x);
		sz[x]+=sz[u];
	}
}
void idfs(int x,int pre=-1)
{	
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||ban[u])continue;
		d[u]=d[x]+1;
		idfs(u,x);
	}
}
int find_pivot(int x)
{
	vn=0;
	pdfs(x);
	int rt=v[0];
	for(int i=0;i<vn;i++)
	{
		if(sz[v[i]]*2>=sz[v[0]]&&sz[v[i]]<sz[rt])
		{
			rt=v[i];
		}
	}
	d[rt]=0;
	idfs(rt);
	return rt;
}
void dfs(int x,int ty,int pre=-1)
{
	if(ty==0)add(a[x],d[x],1);
	if(ty==1)add(a[x],d[x],-1);
	if(ty==2)update(ANS,query(a[x],d[x])*2ll%mod);
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(ban[u]||u==pre)continue;
		dfs(u,ty,x);
	}
}
void solve(int tx)
{
	int rt=find_pivot(tx);
	for(int i=0;i<con[rt].size();i++)
	{
		int x=con[rt][i];
		if(ban[x])continue;
		dfs(x,2,rt);
		dfs(x,0,rt);
	}
	update(ANS,query(a[rt],0)*2ll%mod);
	for(int i=0;i<con[rt].size();i++)
	{
		int x=con[rt][i];
		if(ban[x])continue;
		dfs(x,1,rt);
	}
	ban[rt]=1;
	for(int i=0;i<con[rt].size();i++)
	{
		int x=con[rt][i];
		if(ban[x])continue;
		solve(x);
	}
}
int main()
{
	prework();
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	solve(1);
	cout<<1ll*ANS*qpow(1ll*n*(n-1)%mod,mod-2)%mod<<endl;
	return 0;
}