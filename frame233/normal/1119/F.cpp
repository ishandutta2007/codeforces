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

const int N=250005;
const ll LIMIT=250000000000ll;
struct seg_tr{
	struct Node{
		int ls,rs,siz;
		ll sum;
	}f[N*25];
	int node_cnt;
	int st[N*25],top;
	Finline void pushup(int x)
	{
		f[x].siz=f[f[x].ls].siz+f[f[x].rs].siz;
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
	}
	void Update(int &cur,ll pos,int C,ll l,ll r)
	{
		if(!cur) cur=top?st[top--]:++node_cnt;
		if(l==r)
		{
			f[cur].siz+=C;
			f[cur].sum+=l*C;
			return;
		}
		ll mid=(l+r)>>1;
		if(pos<=mid) Update(f[cur].ls,pos,C,l,mid);
		else Update(f[cur].rs,pos,C,mid+1,r);
		pushup(cur);
		if(!f[cur].siz)
		{
			st[++top]=cur;
			f[cur].ls=f[cur].rs=0;
			cur=0;
		}
	}
	void del(int &cur)
	{
		if(!cur) return;
		del(f[cur].ls),del(f[cur].rs);
		st[++top]=cur;
		f[cur].ls=f[cur].rs=f[cur].siz=f[cur].sum=0;
		cur=0;
	}
	ll Query(int k,ll l,ll r,int cur)
	{
		if(!k) return 0ll;
		if(l==r) return 1ll*k*l;
		ll mid=(l+r)>>1;
		if(k>f[f[cur].ls].siz) return f[f[cur].ls].sum+Query(k-f[f[cur].ls].siz,mid+1,r,f[cur].rs);
		return Query(k,l,mid,f[cur].ls);
	}
}tr;
int root[N],limit;
struct edge{
	int v,w;
	Finline bool operator < (const edge &o)const
	{
		return v==o.v?w<o.w:v<o.v;
	}
};
std::set<edge> e[N];
int dg[N],vis[N];
std::vector<int> nd[N];
ll dp[N][2];
void dfs(int x,int fa,ll fa_val)
{
	vis[x]=limit;
	int cnt=dg[x];
	ll sum=0;
	for(auto it:e[x]) if(it.v!=fa) dfs(it.v,x,it.w);
	for(auto it:e[x])
	{
		int v=it.v;
		if(v==fa) continue;
		if(dp[v][1]<=dp[v][0])
		{
			--cnt;
			sum+=dp[v][1];
		}
		else
		{
			sum+=dp[v][0];
			if(dp[v][1]-dp[v][0]<=LIMIT) tr.Update(root[x],dp[v][1]-dp[v][0],1,0,LIMIT);
		}
	}
	if(cnt<=limit)
	{
		dp[x][0]=sum;
		dp[x][1]=sum+fa_val;
	}
	else
	{
		dp[x][0]=sum+(cnt-limit<=tr.f[root[x]].siz?tr.Query(cnt-limit,0,LIMIT,root[x]):INF);
		dp[x][1]=sum+(cnt-limit-1<=tr.f[root[x]].siz?tr.Query(cnt-limit-1,0,LIMIT,root[x]):INF)+fa_val;
	}
	for(auto it:e[x]) if(it.v!=fa&&dp[it.v][1]>dp[it.v][0]&&dp[it.v][1]-dp[it.v][0]<=LIMIT) tr.Update(root[x],dp[it.v][1]-dp[it.v][0],-1,0,LIMIT);
}
int main()
{
	int n;read(n);
	int x,y,z;
	for(int i=1;i<n;++i)
	{
		read(x,y,z);
		e[x].insert((edge){y,z});
		e[y].insert((edge){x,z});
		++dg[x],++dg[y];
	}
	for(int i=1;i<=n;++i) nd[dg[i]].pb(i);
	memset(vis,255,sizeof(vis));
	std::set<int> rest;
	for(int i=1;i<=n;++i) rest.insert(i);
	for(int d=0;d<n;++d)
	{
		limit=d;
		for(auto x:nd[d])
		{
			rest.erase(x);
			for(auto it:e[x])
			{
				tr.Update(root[it.v],it.w,1,0,LIMIT);
				e[it.v].erase((edge){x,it.w});
			}
			e[x].clear();
			tr.del(root[x]);
		}
		ll ans=0;
		for(auto it:rest) if(vis[it]!=limit) dfs(it,0,INF),ans+=dp[it][0];
		printf("%lld%c",ans," \n"[d+1==n]);
	}
	return 0;
}