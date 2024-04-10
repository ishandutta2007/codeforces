// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<int,int> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
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
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
int f[N],g[N];
std::vector<int> e1[N],e2[N];
int dg1[N],dg2[N];
int _q[N],_l,_r;
int main()
{
	int n,m;
	read(n,m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		e1[x].pb(y);
		e2[y].pb(x);
		++dg1[y],++dg2[x];
	}
	_l=1,_r=0;
	for(int i=1;i<=n;++i)
	{
		f[i]=g[i]=i;
		if(e2[i].empty())
		{
			_q[++_r]=i;
		}
	}
	int cnt=0;
	while(_l!=_r+1)
	{
		++cnt;
		int x=_q[_l++];
		for(int v:e1[x])
		{
			chmin(f[v],f[x]);
			if(!--dg1[v])
			{
				_q[++_r]=v;
			}
		}
	}
	if(cnt!=n)
	{
		printf("-1\n");
		return 0;
	}
	_l=1,_r=0;
	for(int i=1;i<=n;++i)
	{
		if(e1[i].empty())
		{
			_q[++_r]=i;
		}
	}
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int v:e2[x])
		{
			chmin(g[v],g[x]);
			if(!--dg2[v])
			{
				_q[++_r]=v;
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;++i)
	{
		if(f[i]==g[i]&&f[i]==i)
		{
			++res;
		}
	}
	printf("%d\n",res);
	for(int i=1;i<=n;++i)
	{
		if(f[i]==g[i]&&f[i]==i) printf("A");
		else printf("E");
	}
	printf("\n");
	return 0;
}