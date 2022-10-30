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

const int N=45;
int f[N][N][N][N];
int a[N][N],line[N][N];
int main()
{
	int n,m,_;
	read(n,m,_);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%1d",&a[i][j]);
			if(!a[i][j])
			{
				line[i][j]=line[i][j-1]+1;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			for(int p=i;p<=n;++p)
			{
				for(int q=j;q<=m;++q)
				{
					int cnt=0,tmp=inf;
					for(int x=p;x>=i;--x)
					{
						chmin(tmp,min(line[x][q],q-j+1));
						cnt+=tmp;
					}
					f[i][j][p][q]=cnt;
				}
			}
		}
	}
	int a,b,c,d;
	while(_--)
	{
		read(a,b,c,d);
		int ans=0;
		for(int i=a;i<=c;++i)
		{
			for(int j=b;j<=d;++j)
			{
				ans+=f[a][b][i][j];
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}