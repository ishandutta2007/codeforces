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
const int Mod = 1e9+7;
int n,u,v;
ll ans,a[MAXN];
vector<int> G[MAXN]; 
vector<pli> Set[MAXN];
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
inl ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
inl void dfs(int now,int fa){
	vector<pli> tmp;
	for(pli g:Set[fa]) tmp.pb(mp(gcd(g.fir,a[now]),g.sec));tmp.pb(mp(a[now],1));
	for(int i=1;i<tmp.size();i++)if(tmp[i].fir==tmp[i-1].fir) tmp[i].sec+=tmp[i-1].sec,tmp[i-1].sec=0;
	for(pli g:tmp)if(g.sec!=0) Set[now].pb(g),ans+=g.fir*g.sec%Mod,ans%=Mod; 
	for(int to:G[now])if(to!=fa)dfs(to,now);
}
int main(){
	//freopen("in.txt","r",stdin);
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<n;i++)read(u),read(v),G[u].pb(v),G[v].pb(u);
	dfs(1,1),printf("%d\n",ans);
	return 0;
}