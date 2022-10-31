// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;

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
	register int pos(0);
	s[pos]=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) s[++pos]=ch,ch=getchar();
	return pos+1;
}

const int N=5005;
int f[N][N],a[N],b[N];
int main()
{
	memset(f,63,sizeof(f));
	int n;
	read(n);
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		if(a[i]!=a[i-1])
		{
			b[++cnt]=a[i];
		}
	}
	n=cnt;
	for(int i=1;i<=n;++i) f[i][i]=0;
	for(int len=2;len<=n;++len)
	{
		for(int i=1,j=len;j<=n;++i,++j)
		{
			if(b[i]==b[j])
			{
				chmin(f[i][j],f[i+1][j-1]+1);
			}
			else
			{
				chmin(f[i][j],min(f[i+1][j],f[i][j-1])+1);
			}
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}