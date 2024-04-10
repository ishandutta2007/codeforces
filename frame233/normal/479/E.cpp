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

const int N=5005,mod=1000000007;
int f[N][N],sum[N][N];
Finline void add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
int main()
{
	int n,a,b,k;
	read(n,a,b,k);
	f[0][a]=1;
	for(int i=a;i<=n;++i) sum[0][i]=1;
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(j<b)
			{
				f[i][j]=(sum[i-1][(j+b-1)>>1]-f[i-1][j]+mod)%mod;
			}
			if(j>b)
			{
				f[i][j]=((sum[i-1][n]-sum[i-1][(j+b)>>1]-f[i-1][j])%mod+mod)%mod;
			}
			sum[i][j]=f[i][j];
			add(sum[i][j],sum[i][j-1]);
		}
	}
	printf("%d\n",sum[k][n]);
    return 0;
}