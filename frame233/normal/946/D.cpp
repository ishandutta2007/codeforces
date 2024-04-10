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

const int N=505;
int a[N][N],pos[N],minn[N][N];
int f[N][N];
int main()
{
	int n,m,k,x;
	read(n,m,k);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%1d",&x);
			if(x)
			{
				a[i][++pos[i]]=j;
			}
		}
		if(!pos[i]) minn[i][0]=0;
		else minn[i][0]=a[i][pos[i]]-a[i][1]+1;
		for(int j=1;j<=k&&j<=pos[i];++j)
		{
			minn[i][j]=inf;
			for(int t=0;t<=j&&t<pos[i]&&pos[i]-(j-t)>0;++t)
			{
				chmin(minn[i][j],a[i][pos[i]-(j-t)]-a[i][t+1]+1);
			}
		}
		minn[i][pos[i]]=0;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			f[i][j]=inf;
			for(int t=0;t<=j&&t<=pos[i];++t)
			{
				chmin(f[i][j],f[i-1][j-t]+minn[i][t]);
			}
		}
	}
	int ans=inf;
	for(int i=0;i<=k;++i) chmin(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}
//