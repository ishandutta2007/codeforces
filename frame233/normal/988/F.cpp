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
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
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

const int N=2005;
bool used[N];
int w[N];
ll f[N];
int main()
{
	memset(w,255,sizeof(w));
	memset(f,63,sizeof(f));
	int a,n,m,x,y;
	read(a,n,m);
	for(int i=1;i<=n;++i)
	{
		read(x,y);
		for(int j=x;j<y;++j)
		{
			used[j]=1;
		}
	}
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		if(~w[x]) chmin(w[x],y);
		else w[x]=y;
	}
	f[0]=0;
	for(int i=1;i<=a;++i)
	{
		bool flag=1;
		for(int j=i-1;j>=0;--j)
		{
			flag&=!used[j];
			if(flag)
			{
				chmin(f[i],f[j]);
			}
			if(~w[j]&&f[j]<=4557430888798830399ll) chmin(f[i],f[j]+1ll*w[j]*(i-j));
		}
	}
	printf("%lld\n",f[a]>=4557430888798830399ll?-1:f[a]);
	return 0;
}
//