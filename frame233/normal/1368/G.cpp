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

const int N=200005;
char pool[N<<2],*p=pool,*s[N];
int n,m;
inline int getid(int x,int y)
{
	return (x-1)*m+y;
}
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt,dg[N];
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt,++dg[v];
}
inline bool valid(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;
}
int dfn[N],siz[N],id;
void dfs(int x,int fa)
{
	dfn[x]=++id,siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		dfs(v,x),siz[x]+=siz[v];
	}
}
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int tag[N<<2],len[N<<2];
void upd(int L,int R,int C,int l,int r,int cur)
{
	if(L<=l&&r<=R)
	{
		tag[cur]+=C,len[cur]=tag[cur]?r-l+1:(l!=r?len[ls(cur)]+len[rs(cur)]:0);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) upd(L,R,C,l,mid,ls(cur));
	if(R>mid) upd(L,R,C,mid+1,r,rs(cur));
	len[cur]=tag[cur]?r-l+1:(l!=r?len[ls(cur)]+len[rs(cur)]:0);
}
struct info{
	int x,L,R,opt;
	inline bool operator < (const info &o)const{return x<o.x;}
}q[N<<2];
int pos;
inline void push(int x,int y)
{
	q[++pos]={dfn[x],dfn[y],dfn[y]+siz[y]-1,1};
	q[++pos]={dfn[x]+siz[x],dfn[y],dfn[y]+siz[y]-1,-1};
}
int main()
{
	read(n,m);
	for(int i=0;i<=n+1;++i)s[i]=p,p+=m+2;
	for(int i=1;i<=n;++i) read_str(s[i]+1);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
	{
		if(s[i][j]=='L'&&valid(i,j+2)) addedge(getid(i,j+2),getid(i,j));
		else if(s[i][j]=='R'&&valid(i,j-2)) addedge(getid(i,j-2),getid(i,j));
		else if(s[i][j]=='U'&&valid(i+2,j)) addedge(getid(i+2,j),getid(i,j));
		else if(s[i][j]=='D'&&valid(i-2,j)) addedge(getid(i-2,j),getid(i,j));
	}
	for(int i=1;i<=n*m;++i) if(!dg[i]) dfs(i,0);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
	{
		if(s[i][j]=='L') push(getid(i,j),getid(i,j+1));
		else if(s[i][j]=='R') push(getid(i,j),getid(i,j-1));
		else if(s[i][j]=='U') push(getid(i,j),getid(i+1,j));
		else if(s[i][j]=='D') push(getid(i,j),getid(i-1,j));
	}
	std::sort(q+1,q+pos+1);
	int cur=1;
	ll ans=0;
	for(int i=1;i<=n*m;++i)
	{
		while(cur<=pos&&q[cur].x==i) upd(q[cur].L,q[cur].R,q[cur].opt,1,n*m,1),++cur;
		ans+=len[1];
	}
	printf("%lld\n",ans>>1);
	return 0;
}