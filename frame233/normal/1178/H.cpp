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
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=20015;
int a[N],b[N],n,t[N],d[N];
ll e[N];
bool check(int mid)
{
	for(int i=1;i<=n+n;++i) e[i]=1LL*mid*a[i]+b[i],t[i]=i;
	std::sort(t+1,t+n+n+1,[&](int A,int B)->bool{return e[A]<e[B];});
	int id=0;
	for(int i=1;i<=n+n;++i)
	{
		int j=i;
		while(j<n+n&&e[t[j+1]]==e[t[i]]) ++j;
		for(int k=i;k<=j;++k) if(t[k]>n) ++id;
		for(int k=i;k<=j;++k) d[t[k]]=id;
		i=j;
	}
	for(int i=1;i<=n+n;++i) e[i]=b[i],t[i]=i;
	std::sort(t+1,t+n+n+1,[&](int A,int B)->bool{return e[A]<e[B];});
	int maxx=0,cur=0;
	for(int i=1;i<=n+n;++i)
	{
		int j=i;
		while(j<n+n&&e[t[j+1]]==e[t[i]]) ++j;
		for(int k=i;k<=j;++k) chmax(maxx,d[t[k]]);
		for(int k=i;k<=j;++k) if(t[k]<=n) cur=min(cur+1,maxx);
		i=j;
	}
	return cur>=n;
}
struct edge{
	int v,nxt;
	int w,cost;
}c[N<<3];
int front[N],edge_cnt=-1;
inline void addedge(int u,int v,int w,int cost)
{
	c[++edge_cnt]=(edge){v,front[u],w,cost},front[u]=edge_cnt;
	c[++edge_cnt]=(edge){u,front[v],0,-cost},front[v]=edge_cnt;
}
int dep[N],_q[N<<6],_l,_r,cur[N];
bool inq[N];
int node_cnt,S,T;
bool bfs()
{
	memset(dep,63,(node_cnt+3)<<2);
	memcpy(cur,front,(node_cnt+3)<<2);
	memset(inq,0,node_cnt+3);
	dep[S]=0,_q[_l=_r=1]=S;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		inq[x]=false;
		for(int i=front[x];~i;i=c[i].nxt)
		{
			int v=c[i].v;
			if(c[i].w&&dep[v]>dep[x]+c[i].cost)
			{
				dep[v]=dep[x]+c[i].cost;
				if(!inq[v]) inq[v]=true,_q[++_r]=v;
			}
		}
	}
	return dep[T]<inf;
}
int dfs(int x,int flow)
{
	if(x==T||!flow) return flow;
	inq[x]=true;
	int f=0,rf;
	for(int &i=cur[x];~i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(!inq[v]&&dep[v]==dep[x]+c[i].cost&&(rf=dfs(v,min(flow,c[i].w))))
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
	while(bfs()) ans+=dfs(S,inf)*dep[T];
	return ans;
}
int calc(int mid)
{
	memset(front,255,sizeof(front));
	S=9*n+1,T=S+1,node_cnt=T;
	for(int i=1;i<=n;++i) addedge(S,i,1,0),addedge(i,i+n,1,1),addedge(i,i+3*n,1,0);
	for(int i=1;i<=n+n;++i) addedge(n+i,3*n+i,inf,0),addedge(3*n+i,5*n+i,inf,1),addedge(3*n+i,7*n+i,inf,0),addedge(5*n+i,7*n+i,inf,0);
	for(int i=n+1;i<=n+n;++i) addedge(7*n+i,T,1,0);
	for(int i=1;i<=n+n;++i) e[i]=b[i],t[i]=i;
	std::sort(t+1,t+n+n+1,[&](int A,int B)->bool{return e[A]<e[B];});
	int last=0;
	for(int i=1;i<=n+n;++i)
	{
		int j=i;
		while(j<n+n&&e[t[j+1]]==e[t[i]]) ++j;
		for(int k=i;k<=j;++k)
		{
			if(last) addedge(t[k]+n,last,inf,0);
			last=t[k]+n;
		}
		if(i!=j) addedge(t[i]+n,last,inf,0);
		i=j;
	}
	for(int i=1;i<=n+n;++i) e[i]=1LL*mid*a[i]+b[i],t[i]=i;
	std::sort(t+1,t+n+n+1,[&](int A,int B)->bool{return e[A]<e[B];});
	last=0;
	for(int i=1;i<=n+n;++i)
	{
		int j=i;
		while(j<n+n&&e[t[j+1]]==e[t[i]]) ++j;
		for(int k=i;k<=j;++k)
		{
			if(last) addedge(t[k]+5*n,last,inf,0);
			last=t[k]+5*n;
		}
		if(i!=j) addedge(t[i]+5*n,last,inf,0);
		i=j;
	}
	return dinic();
}
int main()
{
	read(n);
	for(int i=1;i<=n+n;++i) read(a[i],b[i]);
	int l=0,r=1e9;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(!check(l)) printf("-1\n");
	else printf("%d %d\n",l,calc(l));
	return 0;
}