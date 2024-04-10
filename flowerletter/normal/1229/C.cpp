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
#define mp make_pair
#define inl inline
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define mymax(a,b) ((a)<(b)?a=b,1:0)
#define mymin(a,b) ((a)>(b)?a=b,1:0)
#define lson root<<1
#define rson root<<1|1
#define mst0(x) memset(x,0,sizeof(x))
#define debug(x) printf(#x":%d\n",x)
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
const int MAXN = 1e5+10;
int n,m,q,u,v,du[MAXN];
ll ans;
vector<int> G[MAXN];
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
inl ll Get(int x){
	return 1ll*G[x].size()*(du[x]-G[x].size());
}
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(m);
	for(int i=1;i<=m;i++)read(u),read(v),G[min(u,v)].pb(max(u,v)),du[u]++,du[v]++;
	for(int i=1;i<=n;i++)ans+=Get(i);printf("%lld\n",ans);
	for(read(q);q;q--){
		read(u),ans-=Get(u);
		for(int to:G[u])ans-=Get(to),G[to].pb(u),ans+=Get(to);
		G[u].clear(),printf("%lld\n",ans);
	}
	return 0;
}