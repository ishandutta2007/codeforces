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

const int N=605;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
ll INV[N];
struct edge{int v,nxt;}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v){c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;}
int ans[405][405],_q[405],_l,_r,dis[405];
std::vector<int> e1[405],e2[405],r1[405],r2[405];
int n,m;
int dg[405];
void bfs(int x,std::vector<int> *e,std::vector<int> *r)
{
	for(int i=1;i<=n;++i)e[i].clear(),r[i].clear();
	memset(dis,255,sizeof(dis)),dis[x]=0,_q[_l=_r=1]=x;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=front[x];i;i=c[i].nxt)
		{
			int v=c[i].v;
			if(dis[v]==-1)dis[v]=dis[x]+1,_q[++_r]=v;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int _=front[i];_;_=c[_].nxt)
		{
			int v=c[_].v;
			if(dis[v]==dis[i]+1)e[i].pb(v),r[v].pb(i);
		}
	}
}
int dp[N],val[N],cnt[N],pre[N],rev[N],inv[N],Q[N];
bool mark[N];
int main()
{
	INV[0]=INV[1]=1;for(int i=2;i<N;++i)INV[i]=INV[mod%i]*(mod-mod/i)%mod;
	read(n,m);
	int x,y;
	for(int i=1;i<=m;++i)read(x,y),addedge(x,y),addedge(y,x);
	for(int a=1;a<=n;++a)
	{
		bfs(a,e1,r1),memset(dg,0,sizeof(dg)),_l=1,_r=0;
		for(int i=1;i<=n;++i)for(auto v:e1[i])++dg[v];
		for(int i=1;i<=n;++i)if(!dg[i])_q[++_r]=i;
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(auto v:e1[x])if(!--dg[v])_q[++_r]=v;
		}
		if(_r!=n)continue;
		for(int i=1;i<=n;++i)rev[_q[i]]=i,Q[i]=_q[i];
		for(int b=a;b<=n;++b)
		{
			bfs(b,e2,r2);
			memset(mark,0,sizeof(mark));
			cnt[0]=0,pre[0]=1,inv[0]=1;
			for(int i=1;i<=n;++i)
			{
				int x=Q[i];
				val[i]=0;
				for(auto v:r1[x])mark[v]=true;
				for(auto v:r2[x])val[i]+=mark[v];
				for(auto v:r1[x])mark[v]=false;
				if(val[i]==0)pre[i]=pre[i-1],cnt[i]=cnt[i-1]+1,inv[i]=inv[i-1];
				else pre[i]=1LL*val[i]*pre[i-1]%mod,cnt[i]=cnt[i-1],inv[i]=inv[i-1]*INV[val[i]]%mod;
			}
			memset(dp,0,(n+3)<<2),dp[a]=1;
			if(a!=b)
			{
				for(int i=2;i<=n;++i)
				{
					int x=Q[i],j;
					for(auto v:r1[x])j=rev[v],add(dp[x],1LL*dp[v]*(cnt[i-1]==cnt[j]?1LL*pre[i-1]*inv[j]%mod:0)%mod);
					if(x==b)break;
				}
			}
			int qwq=dp[b];
			for(int i=rev[b]+1;i<=n;++i)qwq=1LL*qwq*val[i]%mod;
			ans[a][b]=qwq;
		}
	}
	for(int a=1;a<=n;++a)for(int b=1;b<a;++b)ans[a][b]=ans[b][a];
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)printf("%d%c",ans[i][j]," \n"[j==n]);
	return 0;
}