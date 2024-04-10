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
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 1e5+10;
int n,m,u,v,ans,vis[MAXN],fa[MAXN];
vector<int> G[MAXN];
template<class T>inl void ylmin(T &a,T b){a=a<b?a:b;}
template<class T>inl void ylmax(T &a,T b){a=a>b?a:b;}
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
inl int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inl void bfs(int s){
	queue<int> Q;
	Q.push(s);fa[s]=find(s+1);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(auto v:G[u]) vis[v]=u;
		for(int v=find(1);v<=n;v=find(v+1))if(vis[v]!=u) fa[v]=find(v+1),Q.push(v);
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,n+1)fa[i]=i;
	rep(i,1,m)read(u),read(v),G[u].pb(v),G[v].pb(u);
	for(int i=1;i<=n;i=find(i+1)) bfs(i),++ans; 
	printf("%d\n",ans-1);
	return 0;
}