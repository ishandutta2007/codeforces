// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=300005;
int a[N],in[N],out[N],id1,id2,b[N],siz[N],Fa[N],c[N],pos,dep[N],qwq;
std::vector<int> e[N];
void dfs1(int x,int fa)
{
	in[x]=++id1,siz[x]=1,Fa[x]=fa;
	for(auto v:e[x])if(v!=fa)dep[v]=dep[x]+1,dfs1(v,x),siz[x]+=siz[v];
	out[x]=++id2,b[id2]=x;
}
void dfs2(int x,int fa)
{
	if(a[x]>=qwq)c[++pos]=a[x];
	for(auto v:e[x])if(v!=fa)dfs2(v,x);
}
inline bool check(int x,int y){return in[x]<=in[y]&&in[y]<in[x]+siz[x];}
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	for(int i=1;i<=n;++i)std::sort(e[i].begin(),e[i].end(),[&](int A,int B){return a[A]<a[B];});
	dfs1(1,0);
	if(a[1]==1)
	{
		for(int i=1;i<=n;++i)if(in[i]!=a[i])return puts("NO"),0;
		printf("YES\n%d\n",0);
		for(int i=1;i<=n;++i)printf("%d%c",a[i]," \n"[i==n]);
		return 0;
	}
	qwq=a[1]-1;
	ll ans=0;
	int u=std::find(a+1,a+n+1,qwq)-a;
	if(!check(u,b[qwq]))return puts("NO"),0;
	while(u>1)
	{
		if(a[u]>a[Fa[u]])return puts("NO"),0;
		std::swap(a[u],a[Fa[u]]),u=Fa[u],++ans;
	}
	for(int i=1;i<=n;++i)if(a[i]<qwq&&i!=b[a[i]])return puts("NO"),0;
	for(int i=1;i<=n;++i)if(a[i]<qwq)ans+=dep[i];
	dfs2(1,0);
	for(int i=1;i<pos;++i)if(c[i]>c[i+1])return puts("NO"),0;
	printf("YES\n%lld\n",ans);
	for(int i=1;i<=n;++i)printf("%d%c",in[i]," \n"[i==n]);
	return 0;
}