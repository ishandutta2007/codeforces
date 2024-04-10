// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

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

const int N=1005;
double a[N][N];
double p[N],E[N];
bool vis[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		p[i]=1.0;
		E[i]=1.0;
		for(int j=1;j<=n;++j)
		{
			scanf("%lf",&a[i][j]);
			a[i][j]/=100.0;
		}
	}
	p[n]=0;
	E[n]=0.0;
	while(true)
	{
		double minn=1e18;
		int pos=0;
		for(int i=1;i<=n;++i)
		{
			if(vis[i]||p[i]==1.0) continue;
			double tmp=E[i]/(1.0-p[i]);
			if(tmp<minn)
			{
				minn=tmp;
				pos=i;
			}
		}
		if(!pos) break;
		vis[pos]=true;
		E[pos]=minn;
		for(int i=1;i<=n;++i)
		{
			if(!vis[i])
			{
				E[i]+=minn*p[i]*a[i][pos];
				p[i]*=(1.0-a[i][pos]);
			}
		}
	}
	printf("%.10lf\n",E[1]);
	return 0;
}