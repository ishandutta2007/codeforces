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
const int MAXN = 1e5 + 10;
const ll inf = 1e18;
int n,q,u,v,w,x,y,fa[MAXN],id[MAXN];
ll lim,dis[MAXN][2];
struct Edge{
	int to,next,w;
}e[MAXN<<1];
int head[MAXN],cnt;
inl void add(int u,int v,int w){
	e[++cnt]=(Edge){v,head[u],w},head[u]=cnt;
	e[++cnt]=(Edge){u,head[v],w},head[v]=cnt;
}
namespace findmaxlen{
	int ans1,ans2,Maxpos;
	ll dep[MAXN],Max;
	inl void dfs(int u,int fa){
		trv(i,u){
			int v=e[i].to;
			if(v==fa) continue;
			dep[v]=dep[u]+e[i].w;
			dfs(v,u);
		}
	}
	inl void work(){
		memset(dep,0,sizeof dep);
		dfs(1,1);
		Max=Maxpos=0;
		rep(i,1,n) if(ylmax(Max,dep[i])) Maxpos=i;
		ans1=Maxpos;
		memset(dep,0,sizeof dep);
		dfs(ans1,ans1);
		Max=Maxpos=0;
		rep(i,1,n) if(ylmax(Max,dep[i])) Maxpos=i;
		ans2=Maxpos;
	}
}
inl void getdis(int u,int fa,int type){
	trv(i,u){
		int v=e[i].to;
		if(v==fa) continue;
		dis[v][type]=dis[u][type]+e[i].w;
		getdis(v,u,type);
	}
}
inl void dfs(int u,int father){
	fa[u]=father;
	trv(i,u) {
		int v=e[i].to;
		if(v==father) continue;
		dfs(v,u);
	}
}
inl ll val(int u){
	return max(dis[u][0],dis[u][1]);
}
inl bool cmp(int a,int b){
	return val(a)<val(b) || (val(a)==val(b) && a>b);
}
namespace ufs{
	int fa[MAXN],size[MAXN];
	inl void clear(){
		rep(i,1,n) fa[i]=i,size[i]=1;
	}
	inl int find(int u){
		return fa[u]==u?u:fa[u]=find(fa[u]);
	}
	inl void merge(int u,int v){
		u=find(u),v=find(v);
		if(size[u]>size[v]) swap(u,v);
		fa[u]=v,size[v]+=size[u];
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,2,n) read(u),read(v),read(w),add(u,v,w);
	findmaxlen::work();
	x=findmaxlen::ans1,y=findmaxlen::ans2;
	getdis(x,x,0),getdis(y,y,1);
	ll Min=inf;int Minpos=0;
	rep(i,1,n) if(ylmin(Min,val(i))) Minpos=i;
	dfs(Minpos,Minpos);
	rep(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(read(q);q;q--){
		read(lim);
		ufs::clear();
		int ans=0;
		for(int l=n,r=n;l;l--){
			while(val(id[r])>val(id[l])+lim) ufs::size[ufs::find(id[r])]--,r--;
			ylmax(ans,ufs::size[ufs::find(id[l])]);
			ufs::merge(id[l],fa[id[l]]);
		}
		printf("%d\n",ans);
	}
	return 0;
}