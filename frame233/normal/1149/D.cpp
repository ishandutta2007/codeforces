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

const int N=75;
struct edge{
	int v,nxt;
}e1[405],e2[405];
int fr1[N],fr2[N],ec1,ec2;
inline void ae1(int u,int v)
{
	e1[++ec1]=(edge){v,fr1[u]};
	fr1[u]=ec1;
}
inline void ae2(int u,int v)
{
	e2[++ec2]=(edge){v,fr2[u]};
	fr2[u]=ec2;
}
int fa[N],id[N],siz[N];
std::vector<int> nd[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int dp[1<<17][N];
struct node{int st,u,d;}_q1[(1<<17)*N+5],_q2[(1<<17)*N+5];
int _l1,_r1,_l2,_r2;
int main()
{
	int n,m,A,B;read(n,m,A,B);
	int x,y,z;
	for(int i=1;i<=n;++i) fa[i]=i;
	std::vector<pi> E;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		if(z==A) fa[find(x)]=find(y),ae1(x,y),ae1(y,x);
		else E.pb({x,y});
	}
	int cnt=0;
	for(int i=1;i<=n;++i) ++siz[find(i)],nd[find(i)].pb(i);
	for(int i=1;i<=n;++i) if(fa[i]==i&&siz[i]>=4) id[i]=++cnt;
	for(int i=1;i<=n;++i) id[i]=id[find(i)];
	for(auto it:E) if(find(it.first)!=find(it.second)) ae2(it.first,it.second),ae2(it.second,it.first);
	memset(dp,63,sizeof(dp));
	dp[id[1]?1<<(id[1]-1):0][1]=0;
	_q1[_l1=_r1=1]={id[1]?1<<(id[1]-1):0,1,0};
	_l2=1,_r2=0;
	while(_l1!=_r1+1||_l2!=_r2+1)
	{
		node x;
		if(_l1==_r1+1||_l2==_r2+1) x=_l1!=_r1+1?_q1[_l1++]:_q2[_l2++];
		else x=_q1[_l1].d<_q2[_l2].d?_q1[_l1++]:_q2[_l2++];
		int st=x.st;
		for(int i=fr1[x.u];i;i=e1[i].nxt)
		{
			int v=e1[i].v;
			if(dp[st][v]>dp[st][x.u]+A) dp[st][v]=dp[st][x.u]+A,_q1[++_r1]={st,v,dp[st][v]};
		}
		for(int i=fr2[x.u];i;i=e2[i].nxt)
		{
			int v=e2[i].v,to=st|(id[v]?1<<(id[v]-1):0);
			if(id[v]&&st==to) continue;
			if(dp[to][v]>dp[st][x.u]+B) dp[to][v]=dp[st][x.u]+B,_q2[++_r2]={to,v,dp[to][v]};
		}
	}
	for(int i=1;i<=n;++i)
	{
		int ans=inf;
		for(int st=0;st<1<<cnt;++st)chmin(ans,dp[st][i]);
		printf("%d%c",ans," \n"[i==n]);
	}
	return 0;
}