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
const int MAXN = 6e5+10;
int T,k,u,v,w,cnt,head[MAXN],size[MAXN],dep[MAXN];
pair<pii,int> E[MAXN];
struct Edge{int to,next,val;}e[MAXN<<1];
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
inl void add(int u,int v,int w){
	e[++cnt]=(Edge){v,head[u],w},head[u]=cnt;
}
inl void dfs(int u,int fa){
	size[u]=1;dep[u]=dep[fa]+1;
	travel(i,u){
		if(e[i].to==fa) continue;
		dfs(e[i].to,u);
		size[u]+=size[e[i].to];
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		read(k);
		cnt=0;
		rep(i,1,k<<1) head[i]=0,size[i]=0;
		rep(i,2,k<<1) read(u),read(v),read(w),add(u,v,w),add(v,u,w),E[i]={{u,v},w};
		dfs(1,0);
		ll G=0,B=0;
		rep(i,2,k<<1) {
			if(dep[E[i].fir.sec]<dep[E[i].fir.fir]) swap(E[i].fir.fir,E[i].fir.sec);
			if(size[E[i].fir.sec]&1) G+=E[i].sec;
			B+=1ll*min(size[E[i].fir.sec],(k<<1)-size[E[i].fir.sec])*E[i].sec;
		}
		printf("%lld %lld\n",G,B);
	}
	return 0;
}