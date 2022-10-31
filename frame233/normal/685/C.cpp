// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

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
template<typename _Tp>void output(_Tp x)
{
	if(x>9) output(x/10);
	putchar(48+x%10);
}
template<typename _Tp>void print(_Tp x,char ch='\n')
{
	if(x<0) putchar('-'),x=-x;
	output(x);
	putchar(ch);
}
const int N=100005;
ll x[N],y[N],z[N];
int n;
ll X,Y,Z;
bool check(ll mid)
{
	ll min1=-4.6e18,min2=-4.6e18,min3=-4.6e18,min4=-4.6e18;
	ll max1=4.6e18,max2=4.6e18,max3=4.6e18,max4=4.6e18;
	for(int i=1;i<=n;++i)
	{
		chmin(max1,x[i]+y[i]+z[i]+mid);
		chmin(max2,x[i]+y[i]-z[i]+mid);
		chmin(max3,x[i]-y[i]+z[i]+mid);
		chmax(min3,-(-x[i]+y[i]-z[i]+mid));
		chmax(min2,-(-x[i]-y[i]+z[i]+mid));
		chmax(min1,-(-x[i]-y[i]-z[i]+mid));
		
		chmax(min4,-x[i]+y[i]+z[i]-mid);
		chmin(max4,-x[i]+y[i]+z[i]+mid);
	}
	/*
	fprintf(stderr,"! %lld %lld\n",min1,max1);
	fprintf(stderr,"! %lld %lld\n",min2,max2);
	fprintf(stderr,"! %lld %lld\n",min3,max3);
	fprintf(stderr,"! %lld %lld\n",min4,max4);
	*/
	for(int i=0;i<=1;++i)
	{
		ll a=min2;
		ll b=min3;
		ll c=min4;
		ll A=max2;
		ll B=max3;
		ll C=max4;
		ll L=min1,R=max1;
		if((a&1)!=i) ++a;
		if((b&1)!=i) ++b;
		if((c&1)!=i) ++c;
		if((L&1)!=i) ++L;
		if((A&1)!=i) --A;
		if((B&1)!=i) --B;
		if((C&1)!=i) --C;
		if((R&1)!=i) --R;
		ll rest=L-(a+b+c);
		if(a>A||b>B||c>C||L>R) continue;
		if(rest<=0)
		{
			if(a+b+c<=R&&a<=A&&b<=B&&c<=C)
			{
				X=(a+b)>>1;
				Y=(a+c)>>1;
				Z=(b+c)>>1;
				return true;
			}
			continue;
		}
		ll tmp=min(rest,A-a);
		a+=tmp;
		rest-=tmp;
		
		tmp=min(rest,B-b);
		b+=tmp;
		rest-=tmp;
		
		tmp=min(rest,C-c);
		c+=tmp;
		rest-=tmp;
		
		if(!rest&&a+b+c<=R&&a<=A&&b<=B&&c<=C)
		{
			X=(a+b)>>1;
			Y=(a+c)>>1;
			Z=(b+c)>>1;
			return true;
		}
	}
	return false;
}
void MAIN()
{
	read(n);
	for(int i=1;i<=n;++i) read(x[i],y[i],z[i]);
	ll l=0,r=3e18;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	check(l);
	printf("%lld %lld %lld\n",X,Y,Z);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}