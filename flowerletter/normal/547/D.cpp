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
#define travel(i,u) for(int &i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 2e5+10;
int n,m,u,v,last,ans[MAXN],used[MAXN<<1];
vector<pii> G[MAXN<<1];
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
inl void eular(int u){
	while(size(G[u])){
		pii mjy=G[u].back();G[u].pop_back();
		if(used[mjy.sec]) continue;
		used[mjy.sec]=1;
		if(mjy.sec<=n) ans[mjy.sec]=mjy.fir>MAXN;
		eular(mjy.fir);
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(u),read(v),G[u].pb({v+MAXN,++m}),G[v+MAXN].pb({u,m});
	rep(i,1,(MAXN<<1)-1)
		if(size(G[i])&1){
			if(last) G[last].pb({i,++m}),G[i].pb({last,m}),last=0;
			else last=i;
		}
	rep(i,1,(MAXN<<1)-1) eular(i);
	rep(i,1,n) putchar(ans[i]?'r':'b');
	return 0;
}