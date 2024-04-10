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
const int maxn=500000;
int dis[maxn];
int q[maxn],qn;
int pre[maxn];
pair<pair<int,int>,int> pret[maxn];
void prework(int m,int lim)
{
	assert(m<=17);
	memset(dis,-1,sizeof(dis));
	qn=0;
	dis[0]=0;
	q[qn++]=0;
	int mxd=0;
	for(int i=0;i<qn;i++)
	{
		int x=q[i];
		mxd=max(mxd,dis[x]);
		for(int t0=0;t0<m;t0++)
		{
			for(int t1=t0+1;t1<m;t1++)
			{
				int t2=t1-t0+t1;
				int nx=x^(1<<t0)^(1<<t1);
				if(t2>=lim)continue;
				if(t2<m)nx^=(1<<t2);
				if(dis[nx]==-1)
				{
					dis[nx]=dis[x]+1;
					pre[nx]=x;
					pret[nx]=MP(MP(t0,t1),t2);
					q[qn++]=nx;
				}
			}
		}
	}
	cerr<<"mxd="<<mxd<<" qn="<<qn<<endl;
}
int n;
int a[100111];
vector<pair<pair<int,int>,int> > V;
void output()
{
	puts("YES");
	putsi(V.size());
	assert(V.size()<=n/3+12);
	for(int i=1;i<=n;i++)assert(a[i]==0);
	for(int i=0;i<V.size();i++)
	{
		putsiii(V[i].FF.FF,V[i].FF.SS,V[i].SS);
	}
	exit(0);
}
void check()
{
	bool ok=1;
	for(int i=1;i<=3;i++)ok&=!a[i];
	if(ok)
	{
		output();
	}
}
void flip(int x,int y,int z)
{
	V.PB(MP(MP(x,y),z));
	a[x]^=1;
	a[y]^=1;
	a[z]^=1;
	assert(x>=1&&x<=n&&y>=1&&y<=n&&z>=1&&z<=n);
}
void addroute(int dlt,int msk)
{
	while(msk>0)
	{
		flip(dlt+pret[msk].FF.FF,dlt+pret[msk].FF.SS,dlt+pret[msk].SS);
		msk=pre[msk];
	}
}
int main()
{
	prework(9,12);
	geti(n);
//	n=100000;
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
//		a[i]=rand()&1;
	}
	int it=1;
	while(it+16<=n)
	{
		int msk=0;
		for(int j=0;j<9;j++)
		{
			msk|=a[it+j]<<j;
		}
		addroute(it,msk);
		it+=9;
	}
	prework(n-it+1,n-it+1);
	int msk=0;
	for(int i=0;i<=n-it;i++)
	{
		msk|=a[it+i]<<i;
	}
	cerr<<"msk="<<msk<<endl;
	if(dis[msk]==-1)
	{
		puts("NO");
		return 0;
	}
	else
	{
		addroute(it,msk);
		output();
	}
	/*
	for(int i=n+1;i>=4;i--)
	{
		if(a[i])
		{
			a[i-3]^=1;
			a[i]^=1;
			V.PB(MP(MP(i-3,i-2),i-1));
		}
	}
	check();
	if(n>=7)
	{
		if(a[1])
		{
			V.PB(MP(MP(1,4),7));
			V.PB(MP(MP(4,5),6));
			V.PB(MP(MP(5,6),7));
			a[1]^=1;
			a[2]^=1;
		}
		check();
		if(n>=8)
		{
			V.PB(MP(MP(2,5),8));
			V.PB(MP(MP(5,6),7));
			V.PB(MP(MP(6,7),8));
			a[2]^=1;
			a[3]^=1;
			check();
		}
	}
	puts("NO");
	*/
	return 0;
}