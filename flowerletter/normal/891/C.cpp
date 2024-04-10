/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 1e6+10;
int n,m,q,k,u;
vector<pii> quq;
template<class T>inl void ylmin(T &a,T b){a=min(a,b);}
template<class T>inl void ylmax(T &a,T b){a=max(a,b);}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
struct Edge{int u,v,w,id;}e[MAXN];
struct lct{
	#define ls son[u][0]
	#define rs son[u][1]
	int son[MAXN][2],fa[MAXN],rev[MAXN],Max[MAXN],val[MAXN];
	inl bool isroot(int u){return son[fa[u]][0]!=u && son[fa[u]][1]!=u;}
	inl void tagrev(int u){swap(ls,rs);rev[u]^=1;}
	inl void pushup(int u){Max[u]=max({Max[ls],Max[rs],val[u]});}
	inl bool type(int u){return son[fa[u]][1]==u;}
	inl void pushdown(int u){
		if(rev[u]) {
			if(ls) tagrev(ls);
			if(rs) tagrev(rs);
			rev[u]=0;
		}
	}
	inl void rotate(int u){
		int f=fa[u],g=fa[f],k=type(u),s=son[u][!k];
		if(!isroot(f)) son[g][type(f)]=u;son[u][!k]=f,son[f][k]=s;
		if(s) fa[s]=f;fa[f]=u,fa[u]=g;
		pushup(f);
	}
	inl void pushall(int u){if(!isroot(u)) pushall(fa[u]);pushdown(u);}
	inl void splay(int u){
		pushall(u);
		while(!isroot(u)){
			int f=fa[u],g=fa[f];
			if(!isroot(f)) rotate(type(f)^type(u)?u:f);
			rotate(u);
		}
		pushup(u);
	}
	inl void access(int u){for(int s=0;u;u=fa[s=u]) splay(u),rs=s,pushup(u);}
	inl void makeroot(int u){access(u);splay(u);tagrev(u);}
	inl void split(int u,int v){makeroot(u);access(v);splay(v);}
	inl void link(int u,int v){makeroot(u);access(v);splay(v);fa[u]=v;}
	inl void cut(int u,int v){makeroot(u);access(v);splay(v);son[v][type(u)]=fa[u]=0,pushup(v);}
	inl int query(int u,int v){
		makeroot(v),access(u),splay(u);
		while(u && max(Max[ls],Max[rs])==Max[u]) u=Max[ls]>Max[rs]?ls:rs;
		return max(u,n);
	}
	#undef ls
	#undef rs
}mjy;
struct dsu{
	int fa[MAXN];
	inl int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	inl void clear(){rep(i,1,n) fa[i]=i;}
}txdy;
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,m) read(e[i].u),read(e[i].v),read(e[i].w),e[i].id=i+n,mjy.Max[i+n]=mjy.val[i+n]=e[i].w;
	txdy.clear();
	rep(i,1,m){
		int u=txdy.find(e[i].u),v=txdy.find(e[i].v);
		if(u==v) {
			int x=mjy.query(e[i].u,e[i].v)-n;
			if(x && e[x].w>e[i].w) mjy.cut(e[x].u,e[x].id),mjy.cut(e[x].v,e[x].id),mjy.link(e[i].u,e[i].id),mjy.link(e[i].v,e[i].id);
		}
		else txdy.fa[u]=v,mjy.link(e[i].u,e[i].id),mjy.link(e[i].v,e[i].id);
	}
	for(read(q);q;q--){
		int flag=1;
		read(k);quq.clear();
		for(int i=1;i<=k;i++){
			read(u);
			if(!flag) continue;
			int x=mjy.query(e[u].u,e[u].v)-n;
			if(x && e[x].w>=e[u].w){
				quq.pb({e[u].id,mjy.val[e[u].id]});
				if(x!=u){
					mjy.cut(e[x].u,e[x].id),mjy.cut(e[x].v,e[x].id);
					mjy.val[e[u].id]=0;
					mjy.link(e[u].u,e[u].id),mjy.link(e[u].v,e[u].id);
				}else mjy.val[e[u].id]=0,mjy.splay(e[u].id);
			}else flag=0;
		}
		puts(flag?"YES":"NO");
		for(auto x:quq) mjy.val[x.fir]=x.sec,mjy.splay(x.fir);
	}
	return 0;
}