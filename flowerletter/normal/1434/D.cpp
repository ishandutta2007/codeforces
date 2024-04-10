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
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
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
const int MAXN = 5e5 + 10;
const int Size = 2e6 + 10;
int n,m,u[MAXN],v[MAXN],w[MAXN];
vector<pii> G[MAXN];
struct Seg{
	#define ls rt<<1
	#define rs rt<<1|1
	int id[Size],rev[Size],type[Size],dep[Size],fa[Size],size[Size],dfs_time;
	int tag[Size],max0[Size],max1[Size];
	inl void dfs(int u,int f){
		rev[id[u]=++dfs_time]=u;
		size[u]=1;dep[u]=dep[fa[u]=f]+1;
		for(auto v:G[u]){
			if(v.fir==f) continue;
			type[v.fir]=type[u]^v.sec;
			dfs(v.fir,u);
			size[u]+=size[v.fir];
		}
	}
	inl void pushdown(int rt){
		if(tag[rt]){
			tag[ls]^=1;tag[rs]^=1;
			swap(max0[ls],max1[ls]);
			swap(max0[rs],max1[rs]);
			tag[rt]=0;
		}
	}
	inl void pushup(int rt){
		max0[rt]=max(max0[ls],max0[rs]);
		max1[rt]=max(max1[ls],max1[rs]);
	}
	inl void update(int rt,int l,int r,int L,int R){
		if(l>=L && r<= R){
			tag[rt]^=1;
			swap(max0[rt],max1[rt]);
			return ;
		}
		pushdown(rt);
		int mid=l+r>>1;
		if(R<=mid) update(ls,l,mid,L,R);
		else if(L>mid) update(rs,mid+1,r,L,R);
		else update(ls,l,mid,L,R),update(rs,mid+1,r,L,R);
		pushup(rt);
	}
	inl void build(int rt,int l,int r){
		if(l==r) {
			if(type[rev[l]]) max1[rt]=dep[rev[l]];
			else max0[rt]=dep[rev[l]];
			return ;
		}
		int mid=l+r>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(rt);
	}
	inl void update(int u,int v){
		if(fa[v]==u) swap(u,v);
		update(1,1,n,id[u],id[u]+size[u]-1);
	}
}mjy1,mjy2;
struct Tree{
	int ans1,ans2,dep[MAXN];
	inl void dfs(int u,int fa){
		dep[u]=dep[fa]+1;
		for(auto v:G[u]) {
			if(v.fir==fa) continue;
			dfs(v.fir,u);
		}
	}
	inl void work(){
		int Maxdep=0,pos=0;
		dfs(1,0);
		rep(i,1,n) if(ylmax(Maxdep,dep[i])) pos=i;
		ans1=pos;
		Maxdep=0,pos=0;
		dfs(ans1,0);
		rep(i,1,n) if(ylmax(Maxdep,dep[i])) pos=i;
		ans2=pos;
	}
}mjy;
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n-1) read(u[i]),read(v[i]),read(w[i]),G[u[i]].pb({v[i],w[i]}),G[v[i]].pb({u[i],w[i]});
	mjy.work();
	mjy1.dfs(mjy.ans1,0);mjy1.build(1,1,n);
	mjy2.dfs(mjy.ans2,0);mjy2.build(1,1,n);
	for(read(m);m;m--){
		int nw;
		read(nw);
		mjy1.update(u[nw],v[nw]);
		mjy2.update(u[nw],v[nw]);
		printf("%d\n",max(mjy1.max0[1],mjy2.max0[1])-1);
	}
	return 0;
}