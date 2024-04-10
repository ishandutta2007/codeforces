#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 100005
int n,m;
vector<int>e[maxn];
vector<int>res;

int sz[maxn],mxp[maxn],rt;
void getrt(int u,int pa)
{
	sz[u]=1;
	for(auto v:e[u]){
		if(v==pa)continue;
		getrt(v,u),sz[u]+=sz[v],mxp[u]=max(mxp[u],sz[v]);
	}mxp[u]=max(mxp[u],n-sz[u]);
	if(mxp[rt]>mxp[u])rt=u;
}

int deg[maxn],dep[maxn],fa[maxn],top[maxn];
set<pii>s,S[maxn];
void dfs(int u,int pa,int tp)
{
	top[u]=tp; fa[u]=pa;
	if(tp&&(int)e[u].size()>=2) 
		S[tp].insert(mkp(dep[u],u));
	for(auto v:e[u]){
		if(v==pa)continue;
		dep[v]=dep[u]+1,deg[u]++,fa[v]=u;
		dfs(v,u,tp);
	}
}
bool vis[maxn];
inline void del(int x){
	vis[x]=1;
	deg[fa[x]]--;
	if(!deg[fa[x]]) S[top[x]].erase(mkp(dep[fa[x]],fa[x]));
}

void getrest(int u)
{
	if(!vis[u])res.pb(u);
	for(auto v:e[u]) if(v!=fa[u]) getrest(v);
}

signed main()
{
	n=read(),m=read();
	For(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	mxp[rt=0]=n+1,getrt(1,0),getrt(rt,0);
	int mx=0,mn=0;
	For(i,1,n) if(i!=rt) mx+=sz[i],mn+=(sz[i]&1);
	if(m>mx||m<mn||(mx-m)%2!=0)return puts("NO")&0;
	
	puts("YES");
	
	int k=mx-m;
	for(auto v:e[rt]) if(sz[v]>1) s.insert(mkp(sz[v],v));
	for(auto v:e[rt]) dep[v]=1,dfs(v,rt,v);
//	cout<<"K "<<k<<endl;
	while(k)
	{
		int u=(--s.end())->se; s.erase(--s.end());
		int x=(--S[u].end())->se;
		vector<int>o;
		if(2*dep[x]>k){
			x=(S[u].lower_bound(mkp(k/2,0)))->se;
			for(auto v:e[x])
				if(v!=fa[x] && !vis[v]) o.pb(v);
			if(o.size()<2)o.pb(x);
			cout<<o[0]<<' '<<o[1]<<endl;
			vis[o[0]]=vis[o[1]]=1;
			break;
		}
		for(auto v:e[x])
			if(v!=fa[x] && !vis[v]) o.pb(v);
		if(o.size()<2)o.pb(x);
		
		cout<<o[0]<<' '<<o[1]<<endl;
	//	cout<<"nowk "<<k-dep[x]*2<<endl;
		del(o[0]),del(o[1]);
		
		sz[u]-=2; k-=dep[x]*2;
		if(sz[u]>1)	s.insert(mkp(sz[u],u));
	}
	
	getrest(rt);
//	cout<<"siz "<<res.size()<<endl;
	for(int i=0;i<res.size()/2;++i)
		cout<<res[i]<<' '<<res[i+(res.size()/2)]<<endl;
	return 0;
}