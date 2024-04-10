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

const int N=100005,mod=1000000007;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add_e(const int &u,const int &v){c[++cnt]=(edge){v,front[u]},front[u]=cnt;}
ll f[N][11][3];
ll tmp[11][3];
int n,m,k,mx;
Finline void add(ll &a,const ll &b){(a+=b)>=mod&&(a-=mod);}
void dfs(int x,int fa)
{
	f[x][0][0]=k-1;
	f[x][1][1]=1;
	f[x][0][2]=m-k;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs(c[i].v,x);
			memcpy(tmp,f[x],sizeof(tmp));
			memset(f[x],0,sizeof(f[x]));
			for(int j=mx;j>=0;--j)
			{
				for(int k=0;k<=j;++k)
				{
					add(f[x][j][0],tmp[j-k][0]*(f[c[i].v][k][0]+f[c[i].v][k][1]+f[c[i].v][k][2])%mod);
					add(f[x][j][1],tmp[j-k][1]*f[c[i].v][k][0]%mod);
					add(f[x][j][2],tmp[j-k][2]*(f[c[i].v][k][0]+f[c[i].v][k][2])%mod);
				}
			}
		}
	}
}
int main()
{
	int x,y;
	read(n,m);
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add_e(x,y),add_e(y,x);
	}
	read(k,mx);
	dfs(1,0);
	ll ans=0;
	for(int i=0;i<=mx;++i)
	{
		for(int j=0;j<3;++j)
		{
			add(ans,f[1][i][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}