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
std::vector<int> e[N];
int dg[N];
struct node{
	int u,d;
	inline bool operator < (const node &o)const{return d>o.d;}
};
std::priority_queue<node> q;
bool mark[N],used[N];
int ans[N];
std::vector<int> Q[N];
void MAIN()
{
	int n,m,k;read(n,m,k);
	if(k>450) return (void)puts("-1");
	for(int i=1;i<=n;++i) e[i].clear(),dg[i]=0;
	int x,y;
	for(int i=1;i<=m;++i) read(x,y),e[x].pb(y),e[y].pb(x),++dg[x],++dg[y];
	for(int i=0;i<=n;++i) used[i]=mark[i]=false,Q[i].clear();
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;++i) q.push({i,dg[i]});
	std::vector<std::vector<int>> clique;
	while(!q.empty())
	{
		node x=q.top();q.pop();
		if(dg[x.u]!=x.d||used[x.u]) continue;
		if(dg[x.u]==k-1)
		{
			std::vector<int> v={x.u};
			for(auto it:e[x.u]) if(!used[it]) v.pb(it);
			clique.pb(v);
		}
		if(dg[x.u]>=k)
		{
			std::vector<int> v;
			for(int i=1;i<=n;++i) if(dg[i]>=k) v.pb(i);
			printf("1 %d\n",SZ(v));
			for(auto it:v) printf("%d ",it);
			printf("\n");
			return;
		}
		used[x.u]=true;
		for(auto v:e[x.u])
		{
			--dg[v];
			if(!used[v]) q.push({v,dg[v]});
		}
	}
	for(int i=0;i<SZ(clique);++i) ans[i]=0;
	for(int id=0;id<SZ(clique);++id) for(int i=0;i<SZ(clique[id]);++i) Q[clique[id][i]].pb(id);
	for(int i=1;i<=n;++i)
	{
		for(auto v:e[i]) mark[v]=true;
		for(auto it:Q[i]) for(auto v:clique[it]) ans[it]+=mark[v];
		for(auto v:e[i]) mark[v]=false;
	}
	for(int i=0;i<SZ(clique);++i)
	{
		if(ans[i]==k*(k-1))
		{
			printf("2\n");
			for(auto it:clique[i]) printf("%d ",it);
			printf("\n");
			return;
		}
	}
	puts("-1");
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}