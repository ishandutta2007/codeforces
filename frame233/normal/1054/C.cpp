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

const int N=1005;
int l[N],r[N];
int rk[N],tmp[N];
bool check(int n)
{
	for(int i=1;i<=n;++i)
	{
		int Lt=0;
		for(int j=1;j<i;++j)
		{
			if(rk[j]>rk[i])
			{
				++Lt;
			}
		}
		if(Lt!=l[i]) return 0;
		int Rt=0;
		for(int j=i+1;j<=n;++j)
		{
			if(rk[j]>rk[i])
			{
				++Rt;
			}
		}
		if(Rt!=r[i]) return 0;
	}
	return 1;
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(l[i]);
	for(int i=1;i<=n;++i) read(r[i]);
	for(int i=1;i<=n;++i)
	{
		rk[i]=(n-1-l[i]-r[i]);
		if(l[i]+r[i]+1>n)
		{
			printf("NO\n");
			return 0;
		}
	}
	if(check(n))
	{
		printf("YES\n");
		for(int i=1;i<=n;++i) tmp[i]=rk[i];
		std::sort(tmp+1,tmp+n+1);
		int len=std::unique(tmp+1,tmp+n+1)-tmp-1;
		for(int i=1;i<=n;++i) printf("%d ",std::lower_bound(tmp+1,tmp+len+1,rk[i])-tmp);
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
    return 0;
}