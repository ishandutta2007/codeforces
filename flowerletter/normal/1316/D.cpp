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
const int MAXN = 1e3+10;
const int dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
const char Next[4]={'R','D','U','L'};
int n,cnt,head[MAXN*MAXN],vis[MAXN*MAXN];
pii a[MAXN][MAXN];
char s[MAXN][MAXN];
struct Edge{
	int to,next,type;
}e[MAXN*MAXN<<2];
vector<int> root;
inl int id(int x,int y){
	return (x-1)*n+y;
}
inl void add(int u,int v,int type){
	e[++cnt]=(Edge){v,head[u],type},head[u]=cnt;
}
inl void dfs(int u){
	vis[u]=1;
	trv(i,u){
		int v=e[i].to;
		if(vis[v] || s[v%n?(v/n+1):v/n][v%n?v%n:n]=='X') continue;
		s[v%n?(v/n+1):v/n][v%n?v%n:n]=Next[e[i].type];
		dfs(v);
	}
}
int main(){
	read(n);
	rep(i,1,n) rep(j,1,n) read(a[i][j].fir),read(a[i][j].sec);
	rep(i,1,n) rep(j,1,n){
		if(a[i][j].fir==-1 && a[i][j].sec==-1){
			rep(k,0,3) {
				int x=i+dx[k],y=j+dy[k];
				if(a[x][y]==a[i][j]) s[i][j]=Next[k];
			}
		}
		if(i==a[i][j].fir && j==a[i][j].sec) s[i][j]='X',root.pb(id(i,j));
		rep(k,0,3) {
			int x=i+dx[k],y=j+dy[k];
			if(a[x][y]==a[i][j]) add(id(i,j),id(x,y),3-k);
		}
	}
	for(auto x:root) dfs(x);
	rep(i,1,n) rep(j,1,n) if(s[i][j]=='\0') puts("INVALID"),exit(0); 
	puts("VALID");
	rep(i,1,n) {
		rep(j,1,n) putchar(s[i][j]);
		puts("");
	}
	return 0;
}