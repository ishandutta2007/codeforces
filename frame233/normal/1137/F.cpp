// Author -- xyr2005

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
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=400005;
struct BIT{
	int c[N];
	Finline void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int ch[N][2],fa[N],val[N],tag[N],siz[N];
bool rev[N];
Finline void pushup(int x){siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;}
Finline bool nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
Finline void rotate(int x)
{
	int y=fa[x],z=fa[y],k=x==ch[y][1],w=ch[x][!k];
	ch[x][!k]=y,ch[y][k]=w,nroot(y)&&(ch[z][y==ch[z][1]]=x);
	fa[x]=z,fa[y]=x,w&&(fa[w]=y);
	pushup(y),pushup(x);
}
Finline void upd(int x,int C){x&&(val[x]=C,tag[x]=C);}
Finline void flip(int x){x&&(std::swap(ch[x][0],ch[x][1]),rev[x]^=1);}
Finline void pushdown(int x){tag[x]&&(upd(ch[x][0],tag[x]),upd(ch[x][1],tag[x]),tag[x]=0);rev[x]&&(flip(ch[x][0]),flip(ch[x][1]),rev[x]=0);}
void splay(int x)
{
	static int st[N];
	int y,top;st[top=1]=y=x;
	while(nroot(y)) st[++top]=y=fa[y];
	while(top) pushdown(st[top--]);
	for(;nroot(x);rotate(x),y=fa[x]) nroot(y)&&(rotate((x==ch[y][1])==(y==ch[fa[y]][1])?y:x),0);
}
int n,q,id,root;
void access(int x)
{
	int y=0;
	for(;x;x=fa[y=x])
	{
		splay(x);
		if(val[x]) tr.add(val[x],-(siz[x]-siz[ch[x][1]]));
		ch[x][1]=y,pushup(x);
	}
	upd(y,++id),tr.add(id,siz[y]);
}
Finline void makeroot(int x)
{
	access(x),splay(x),flip(x);
}
Finline int Query(int x)
{
	if(x==root) return n;
	splay(x);
	return tr.sum(val[x]-1)+siz[ch[x][1]]+1;
}
char s[25];
void dfs(int x,int fa)
{
	::fa[x]=fa;
	for(int i=front[x];i;i=c[i].nxt) if(c[i].v!=fa) dfs(c[i].v,x);
}
int main()
{
	read(n,q);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		addedge(x,y),addedge(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i) siz[i]=1;
	for(int i=1;i<=n;++i) makeroot(i);
	for(int i=1;i<=q;++i)
	{
		read_str(s);
		read(x);
		if(s[0]=='u') makeroot(root=x);
		else if(s[0]=='w') printf("%d\n",Query(x));
		else read(y),printf("%d\n",Query(x)<Query(y)?x:y);
	}
	return 0;
}