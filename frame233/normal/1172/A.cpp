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

const int N=200005;
int a[N],b[N];
int main()
{
	int n;
	read(n);
	int pos=-1;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		read(b[i]);
		if(b[i]==1)
		{
			pos=i;
		}
	}
	bool flag=~pos;
	if(flag)
	{
		for(int i=pos+1;i<=n&&flag;++i)
		{
			if(b[i]!=i-pos+1)
			{
				flag=0;
			}
		}
		for(int i=1;i<pos&&flag;++i)
		{
			if(b[i]&&b[i]-n+pos-1<=i)
			{
				flag=0;
			}
		}
		if(flag)
		{
			printf("%d\n",pos-1);
			return 0;
		}
	}
	int ans=n;
	for(int i=1;i<=n;++i)
	{
		if(b[i])
		{
			chmax(ans,i+n-b[i]+1);
		}
	}
	printf("%d\n",ans);
	return 0;
}