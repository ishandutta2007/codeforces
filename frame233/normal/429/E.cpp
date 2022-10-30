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
int l[N],r[N],t[N],pos,d[N];
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt=-1;
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;
	c[++edge_cnt]=(edge){u,front[v]},front[v]=edge_cnt;
}
int cur[N],ans[N];
void dfs(int x)
{
	for(int i=cur[x];~i;i=cur[x])
	{
		cur[x]=c[i].nxt;
		if(ans[i>>1]==-1) ans[i>>1]=i&1,dfs(c[i].v);
	}
}
int main()
{
	memset(front,255,sizeof(front));
	memset(ans,255,sizeof(ans));
	int n;read(n);
	for(int i=1;i<=n;++i) read(l[i],r[i]),++r[i],t[++pos]=l[i],t[++pos]=r[i];
	std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i) l[i]=std::lower_bound(t+1,t+pos+1,l[i])-t,r[i]=std::lower_bound(t+1,t+pos+1,r[i])-t,++d[l[i]],--d[r[i]],addedge(l[i],r[i]);
	for(int i=1;i<=pos;++i) d[i]+=d[i-1];
	for(int i=1;i<pos;++i) if(d[i]&1) addedge(i,i+1);
	memcpy(cur,front,sizeof(cur));
	for(int i=1;i<=pos;++i) dfs(i);
	for(int i=0;i<n;++i) printf("%d%c",ans[i]," \n"[i+1==n]);
	return 0;
}