// Author -- Frame

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

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
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

const int N=100005;
std::set<int> e[N];
int siz[N],n;
int maxx,rt;
void getrt(int x,int fa)
{
	siz[x]=1;
	int tmp=0;
	for(auto v:e[x])
	{
		if(v==fa) continue;
		getrt(v,x);
		siz[x]+=siz[v];
		chmax(tmp,siz[v]);
	}
	chmax(tmp,n-siz[x]);
	if(tmp<maxx) maxx=tmp,rt=x;
}
int dep[N];
ll sum;
void dfs1(int x,int fa)
{
	sum+=dep[x],siz[x]=1;
	for(auto v:e[x])
	{
		if(v==fa) continue;
		dep[v]=dep[x]+1;
		dfs1(v,x);
		siz[x]+=siz[v];
	}
}
int bel[N],id,Fa[N];
void dfs2(int x,int fa)
{
	bel[x]=id,siz[x]=1,Fa[x]=fa;
	for(auto v:e[x])
	{
		if(v==fa) continue;
		dfs2(v,x);
		siz[x]+=siz[v];
	}
	if(fa) e[x].erase(e[x].find(fa));
}
struct node{
	int id,val;
	Finline bool operator < (const node &o)const
	{
		return val<o.val;
	}
};
std::priority_queue<node> q1,q2[N];
int dg[N],ddg[N];
int head[N];
bool used[N];
int tar;
int resA,resB;
void dfs3(int x,int dep)
{
	++dep;
	if(!used[x]&&!resA)
	{
		if(dep==tar&&!e[x].empty())
		{
			resA=x;
			resB=*e[x].begin();
		}
	}
	for(auto v:e[x]) dfs3(v,dep);
}
std::priority_queue<node> q;
std::vector<int> sons[N];
int main()
{
	ll k;read(n,k);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		e[x].insert(y);
		e[y].insert(x);
	}
	maxx=inf;getrt(1,0);
	dfs1(rt,0);
	for(auto it:e[rt])
	{
		++id;
		head[id]=it;
		dfs2(it,rt);
		q1.push((node){id,siz[it]});
	}
	for(int i=1;i<=n;++i) if(i!=rt) dg[i]=SZ(e[i]);
	for(int i=1;i<=n;++i)
	{
		if(i==rt) continue;
		for(auto v:e[i]) ddg[i]+=dg[v];
		if(!ddg[i]&&dg[i]) q2[bel[i]].push((node){i,dep[i]});
	}
	if(k>sum) return puts("NO"),0;
	std::vector<pi> ans;
	auto upd=[&](int x)
	{
		--dg[Fa[x]],--ddg[Fa[Fa[x]]];
	};
	auto check=[&](int x)
	{
		if(!ddg[x]&&dg[x]) q2[bel[x]].push((node){x,dep[x]});
	};
	if((sum&1)!=(k&1)) return puts("NO"),0;
	int goal=0;
	while(sum>k)
	{
		if(q1.empty()) return puts("NO"),0;
		node x=q1.top();q1.pop();
		if(x.val<2) return puts("NO"),0;
		x.val-=2;
		if(x.val) q1.push(x);
		int o=x.id;
		node y=q2[o].top();
		q2[o].pop();
		int nd=y.id;
		if(sum-y.val*2<k)
		{
			goal=o;
			break;
		}
		sum-=y.val*2;
		if(SZ(e[nd])>=2)
		{
			int A=*e[nd].begin();
			e[nd].erase(e[nd].begin());
			int B=*e[nd].begin();
			e[nd].erase(e[nd].begin());
			ans.pb(mkpr(A,B));
			upd(A),upd(B);
			check(nd),check(Fa[nd]);
		}
		else if(SZ(e[nd])==1)
		{
			int A=*e[nd].begin();
			e[nd].erase(e[nd].begin());
			e[Fa[nd]].erase(nd);
			ans.pb(mkpr(A,nd));
			upd(A),upd(nd);
			check(Fa[nd]),check(Fa[Fa[nd]]);
		}
	}
	for(auto it:ans) used[it.first]=used[it.second]=true;
	tar=(sum-k)>>1;
	if(tar)
	{
		dfs3(head[goal],0);
		used[resA]=used[resB]=true;
		ans.pb(mkpr(resA,resB));
	}
	int cnt=0;
	for(int i=1;i<=n;++i) if(!used[i]&&i!=rt) sons[bel[i]].pb(i),++cnt;
	++cnt;
	for(int i=1;i<=id;++i) if(SZ(sons[i])) q.push((node){i,SZ(sons[i])}),assert(SZ(sons[i])*2<=cnt);
	sons[0].pb(rt);
	q.push((node){0,1});
	while(!q.empty())
	{
		node x=q.top();q.pop();
		node y=q.top();q.pop();
		--x.val,--y.val;
		ans.pb(mkpr(sons[x.id].back(),sons[y.id].back()));
		sons[x.id].pop_back();
		sons[y.id].pop_back();
		if(x.val) q.push(x);
		if(y.val) q.push(y);
	}
	printf("YES\n");
	for(auto it:ans) printf("%d %d\n",it.first,it.second);
	return 0;
}