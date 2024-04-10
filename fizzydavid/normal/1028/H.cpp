#pragma GCC optimize (3)
#pragma G++ optimize (3)
#pragma g++ optimize("O3")
#pragma gcc optimize("O3")
//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
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
const int maxn=200111;
const int maxm=5200000;
int n,q,a[maxn];
bool np[maxm];
int pr[maxm],pn,mnp[maxm];
int w[maxm];
void prework()
{
	w[1]=0;
	for(int i=2;i<maxm;i++)
	{
		if(!np[i])
		{
			pr[pn++]=i;
			w[i]=1;
			mnp[i]=i;
		}
		for(int j=0;j<pn&&1ll*i*pr[j]<maxm;j++)
		{
			np[i*pr[j]]=1;
			w[i*pr[j]]=w[i]+1;
			mnp[i*pr[j]]=pr[j];
			if(i%pr[j]==0)break;
		}
	}
}
int getnumber()
{
	int x;
	geti(x);
	int ret=x;
	while(x>1&&x%mnp[x]==0)
	{
		while(ret%(1ll*mnp[x]*mnp[x])==0)ret/=mnp[x]*mnp[x];
		x/=mnp[x];
	}
	return ret;
}
vector<int> fac[maxn],facw[maxn];
void getfac(int id,int x)
{
	vector<int> vp;
	int tmp=x;
	while(tmp>1)
	{
		vp.PB(mnp[tmp]);
		tmp/=mnp[tmp];
	}
	vector<int> &ret=fac[id];
	int sz=vp.size();
	for(int i=0;i<(1<<sz);i++)
	{
		int t=1;
		for(int j=0;j<sz;j++)if((i>>j)&1)t*=vp[j];
		ret.PB(t);
		facw[id].PB(w[x]-w[t]);
	}
}
int lg2[1<<10];
int CUR;
struct data
{
	int tab[8];
	int msk,msk2;
	bool ok;
	bool check()
	{
		if(!msk)return false;
		int v0=lg2[msk&(-msk)];
		if(v0+v0>CUR)return false;
		int m=msk-(msk&(-msk));
		if(m&&(m&(-m))<=(1<<(CUR-v0))||msk2&&(msk2&(-msk2))<=(1<<(CUR-v0)))return true;
		else return false;
	}
	void add(int v)
	{
		if(!tab[v])
		{
			msk|=1<<v;
			if(!ok)ok=check();
		}
		else if(tab[v]==1)
		{
			msk2|=1<<v;
			if(!ok)ok=check();
		}
		tab[v]++;
	}
	void del(int v)
	{
		tab[v]--;
		if(!tab[v])
		{
			msk&=~(1<<v);
			if(ok)ok=check();
		}
		else if(tab[v]==1)
		{
			msk2&=~(1<<v);
			if(ok)ok=check();
		}
	}
	void init()
	{
		memset(tab,0,sizeof(tab));
		msk=msk2=ok=0;
	}
}yxg[maxm];
int tabr[maxn][20];
void presolve()
{
	int hscnt=0;
	for(int ans=0;ans<=14;ans++)
	{
		CUR=ans;
		for(int i=1;i<maxm;i++)yxg[i].init();
		hscnt=0;
		int r=0;
		for(int i=1;i<=n;i++)
		{
			while(r<=n&&(r<i||hscnt==0))
			{
				r++;
				if(r<=n)
				{
					for(int j=0;j<fac[r].size();j++)
					{
						int x=fac[r][j];
						hscnt-=yxg[x].ok;
						yxg[x].add(facw[r][j]);
						hscnt+=yxg[x].ok;
					}
				}
			}
			tabr[i][ans]=r;
			if(r<=n)
			{
				for(int j=0;j<fac[i].size();j++)
				{
					int x=fac[i][j];
					hscnt-=yxg[x].ok;
					yxg[x].del(facw[i][j]);
					hscnt+=yxg[x].ok;
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<5;j++)cerr<<tabr[i][j]<<" ";cerr<<endl;
	}*/
	
}
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	for(int i=0;i<10;i++)lg2[1<<i]=i;
	prework();
	cerr<<clock()<<endl;
	getii(n,q);
	for(int i=1;i<=n;i++)
	{
		a[i]=getnumber();
		getfac(i,a[i]);
//		for(int j=0;j<fac[i].size();j++)cerr<<fac[i][j]<<","<<facw[i][j]<<" ";cerr<<endl;
	}
	cerr<<clock()<<endl;
	presolve();
	cerr<<clock()<<endl;
	for(int i=1;i<=q;i++)
	{
		int l,r;
		getii(l,r);
		bool flag=0;
		for(int j=0;j<=14;j++)
		{
			if(tabr[l][j]<=r)
			{
				flag=1;
				putsi(j);
				break;
			}
		}
		assert(flag);
	}
	return 0;
}