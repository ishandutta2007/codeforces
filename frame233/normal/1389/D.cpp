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
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
void MAIN()
{
	ll n,k;read(n,k);
	ll l1,r1,l2,r2;read(l1,r1,l2,r2);
	ll L=max(l1,l2),R=min(r1,r2);
	if(l1>l2) std::swap(l1,l2),std::swap(r1,r2);
	if(L<=R)
	{
		k-=(R-L)*n;
		if(k<0) printf("0\n");
		else
		{
			ll c1=max(r1,r2)-min(l1,l2)-(R-L);
			fprintf(stderr,"@ %lld %lld\n",k,c1);
			if(k<=c1*n) printf("%lld\n",k);
			else printf("%lld\n",c1*n+(k-c1*n)*2);
		}
	}
	else
	{
		ll tmp=l2-r1;
		ll c1=r2-l1;
		if(k<=c1) printf("%lld\n",tmp+k);
		else
		{
			ll qwq=max(1LL,min(n,k/c1));
			ll ans=tmp+c1+((k-c1)<<1);
			chmin(ans,qwq*tmp+c1*qwq+(k-c1*qwq)*2);
			if(qwq<n) chmin(ans,(qwq+1)*tmp+k);
			printf("%lld\n",ans);
		}
	}
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}