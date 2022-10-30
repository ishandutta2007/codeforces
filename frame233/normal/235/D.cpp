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
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=3005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int st[N],top;
bool vis[N];
int loop[N],pos,id[N];
void dfs1(int x,int fa)
{
	if(pos) return;
	if(vis[x])
	{
		while(st[top]!=x)
		{
			int tmp=st[top--];
			loop[++pos]=tmp;
		}
		loop[++pos]=x;
		return;
	}
	st[++top]=x,vis[x]=true;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		dfs1(v,x);
	}
	if(pos) return;
	--top,vis[x]=false;
}
int dis[N];
void dfs2(int x,int fa)
{
	dis[x]=dis[fa]+1;
	if(fa) id[x]=id[fa];
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa||id[v]) continue;
		dfs2(v,x);
	}
}
double ans;
void dfs3(int x,int fa,int len)
{
	ans+=1.0/(++len);
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa||id[v]!=id[x]) continue;
		dfs3(v,x,len);
	}
}
inline double f(int a,int b,int c,int d)
{
	return (1.0*b/(a+c+d)+1.0*c/(a+b+d)+1)/(a+b+c+d);
}
int main()
{
	int n;read(n);
	int x,y;
	for(int i=1;i<=n;++i) read(x,y),++x,++y,addedge(x,y),addedge(y,x);
	dfs1(1,0);
	for(int i=1;i<=pos;++i) id[loop[i]]=i;
	for(int i=1;i<=pos;++i) dfs2(loop[i],0);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(id[i]!=id[j])ans+=f(dis[i],abs(id[i]-id[j])-1,pos-abs(id[i]-id[j])-1,dis[j]);
	for(int i=1;i<=n;++i)dfs3(i,0,0);
	printf("%.8lf\n",ans);
	return 0;
}