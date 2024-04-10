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
int n,k,dfs_time,cnt,sum,p[MAXN],q[MAXN],head[MAXN],dfn[MAXN],low[MAXN],color[MAXN];
int tot,ans[MAXN],du[MAXN],mat[MAXN],dep[MAXN];
stack<int> S;
queue<int> Q;
vector<int> rev[MAXN],G[MAXN];
struct Edge{int to,next;}e[MAXN<<1];
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
inl void Tarjan(int now){
	dfn[now]=low[now]=++dfs_time;
	S.push(now);
	travel(i,now){
		if(!dfn[e[i].to]) Tarjan(e[i].to),ylmin(low[now],low[e[i].to]);
		else if(!color[e[i].to]) ylmin(low[now],dfn[e[i].to]);
	}
	if(dfn[now]==low[now]){
		color[now]=++sum;rev[sum].pb(now);
		while(S.top()!=now){
			color[S.top()]=sum;
			rev[sum].pb(S.top());
			S.pop();
		}S.pop();
	}
}
inl void add(int u,int v){e[++cnt]={v,head[u]};head[u]=cnt;}
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(k);
	rep(i,1,n) read(p[i]);
	rep(i,1,n) read(q[i]);
	rep(i,1,n-1) add(p[i],p[i+1]);
	rep(i,1,n-1) add(q[i],q[i+1]);
	rep(i,1,n) if(!dfn[i]) Tarjan(i);
	rep(i,k+1,sum) for(auto quq:rev[i]) color[quq]=k;
	rep(i,1,n) travel(j,i) if(color[i]!=color[e[j].to]) G[color[i]].pb(color[e[j].to]);
	rep(i,1,sum) sort(all(G[i])),G[i].erase(unique(all(G[i])),G[i].end());
	rep(i,1,sum) for(auto quq:G[i]) du[quq]++;
	rep(i,1,sum) if(!du[i]) Q.push(i); 
	rep(i,1,sum) dep[i]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(auto quq:G[u]) {
			ylmax(dep[quq],dep[u]+1);
			if(!(--du[quq])) Q.push(quq);
		}
	}
	int Max=0;
	rep(i,1,sum) ylmax(Max,dep[i]);
	if(Max<k) puts("NO"),exit(0);
	puts("YES");
	rep(i,1,n) putchar(min(dep[color[i]],k)+'a'-1);
	return 0;
}