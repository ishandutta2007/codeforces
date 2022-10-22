/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
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
const int MAXN = 2010;
int n,cnt,tot,x[MAXN],y[MAXN],c[MAXN],k[MAXN],fa[MAXN];
struct Edge{int u,v;ll w;}e[MAXN*MAXN];
ll ans;
vector<Edge> out;
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
inl ll dis(int i,int j){
	return 1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
}
inl bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
inl int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n)fa[i]=i;
	rep(i,1,n)read(x[i]),read(y[i]);
	rep(i,1,n)read(c[i]),e[++cnt]=(Edge){i,n+1,c[i]};
	rep(i,1,n)read(k[i]);
	rep(i,1,n)rep(j,i+1,n)e[++cnt]=(Edge){i,j,dis(i,j)};
	sort(e+1,e+cnt+1,cmp);
	rep(i,1,cnt){
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v) fa[u]=v,ans+=e[i].w,out.pb(e[i]);
		if(out.size()==n) break;
	}
	printf("%lld\n",ans);
	int du=0;
	for(auto x:out)if(x.v==n+1)du++;
	printf("%d\n",du);
	for(auto x:out)if(x.v==n+1)printf("%d ",x.u);puts("");
	printf("%d\n",n-du);
	for(auto x:out)if(x.v!=n+1)printf("%d %d\n",x.u,x.v);
	return 0;
}