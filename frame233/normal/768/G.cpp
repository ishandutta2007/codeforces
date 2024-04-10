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

const int N=100005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int siz[N],son[N],n;
int ans[N];
int limit[N];
struct node{
	int val1,val2,id;
};
std::vector<node> v1[N],v2[N];
void dfs1(int x,int fa)
{
	siz[x]=1;
	std::vector<pi> qwq;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		dfs1(v,x);
		siz[x]+=siz[v],qwq.pb(mkpr(siz[v],v));
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
	if(siz[x]!=n) qwq.pb(mkpr(n-siz[x],fa));
	std::sort(qwq.begin(),qwq.end());
	if(SZ(qwq)>=2)
	{
		limit[x]=qwq[SZ(qwq)-2].first;
		pi tmp=qwq.back();
		if(tmp.second==fa) v2[x].pb((node){qwq[0].first,tmp.first,x});
		else v1[tmp.second].pb((node){qwq[0].first,tmp.first,x});
	}
}
std::set<int> S;
int Son,b[N];
void Upd(int x,int opt)
{
	if(b[x]==0) S.insert(x);
	b[x]+=opt;
	if(b[x]==0) S.erase(S.find(x));
}
void upd(int x,int fa,int opt)
{
	Upd(siz[x],opt);
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa||v==Son) continue;
		upd(v,x,opt);
	}
}
void dfs2(int x,int fa,bool keep)
{
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa||v==son[x]) continue;
		dfs2(v,x,0);
	}
	if(son[x]) dfs2(son[x],x,1),Son=son[x];
	upd(x,fa,1),Son=0;
	for(auto it:v1[x])
	{
		auto qwq=S.lower_bound((it.val2-it.val1)>>1);
		if(qwq!=S.end()) chmin(ans[it.id],max(it.val1+*qwq,it.val2-*qwq));
		if(qwq!=S.begin()) --qwq,chmin(ans[it.id],max(it.val1+*qwq,it.val2-*qwq));
	}
	if(!keep) upd(x,fa,-1);
}
int __[N];
std::set<int> _;
inline void ___(int x,int opt)
{
	if(x==n) return;
	if(!__[x]) _.insert(x);
	__[x]+=opt;
	if(!__[x]) _.erase(_.find(x));
}
void dfs3(int x,int fa,bool keep)
{
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa||v==son[x]) continue;
		___(siz[x],1);
		Upd(siz[x],-1);
		dfs3(v,x,0);
		Upd(siz[x],1);
		___(siz[x],-1);
	}
	if(son[x])
	{
		___(siz[x],1);
		Upd(siz[x],-1);
		dfs3(son[x],x,1),Son=son[x];
		Upd(siz[x],1);
		___(siz[x],-1);
	}
	upd(x,fa,-1),Son=0;
	for(auto it:v2[x])
	{
		auto qwq=S.lower_bound((it.val2-it.val1)>>1);
		if(qwq!=S.end()) chmin(ans[it.id],max(it.val1+*qwq,it.val2-*qwq));
		if(qwq!=S.begin()) --qwq,chmin(ans[it.id],max(it.val1+*qwq,it.val2-*qwq));
		
		qwq=_.lower_bound(((it.val2-it.val1)>>1)+siz[x]);
		if(qwq!=_.end()) chmin(ans[it.id],max(it.val1+(*qwq-siz[x]),it.val2-(*qwq-siz[x])));
		if(qwq!=_.begin()) --qwq,chmin(ans[it.id],max(it.val1+(*qwq-siz[x]),it.val2-(*qwq-siz[x])));
	}
	if(!keep) upd(x,fa,1);
}
int main()
{
	read(n);
	int x,y,root=0;
	for(int i=1;i<=n;++i)
	{
		read(x,y);
		if(!x||!y) root=x|y;
		else addedge(x,y),addedge(y,x);
		ans[i]=n-1;
	}
	S.insert(0);
	dfs1(root,0);
	dfs2(root,0,0);
	for(int i=1;i<=n;++i) Upd(siz[i],1);
	dfs3(root,0,0);
	for(int i=1;i<=n;++i) printf("%d\n",max(ans[i],limit[i]));
	return 0;
}