// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=300005;
const int mod=998244353;
const int G=3,Gi=332748118;
const int inv2[24]={1,499122177,748683265,873463809,935854081,967049217,982646785,990445569,994344961,996294657,997269505,997756929,998000641,998122497,998183425,998213889,998229121,998236737,998240545,998242449,998243401,998243877,998244115,998244234};
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ull *_G[24],*_Gi[24];
bool Seted_G[24],Seted_Gi[24];
ll ksm(ll a,ll b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int r[N];
int calc(int len)
{
	int limit=1;
	while(limit<len) limit<<=1;
	return limit;
}
int poly_init(int len)
{
	int limit=1;
	while(limit<len) limit<<=1;
	for(int i=0;i<limit;++i) r[i]=(r[i>>1]>>1)|((i&1)?(limit>>1):0);
	return limit;
}
void SetG(int limit,int pos)
{
	if(Seted_G[pos]) return;
	Seted_G[pos]=true;
	_G[pos]=(ull *)(malloc(((limit>>1)+1)<<3));
	ll mul=ksm(G,(mod-1)>>pos);
	_G[pos][0]=1;
	for(int i=1;i<limit>>1;++i)
	{
		_G[pos][i]=_G[pos][i-1]*mul%mod;
	}
}
void SetGi(int limit,int pos)
{
	if(Seted_Gi[pos]) return;
	Seted_Gi[pos]=true;
	_Gi[pos]=(ull *)(malloc(((limit>>1)+1)<<3));
	ll mul=ksm(Gi,(mod-1)>>pos);
	_Gi[pos][0]=1;
	for(int i=1;i<limit>>1;++i)
	{
		_Gi[pos][i]=_Gi[pos][i-1]*mul%mod;
	}
}
void DFT(int *A,int limit)
{
	static ull a[N];
	for(int i=0;i<limit;++i) a[i]=A[r[i]];
	int t(1);
	for(int len(2);len<=limit;len<<=1,++t)
	{
		SetG(len,t);
		for(int pos=0;pos<limit;pos+=len)
		{
			ull *w=_G[t];
			for(int i=pos;i<pos+(len>>1);++i,++w)
			{
				ull tmp=*w*a[i+(len>>1)]%mod;
				a[i+(len>>1)]=a[i]+mod-tmp;
				a[i]+=tmp;
			}
		}
	}
	for(int i=0;i<limit;++i) A[i]=a[i]%mod;
}
void IDFT(int *A,int limit)
{
	static ull a[N];
	for(int i=0;i<limit;++i) a[i]=A[r[i]];
	int t(1);
	for(int len(2);len<=limit;len<<=1,++t)
	{
		SetGi(len,t);
		for(int pos=0;pos<limit;pos+=len)
		{
			ull *w=_Gi[t];
			for(int i=pos;i<pos+(len>>1);++i,++w)
			{
				ull tmp=*w*a[i+(len>>1)]%mod;
				a[i+(len>>1)]=a[i]+mod-tmp;
				a[i]+=tmp;
			}
		}
	}
	ll inv=inv2[t-1];
	for(int i=0;i<limit;++i) A[i]=a[i]%mod*inv%mod;
}
struct poly{
	int *a,n;
	Finline poly(int *p=NULL,int len=0):a(p),n(len){};
	Finline void init(int len)
	{
		a=(int *)calloc(len,4);
		n=len;
	}
	Finline void clear()
	{
		free(a);
		a=NULL;
		n=0;
	}
	Finline void print(int len)
	{
		int lim=min(len,n);
		for(int i=1;i<lim;++i) printf("%d ",a[i]);
		for(int i=n;i<len;++i) printf("0 ");
		printf("\n");
	}
	poly operator * (const poly &o)const
	{
		static int f[N],g[N];
		memcpy(f,a,n<<2);
		memcpy(g,o.a,o.n<<2);
		int limit=poly_init(n+o.n-1);
		DFT(f,limit);
		DFT(g,limit);
		for(int i=0;i<limit;++i) f[i]=1ll*f[i]*g[i]%mod;
		IDFT(f,limit);
		poly c((int *)calloc(n+o.n-1,4),n+o.n-1);
		for(int i=0;i<n+o.n-1;++i) c.a[i]=f[i];
		return c;
	}
};
int t1[2][2][N];
int t2[2][2][N];
int qaq[2][2];
int n,k;
struct matrix{
	poly a[2][2];
	void print()
	{
		DEBUG;
		printf("A(x) :   ");a[0][0].print(inf);
		printf("B(x) :   ");a[0][1].print(inf);
		printf("C(x) :   ");a[1][0].print(inf);
		printf("D(x) :   ");a[1][1].print(inf);
		printf("\n");
	}
	matrix operator * (const matrix &o)const
	{
		static int tmp[N];
		matrix ans;
		memset(qaq,0,sizeof(qaq));
		for(int i=0;i<2;++i)
		{
			for(int j=0;j<2;++j)
			{
				for(int k=0;k<2;++k)
				{
					chmax(qaq[i][j],a[i][k].n+o.a[k][j].n-1);
				}
			}
		}
		int maxx=0;
		for(int i=0;i<2;++i)
		{
			for(int j=0;j<2;++j)
			{
				chmax(maxx,qaq[i][j]);
				chmin(qaq[i][j],k);
				ans.a[i][j].init(qaq[i][j]);
			}
		}
		int limit=poly_init(maxx);
		for(int i=0;i<2;++i)
		{
			for(int j=0;j<2;++j)
			{
				memcpy(t1[i][j],a[i][j].a,a[i][j].n<<2);
				memset(t1[i][j]+a[i][j].n,0,(limit-a[i][j].n)<<2);
				DFT(t1[i][j],limit);
			}
		}
		for(int i=0;i<2;++i)
		{
			for(int j=0;j<2;++j)
			{
				memcpy(t2[i][j],o.a[i][j].a,o.a[i][j].n<<2);
				memset(t2[i][j]+o.a[i][j].n,0,(limit-o.a[i][j].n)<<2);
				DFT(t2[i][j],limit);
			}
		}
		for(int i=0;i<2;++i)
		{
			for(int j=0;j<2;++j)
			{
				for(int k=0;k<2;++k)
				{
					for(int t=0;t<limit;++t) tmp[t]=1ll*t1[i][k][t]*t2[k][j][t]%mod;
					IDFT(tmp,limit);
					for(int t=0;t<qaq[i][j];++t) add(ans.a[i][j].a[t],tmp[t]);
				}
			}
		}
		return ans;
	}
}qwq;
matrix _ksm(matrix a,int b)
{
	matrix res;
	res.a[0][0].init(1);
	res.a[1][1].init(1);
	res.a[0][0].a[0]=1;
	res.a[1][1].a[0]=1;
	res.a[0][1].init(1);
	res.a[1][0].init(1);
	res.a[0][1].a[0]=0;
	res.a[1][0].a[0]=0;;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a,b>>=1;
	}
	return res;
}
int main()
{
	read(n,k);
	++k;
	qwq.a[0][0].init(2);
	qwq.a[0][0].a[0]=qwq.a[0][0].a[1]=1;
	qwq.a[0][1].init(1);
	qwq.a[0][1].a[0]=1;
	qwq.a[1][0].init(2);
	qwq.a[1][0].a[1]=1;
	qwq.a[1][1].init(1);
	qwq.a[1][1].a[0]=0;
	_ksm(qwq,n).a[0][0].print(k);
	return 0;
}