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

const int N=200005;
struct edge{int v,nxt;}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v){c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;}
int dep[N],Fa[N],o[N];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int i=front[x];i;i=c[i].nxt)if(c[i].v!=fa)dfs(c[i].v,x);
}
void getp(int x,int fa)
{
	Fa[x]=fa;
	for(int i=front[x];i;i=c[i].nxt)if(c[i].v!=fa)getp(c[i].v,x);
}
bool tag[N];
struct node{
	int x,len,to;
	inline bool operator < (const node &o)const{return len>o.len;}
}t[N];
int main()
{
	int n;read(n);
	int x,y;
	for(int i=1;i<n;++i)read(x,y),addedge(x,y),addedge(y,x);
	dfs(1,0);
	int rt1=std::max_element(dep+1,dep+n+1)-dep;
	dfs(rt1,0);
	int rt2=std::max_element(dep+1,dep+n+1)-dep;
	getp(rt1,0);
	int cur=rt2;
	std::vector<int> diam;
	while(cur)tag[cur]=true,diam.pb(cur),cur=Fa[cur];
	dep[0]=-1,dfs(rt1,0);
	for(int i=1;i<=n;++i)o[i]=dep[i];
	dep[0]=-1,dfs(rt2,0);
	int pos=0;for(int i=1;i<=n;++i)if(!tag[i])t[++pos]={i,max(o[i],dep[i]),o[i]>dep[i]?rt1:rt2};
	std::sort(t+1,t+pos+1);
	std::vector<std::tuple<int,int,int>> ans;
	ll res=0;for(int i=1;i<=pos;++i)ans.pb({t[i].x,t[i].to,t[i].x}),res+=t[i].len;
	while(SZ(diam)>1)ans.pb({diam[0],diam.back(),diam.back()}),res+=SZ(diam)-1,diam.pop_back();
	printf("%lld\n",res);
	for(auto [a,b,c]:ans)printf("%d %d %d\n",a,b,c);
	return 0;
}