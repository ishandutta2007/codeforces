// Author -- xyr2005

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
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int LIMIT=1e5+1;
const int max_len=1<<18;
const int N=max_len+5;
typedef std::vector<ll> poly;
const double PI=acos(-1);
struct comp{
	double a,b;
	Finline comp operator + (const comp &o)const{return (comp){a+o.a,b+o.b};}
	Finline comp operator - (const comp &o)const{return (comp){a-o.a,b-o.b};}
	Finline comp operator * (const comp &o)const{return (comp){a*o.a-b*o.b,a*o.b+b*o.a};}
};
comp Omgs[N];
int r[N];
int calc(int len)
{
	int limit=1;
	while(limit<len) limit<<=1;
	for(int i=0;i<limit;++i) r[i]=(r[i>>1]>>1)|((i&1)?(limit>>1):0);
	for(int i=0;i<limit;++i) Omgs[i]=(comp){std::cos(2.0*PI*i/limit),std::sin(2.0*PI*i/limit)};
	return limit;
}
void dft(comp *a,int limit)
{
	for(int i=0;i<limit;++i) if(i<r[i]) std::swap(a[i],a[r[i]]);
	for(int len=2,qwq=(limit>>1);len<=limit;len<<=1,qwq>>=1)for(int pos=0;pos<limit;pos+=len)
	{
		comp *p(Omgs),*A(a+pos),*B(a+pos+(len>>1));
		for(int i=0;i<len>>1;++i,p+=qwq)
		{
			comp tmp(*p**B);
			*B=*A-tmp,*A=*A+tmp;
			++A,++B;
		}
	}
}
Finline void idft(comp *a,int limit){std::reverse(a+1,a+limit);dft(a,limit);}
poly operator * (const poly &a,const poly &b)
{
	if(1ull*SZ(a)*SZ(b)<=1000)
	{
		poly c(SZ(a)+SZ(b)-1);
		for(uint i=0;i<a.size();++i) for(uint j=0;j<b.size();++j) c[i+j]+=1ull*a[i]*b[j];
		return c;
	}
	static comp A0[N],A1[N],B0[N],B1[N];
	int tmp=SZ(a)+SZ(b),limit=calc(tmp);
	for(int i=0;i<SZ(a);++i) A0[i]=(comp){double(a[i]&32767),0.0},A1[i]=(comp){double(a[i]>>15),0.0};
	for(int i=0;i<SZ(b);++i) B0[i]=(comp){double(b[i]&32767),0.0},B1[i]=(comp){double(b[i]>>15),0.0};
	for(int i=SZ(a);i<limit;++i) A0[i]=A1[i]=(comp){0.0,0.0};
	for(int i=SZ(b);i<limit;++i) B0[i]=B1[i]=(comp){0.0,0.0};
	dft(A0,limit),dft(A1,limit),dft(B0,limit),dft(B1,limit);
	for(int i=0;i<limit;++i)
	{
		comp a0=A0[i],a1=A1[i],b0=B0[i],b1=B1[i];
		A0[i]=a1*b1;
		A1[i]=a1*b0+a0*b1;
		B0[i]=a0*b0;
	}
	idft(A0,limit),idft(A1,limit),idft(B0,limit);
	poly c(tmp-1);
	for(int i=0;i+1<tmp;++i) c[i]=(((ll)(A0[i].a/(double)limit+0.5)<<30)+((ll)(A1[i].a/(double)limit+0.5)<<15)+(ll)(B0[i].a/(double)limit+0.5));
	return c;
}
Finline poly operator *= (poly &a,const poly &b){return a=a*b;}
template<typename _Tp>Finline poly operator * (poly a,const _Tp &b){return a*=b;}
template<typename _Tp>Finline poly operator * (const _Tp &b,poly a){return a*=b;}
int X[N];
ll ans[N];
int n,m,q;
void solve(std::vector<ll> a,std::vector<ll> b,int opt)
{
	poly A0(LIMIT),B0(LIMIT),A1(LIMIT),B1(LIMIT);
	for(auto it:a) ++A0[it];
	for(auto it:b) ++B0[it];
	for(int i=0;i+1<SZ(a);++i) ++A1[min(a[i],a[i+1])];
	for(int i=0;i+1<SZ(b);++i) ++B1[min(b[i],b[i+1])];
	poly n=A0*B0,m1=A0*B1,m2=A1*B0,f=A1*B1;
	for(int i=SZ(n)-2;i>=0;--i) n[i]+=n[i+1];
	for(int i=SZ(m1)-2;i>=0;--i) m1[i]+=m1[i+1];
	for(int i=SZ(m2)-2;i>=0;--i) m2[i]+=m2[i+1];
	for(int i=SZ(f)-2;i>=0;--i) f[i]+=f[i+1];
	for(int i=1;i<=q;++i) ans[i]+=opt*(n[X[i]]-m1[X[i]]-m2[X[i]]+f[X[i]]);
}
int main()
{
	read(n,m,q);
	std::vector<ll> a(n),b(m);
	for(auto &&it:a) read(it);
	for(auto &&it:b) read(it);
	for(int i=1;i<=q;++i) read(X[i]);
	solve(a,b,1);
	for(auto &&it:a) it=LIMIT-it;
	for(auto &&it:b) it=LIMIT-it;
	for(int i=1;i<=q;++i) X[i]=min(LIMIT*2-X[i]+1,LIMIT*2-1);
	solve(a,b,-1);
	for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
	return 0;
}