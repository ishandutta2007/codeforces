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
const int MAXN = 4e5+10;
int n,cnt,head[MAXN],used[MAXN],a[MAXN],low[MAXN];
struct Edge{int to,next,val;}e[MAXN<<2];
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
inl int id(int u,int type){
	return type?n+u:u; 
}
inl void add(int u,int v,int w){
	e[++cnt]=(Edge){v,head[u],w},head[u]=cnt;
}
inl void spfa(){
	rep(i,1,n<<1) low[i]=1e9;
	queue<int> Q;
	Q.push(0);used[0]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();used[u]=0;
		travel(i,u){
			if(low[e[i].to]>low[u]+e[i].val) {
				low[e[i].to]=low[u]+e[i].val;
				if(!used[e[i].to]) used[e[i].to]=1,Q.push(e[i].to); 
			}
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(a[i]);
	rep(i,1,n){
		add(0,id(i,a[i]&1),0);
		if(i-a[i]>=1) add(id(i-a[i],0),id(i,0),1),add(id(i-a[i],1),id(i,1),1);
		if(i+a[i]<=n) add(id(i+a[i],0),id(i,0),1),add(id(i+a[i],1),id(i,1),1);
	}
	spfa();
	rep(i,1,n) printf("%d ",low[id(i,(a[i]&1)^1)]==1e9?-1:low[id(i,(a[i]&1)^1)]);
	return 0;
}