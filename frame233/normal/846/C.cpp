// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=5005;
ll f[N][3],a[N];
int opt[N][3];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	ll sum=0;
	for(int i=1;i<=n;++i)
	{
		sum+=a[i];
		f[i][0]=sum;
		opt[i][0]=i;
		ll tmp=0;
		for(int j=i;j>=1;--j)
		{
			tmp+=a[j];
			if(f[j-1][0]-tmp>f[i][1])
			{
				f[i][1]=f[j-1][0]-tmp;
				opt[i][1]=j-1;
			}
			if(f[j-1][1]+tmp>f[i][2])
			{
				f[i][2]=f[j-1][1]+tmp;
				opt[i][2]=j-1;
			}
		}
		if(f[i][0]>f[i][1])
		{
			f[i][1]=f[i][0];
			opt[i][1]=i;
		}
		if(f[i][1]>f[i][2])
		{
			f[i][2]=f[i][1];
			opt[i][2]=i;
		}
	}
	ll ans=0;
	sum=0;
	int pos=n;
	for(int i=n;i>=1;--i)
	{
		if(ans<f[i][2]-sum)
		{
			ans=f[i][2]-sum;
			pos=i;
		}
		sum+=a[i];
	}
	printf("%d %d %d\n",opt[opt[pos][2]][1],opt[pos][2],pos);
	return 0;
}