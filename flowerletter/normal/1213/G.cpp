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
const int MAXN = 2e5+10;
struct Edge{int u,v,w;}e[MAXN]; 
int n,m,u,v,w,size[MAXN],fa[MAXN];
ll now,ans[MAXN];
vector<pii> G[MAXN];
template<class T>inl void ylmin(T &a,T b){a=a<b?a:b;}
template<class T>inl void ylmax(T &a,T b){a=a>b?a:b;}
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
inl bool cmp(Edge a,Edge b){return a.w<b.w;}
inl int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
inl ll cacl(ll x){return x*(x-1)/2;}
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,n) fa[i]=i,size[i]=1;
	rep(i,1,n-1) read(u),read(v),read(w),e[i]={u,v,w};
	sort(e+1,e+n,cmp);
	rep(i,1,n-1){
		now-=cacl(size[find(e[i].u)]),now-=cacl(size[find(e[i].v)]);
		now+=cacl(size[find(e[i].u)]+size[find(e[i].v)]);
		ans[e[i].w]=now;
		size[find(e[i].u)]+=size[find(e[i].v)];
		fa[find(e[i].v)]=find(e[i].u);
	}
	rep(i,1,2e5) if(!ans[i]) ans[i]=ans[i-1];
	rep(i,1,m) read(u),printf("%lld ",ans[u]);
	return 0;
}