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

const int N=100005;
int SG[N],a[N];
struct edge{
	int v,nxt;
}c[N<<6];
int front[N],cnt;
Finline void add(const int &u,const int &v){c[++cnt]=(edge){v,front[u]},front[u]=cnt;}
int dg[N];
int _q[N],_l,_r;
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=n;i>=1;--i)
	{
		for(int j=i+a[i];j<=n;j+=a[i])
		{
			if(a[i]<a[j])
			{
				add(j,i);
				++dg[i];
			}
		}
		for(int j=i-a[i];j>=1;j-=a[i])
		{
			if(a[i]<a[j])
			{
				add(j,i);
				++dg[i];
			}
		}
	}
	_l=1;
	for(int i=1;i<=n;++i)
	{
		if(!dg[i])
		{
			_q[++_r]=i;
		}
	}
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=front[x];i;i=c[i].nxt)
		{
			SG[c[i].v]|=!SG[x];
			if(!--dg[c[i].v])
			{
				_q[++_r]=c[i].v;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		printf(SG[i]?"A":"B");
	}
	printf("\n");
	return 0;
}