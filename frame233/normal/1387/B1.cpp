// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int dep[N],t[N];
int pre[N],nxt[N],Fa[N];
bool used[N];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;Fa[x]=fa;
	for(int i=front[x];i;i=c[i].nxt) if(c[i].v!=fa) dfs(c[i].v,x);
}
int main()
{
	int n;read(n);
	int x,y;for(int i=1;i<n;++i) read(x,y),addedge(x,y),addedge(y,x);
	dfs(1,0);for(int i=1;i<=n;++i) t[i]=i;std::sort(t+1,t+n+1,[&](int A,int B)->bool{return dep[A]>dep[B];});
	used[0]=true;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int x=t[i];if(used[x]||used[Fa[x]]) continue;ans+=2;
		used[x]=used[Fa[x]]=true;pre[x]=Fa[x],nxt[x]=Fa[x],pre[Fa[x]]=x,nxt[Fa[x]]=x;
	}
	for(int i=1;i<=n;++i)
	{
		if(!used[i])
		{
			ans+=2;
			for(int _=front[i];_;_=c[_].nxt)
			{
				int v=c[_].v;
				if(used[v])
				{
					pre[i]=v,nxt[i]=nxt[v];
					pre[nxt[v]]=i,nxt[v]=i;
					break;
				}
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i) printf("%d ",nxt[i]);
	printf("\n");
	return 0;
}