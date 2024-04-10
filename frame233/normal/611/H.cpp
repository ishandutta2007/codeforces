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
int read()
{
	char ch;do{ch=getchar();}while(ch!='?');
	int ans=0;do{ch=getchar(),++ans;}while(ch=='?');
	return ans;
}
int calc(int x)
{
	int cnt=0;
	while(x) x/=10,++cnt;
	return cnt;
}
int b[7][7],C[7][7],siz[7],cnt,a[7],n,oc[7],kp[7],nd[7],A[35],B[35];
struct edge{int v,nxt,w;}c[205];
int front[35],edge_cnt;
inline void addedge(int u,int v,int w)
{
	c[++edge_cnt]=(edge){v,front[u],w},front[u]=edge_cnt;
	c[++edge_cnt]=(edge){u,front[v],0},front[v]=edge_cnt;
}
int dep[35],cur[35],S,T,_q[35],_l,_r;
bool bfs()
{
	memset(dep,255,sizeof(dep));
	memcpy(cur,front,sizeof(cur));
	_q[_l=_r=1]=S,dep[S]=0;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=front[x];~i;i=c[i].nxt)
		{
			int v=c[i].v;
			if(c[i].w&&dep[v]==-1) dep[v]=dep[x]+1,_q[++_r]=v;
		}
	}
	return ~dep[T];
}
int dfs(int x,int flow)
{
	if(x==T||!flow) return flow;
	int f=0,rf;
	for(int &i=cur[x];~i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(dep[v]==dep[x]+1&&(rf=dfs(v,min(flow,c[i].w))))
		{
			flow-=rf,f+=rf;
			c[i].w-=rf,c[i^1].w+=rf;
			if(!flow) return f;
		}
	}
	return f;
}
int dinic()
{
	int ans=0;
	while(bfs())ans+=dfs(S,inf);
	return ans;
}
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int dep)
{
	if(dep>=cnt-1)
	{
		memcpy(b,C,sizeof(b));
		std::vector<pi> E;
		if(cnt>1)
		{
			std::priority_queue<int,std::vector<int>,std::greater<int>> q;
			memset(oc,0,sizeof(oc));
			for(int i=1;i<cnt-1;++i) ++oc[a[i]];
			for(int i=1;i<=cnt;++i) if(!oc[i]) q.push(i);
			for(int i=1;i<cnt-1;++i)
			{
				int a=q.top(),b=::a[i];q.pop();
				if(a>b) std::swap(a,b);
				--::b[a][b],E.pb({kp[a],kp[b]});
				if(!--oc[::a[i]]) q.push(::a[i]);
			}
			int nd1=q.top();q.pop();
			int nd2=q.top();
			if(nd1>nd2) std::swap(nd1,nd2);
			E.pb({kp[nd1],kp[nd2]}),--b[nd1][nd2];
		}
		for(int i=1;i<=cnt;++i)for(int j=i;j<=cnt;++j)if(b[i][j]<0)return;
		memset(front,255,sizeof(front)),edge_cnt=-1;
		S=cnt*(cnt+1)/2+cnt+1,T=S+1;
		for(int i=1;i<=cnt;++i) addedge(S,i,siz[i]);
		int id=cnt;
		for(int i=1;i<=cnt;++i)for(int j=i;j<=cnt;++j)++id,addedge(i,id,b[i][j]),addedge(j,id,b[i][j]),addedge(id,T,b[i][j]),A[id]=i,B[id]=j;
		if(dinic()==n-cnt)
		{
			for(int i=1;i<=cnt;++i) nd[i]=kp[i];
			for(int i=1;i<=cnt;++i) for(int _=front[i];~_;_=c[_].nxt)if(c[_].v!=S)
			{
				int r=c[_^1].w,qwq=A[c[_].v]==i?B[c[_].v]:A[c[_].v];
				while(r--) E.pb({++nd[i],kp[qwq]});
			}
			assert(SZ(E)==n-1);
			std::iota(fa,fa+n+1,0);
			for(auto it:E) fa[find(it.first)]=find(it.second);
			for(int i=1;i<=n;++i) assert(find(i)==find(1));
			for(auto it:E) printf("%d %d\n",it.first,it.second);
			exit(0);
		}
		return;
	}
	for(int i=1;i<=cnt;++i) a[dep]=i,dfs(dep+1);
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i) ++siz[calc(i)];
	for(int i=1;i<n;++i)
	{
		int a=read(),b=read();
		if(a>b) std::swap(a,b);
		++C[a][b];
	}
	kp[1]=1;for(int i=2;i<=6;++i) kp[i]=kp[i-1]*10;
	for(int i=1;i<=6;++i) if(siz[i]) ++cnt,--siz[i];
	dfs(1);
	puts("-1");
	return 0;
}