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

const int N=1005;
char s[N][N];
bool a[N],b[N];
int fa[N*N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	int n,m;
	read(n,m);
	auto id=[&](int x,int y)->int{return (x-1)*m+y;};
	for(int i=0;i<N;++i) a[i]=b[i]=true;
	for(int i=1;i<=n;++i)
	{
		read_str(s[i]+1);
		for(int j=1;j<=m;++j)
		{
			a[i]&=s[i][j]=='.';
			b[j]&=s[i][j]=='.';
		}
	}
	bool f1=false,f2=false;
	for(int i=1;i<=n;++i) f1|=a[i];
	for(int i=1;i<=m;++i) f2|=b[i];
	if(f1!=f2)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]) continue;
		int cnt=0,a=inf,b=0;
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='#')
			{
				++cnt;
				chmin(a,j);
				chmax(b,j);
			}
		}
		if(cnt!=b-a+1)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(b[i]) continue;
		int cnt=0,a=inf,b=0;
		for(int j=1;j<=n;++j)
		{
			if(s[j][i]=='#')
			{
				++cnt;
				chmin(a,j);
				chmax(b,j);
			}
		}
		if(cnt!=b-a+1)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n*m;++i)
	{
		fa[i]=i;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='.') continue;
			if(s[i-1][j]=='#') fa[find(id(i,j))]=find(id(i-1,j));
			if(s[i+1][j]=='#') fa[find(id(i,j))]=find(id(i+1,j));
			if(s[i][j-1]=='#') fa[find(id(i,j))]=find(id(i,j-1));
			if(s[i][j+1]=='#') fa[find(id(i,j))]=find(id(i,j+1));
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='#')
			{
				ans+=fa[id(i,j)]==id(i,j);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}