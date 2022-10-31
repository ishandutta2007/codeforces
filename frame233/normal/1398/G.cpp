// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int max_len=1<<19;
const int N=max_len+5;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
template<typename _Tp>Finline _Tp _sub(_Tp a,const _Tp &b){(a+=mod-b)>=mod&&(a-=mod);return a;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
typedef std::vector<int> poly;
void print(const poly &a)
{
	for(auto it:a) printf("%d ",it);
	printf("\n");
}
poly operator += (poly &a,const poly &b)
{
	if(SZ(b)>SZ(a)) a.resize(SZ(b));
	for(uint i=0;i<b.size();++i) add(a[i],b[i]);
	return a;
}
Finline poly operator + (const poly &a,const poly &b){poly tmp(a);tmp+=b;return tmp;}
poly operator -= (poly &a,const poly &b)
{
	if(SZ(b)>SZ(a)) a.resize(SZ(b));
	for(uint i=0;i<b.size();++i) sub(a[i],b[i]);
	return a;
}
Finline poly operator - (const poly &a,const poly &b){poly tmp(a);tmp-=b;return tmp;}
ull Omgs[N];
int r[N];
int calc(int len)
{
	int limit=1;
	while(limit<len) limit<<=1;
	for(int i=0;i<limit;++i) r[i]=(r[i>>1]>>1)|((i&1)?(limit>>1):0);
	return limit;
}
void setup()
{
	ll G=ksm(3,(mod-1)/max_len);
	Omgs[max_len>>1]=1;
	for(int i=(max_len>>1)+1;i<max_len;++i) Omgs[i]=Omgs[i-1]*G%mod;
	for(int i=(max_len>>1)-1;i>=0;--i) Omgs[i]=Omgs[i<<1];
}
void dft(poly &a,int limit)
{
	static ull A[N];
	for(int i=0;i<limit;++i) A[r[i]]=a[i];
	for(int len=2,hf=1;len<=limit;len<<=1,hf<<=1)for(int pos=0;pos<limit;pos+=len)
	{
		ull *w(Omgs+hf),*p(A+pos),*q(A+pos+hf);
		for(int i=0;i<hf;++i,++p,++q)
		{
			ull tmp=(*w++)*(*q)%mod;
			*q=*p+mod-tmp,*p+=tmp;
		}
	}
	for(int i=0;i<limit;++i) a[i]=A[i]%mod;
}
void idft(poly &a,int limit)
{
	std::reverse(&a[1],&a[limit]);dft(a,limit);
	ull inv=mod-(mod-1)/limit;for(int i=0;i<limit;++i) a[i]=inv*a[i]%mod;
}
poly operator * (poly a,poly b)
{
	if(1ull*SZ(a)*SZ(b)<=100)
	{
		poly c(SZ(a)+SZ(b)-1);
		for(uint i=0;i<a.size();++i) for(uint j=0;j<b.size();++j) add(c[i+j],1ull*a[i]*b[j]%mod);
		return c;
	}
	int tmp=SZ(a)+SZ(b),limit=calc(tmp);a.resize(limit),b.resize(limit),dft(a,limit),dft(b,limit);
	for(int i=0;i<limit;++i) a[i]=1ull*a[i]*b[i]%mod;
	return idft(a,limit),a.resize(tmp-1),a;
}
Finline poly operator *= (poly &a,const poly &b){return a=a*b;}
template<typename _Tp>Finline poly operator *= (poly &a,const _Tp &b)
{
	for(auto &&it:a) it=1ll*it*b%mod;
	return a;
}
template<typename _Tp>Finline poly operator * (poly a,const _Tp &b){return a*=b;}
template<typename _Tp>Finline poly operator * (const _Tp &b,poly a){return a*=b;}
template<typename _Tp>Finline poly operator /= (poly &a,const _Tp &b)
{
	ll inv=ksm(b);
	for(auto &&it:a) it=1ll*it*inv%mod;
	return a;
}
template<typename _Tp>Finline poly operator / (poly a,const _Tp &b){return a/=b;}
template<typename _Tp>Finline poly operator / (const _Tp &b,poly a){return a/=b;}
const int MAXN=1000005;
std::vector<int> d[MAXN];
int main()
{
	setup();
	for(int i=MAXN-1;i>=1;--i)for(int j=i;j<MAXN;j+=i)d[j].pb(i);
	int k,n,m;read(k,n,m);
	int x;poly a(n+1),b(n+1);
	for(int i=0;i<=k;++i) read(x),a[x]=1,b[n-x]=1;
	a*=b;int q;read(q);
	while(q--)
	{
		int x;read(x);x>>=1;
		for(auto it:d[x]) if(it<=m+n&&it>m&&a[it-m+n]){printf("%d ",it<<1);goto end;}
		printf("-1 ");
		end:{}
	}
	printf("\n");
	return 0;
}