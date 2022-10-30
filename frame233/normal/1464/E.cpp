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

const int N=100005;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt,dg[N];
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt,++dg[v];
}
std::vector<int> e[N];
int _q[N],_l,_r,f[N],a[513];
bool vis[513];
int main()
{
	int n,m;read(n,m);
	int x,y;
	for(int i=1;i<=m;++i) read(x,y),addedge(y,x),e[x].pb(y);
	for(int i=1;i<=n;++i) if(!dg[i]) _q[++_r]=i;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(auto v:e[x]) vis[f[v]]=true;
		while(vis[f[x]])++f[x];
		for(auto v:e[x]) vis[f[v]]=false;
		for(int i=front[x];i;i=c[i].nxt)if(!--dg[c[i].v])_q[++_r]=c[i].v;
	}
	for(int i=1;i<=n;++i) ++a[f[i]];
	for(int len=2;len<=512;len<<=1) for(int i=0;i<512;i+=len)
	{
		int *p=a+i,*q=a+i+(len>>1);
		for(int pos=0;pos<len>>1;++pos,++p,++q)
		{
			int x=*p;
			add(*p,*q),*q=mod-*q,add(*q,x);
		}
	}
	int ans=0;
	for(int i=0;i<512;++i) add(ans,ksm(n+mod+1-a[i]));
	ans=(1+mod-1LL*ans*ksm(512)%mod)%mod;
	printf("%d\n",ans);
	return 0;
}