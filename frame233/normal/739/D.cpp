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

const int N=615;
namespace flow
{
	struct edge{
		int v,nxt;
		int w;
	}c[N*N<<4];
	int front[N],edge_cnt;
	int cur[N],dep[N],S,T;
	int _q[N],_l,_r;
	int node_cnt;
	Finline void addedge(int u,int v,int w)
	{
		c[++edge_cnt]=(edge){v,front[u],w},front[u]=edge_cnt;
		c[++edge_cnt]=(edge){u,front[v],0},front[v]=edge_cnt;
	}
	Finline void init(){memset(front,255,sizeof(front)),edge_cnt=-1;}
	bool bfs()
	{
		memset(dep,255,(node_cnt+3)<<2);
		memcpy(cur,front,(node_cnt+3)<<2);
		dep[S]=0;
		_q[_l=_r=1]=S;
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(int i=front[x];~i;i=c[i].nxt)
			{
				if(c[i].w&&!~dep[c[i].v])
				{
					dep[c[i].v]=dep[x]+1;
					_q[++_r]=c[i].v;
				}
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
			if(dep[c[i].v]==dep[x]+1&&(rf=dfs(c[i].v,min(flow,c[i].w))))
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
		while(bfs()) ans+=dfs(S,inf);
		return ans;
	}
}
using namespace flow;

int get()
{
	static char s[15];
	int len=read_str(s);
	if(s[0]=='?') return -1;
	int x=0;for(int i=0;i<len;++i) x=x*10+s[i]-48;
	return x;
}
int D[N],L[N];
int d[N],l[N];
int maxx[N],cnt[N];
bool vis[N][N];
std::vector<int> nd[N][N];
int to[N],n;
int pre[N],id;
int _d_[N],_l_[N];
void solve()
{
	memset(_d_,0,sizeof(_d_));
	memset(_l_,0,sizeof(_l_));
	memcpy(d,D,sizeof(d));
	memcpy(l,L,sizeof(l));
	memset(maxx,-1,sizeof(maxx));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	memset(pre,0,sizeof(pre));
	init();
	for(int i=1;i<=n;++i)
	{
		if(~d[i]&&~l[i])
		{
			chmax(maxx[l[i]],d[i]);
			if(d[i]==0) ++cnt[l[i]];
			vis[l[i]][d[i]]=true;
		}
		if(~l[i]) chmax(maxx[l[i]],0);
	}
	int qwq=0;
	for(int i=1;i<=n;++i) if(~maxx[i]) qwq+=maxx[i]+i;
	if(qwq>n) return;
	int sum=0;
	for(int i=1;i<=n;++i)
	{
		if(~maxx[i])
		{
			++pre[0];
			_d_[pre[0]]=0,_l_[pre[0]]=i;
			int rest=i-cnt[i]%i;
			if(rest==i&&cnt[i]) continue;
			addedge(pre[0]+n,T,rest);
			sum+=rest;
			for(int j=1;j<=n;++j)
			{
				if(~d[j]&&~l[j]) continue;
				if((d[j]==-1||d[j]==0)&&(l[j]==-1||l[j]==i)) addedge(j,pre[0]+n,1);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		pre[i]=pre[i-1];
		if(~maxx[i])
		{
			for(int j=1;j<maxx[i];++j)
			{
				if(!vis[i][j])
				{
					_d_[pre[i]+j]=j,_l_[pre[i]+j]=i;
					addedge(n+pre[i]+j,T,1);
					++sum;
					for(int k=1;k<=n;++k)
					{
						if(~d[k]&&~l[k]) continue;
						if((d[k]==j||d[k]==-1)&&(l[k]==i||l[k]==-1)) addedge(k,n+pre[i]+j,1);
					}
				}
			}
			if(maxx[i]) pre[i]+=maxx[i]-1;
		}
	}
	for(int i=1;i<=n;++i) if(d[i]==-1||l[i]==-1) addedge(S,i,1);
	int ans=dinic();
	if(ans!=sum) return;
	for(int i=1;i<=n;++i)
	{
		if(~d[i]&&~l[i]) continue;
		for(int _=front[i];~_;_=c[_].nxt)
		{
			int v=c[_].v,w=c[_].w;
			if(!w&&v!=S) d[i]=_d_[v-n],l[i]=_l_[v-n];
		}
		if(d[i]==-1&&l[i]==-1) d[i]=0,l[i]=1;
		else if(d[i]==-1)
		{
			if(l[i]==1) d[i]=0;
			else d[i]=1;
		}
		else if(l[i]==-1)
		{
			if(d[i]==0) l[i]=1;
			else l[i]=l[id];
		}
	}
	for(int i=1;i<=n;++i) nd[l[i]][d[i]].pb(i);
	for(int i=1;i<=n;++i)
	{
		assert(SZ(nd[i][0])%i==0);
		for(int l=0,r=i;r<=SZ(nd[i][0]);l+=i,r+=i)
		{
			int last=nd[i][0][r-1];
			for(int j=l;j<r;++j)
			{
				to[nd[i][0][j]]=last;
				last=nd[i][0][j];
			}
		}
		for(int j=1;j<=n;++j)
		{
			if(nd[i][j].empty()) break;
			for(auto it:nd[i][j]) to[it]=nd[i][j-1].back();
		}
	}
	for(int i=1;i<=n;++i) printf("%d%c",to[i]," \n"[i==n]);
	exit(0);
}
int main()
{
	read(n);S=n+n+1,T=S+1,node_cnt=T;
	for(int i=1;i<=n;++i) D[i]=get(),L[i]=get();
	id=1;for(int i=2;i<=n;++i) if(D[i]>D[id]||(D[i]==D[id]&&L[i]!=-1)) id=i;
	if(L[id]!=-1) solve();
	else
	{
		for(int i=1;i<=n;++i)
		{
			L[id]=i;
			solve();
		}
	}
	puts("-1");
	return 0;
}