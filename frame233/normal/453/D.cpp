// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=(1<<20)+5;
ll mod;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
inline ll mul(ll a,ll b){return ((a*b-(ll)((long double)a/mod*b)*mod)+mod)%mod;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=mul(res,a);a=mul(a,a),b>>=1;}return res;}
ll a[N],B[21],cnt[N],b[N];
void fwt(ll *a,int limit)
{
	for(int len=2;len<=limit;len<<=1)for(int i=0;i<limit;i+=len)
	{
		ll *p=a+i,*q=a+i+len/2,tp;
		for(int _=0;_<len>>1;++_,++p,++q)tp=*p,add(*p,*q),(*q=tp+mod-*q)>=mod&&(*q-=mod);
	}
}
void ifwt(ll *a,int limit)
{
	fwt(a,limit);
	for(int i=0;i<limit;++i) a[i]/=limit;
}
int main()
{
	int m;ll t;read(m,t,mod);
	for(int i=0;i<1<<m;++i) read(a[i]);
	for(int i=0;i<=m;++i) read(B[i]);
	for(int i=0;i<1<<m;++i) b[i]=B[cnt[i]=cnt[i>>1]+(i&1)];
	mod=(1LL<<m)*mod;
	fwt(a,1<<m),fwt(b,1<<m);
	for(int i=0;i<1<<m;++i) a[i]=mul(a[i],ksm(b[i],t));
	ifwt(a,1<<m);
	for(int i=0;i<1<<m;++i) printf("%lld\n",a[i]);
	return 0;
}