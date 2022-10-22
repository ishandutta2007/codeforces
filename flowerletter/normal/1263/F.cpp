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
const int MAXN = 5010;
const int inf = 99844853;
int n,p,q,u;
struct Dinic{
	int s,t,cnt=1,head[MAXN],cur[MAXN],dep[MAXN];
	struct Edge{int to,next,val;}e[MAXN<<4];
	inl void add(int u,int v,int w){
		e[++cnt]=(Edge){v,head[u],w},head[u]=cnt;
		e[++cnt]=(Edge){u,head[v],0},head[v]=cnt;
	}
	inl bool bfs(){
		rep(i,1,t) dep[i]=0,cur[i]=head[i];
		queue<int> Q;Q.push(s);dep[s]=1;
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			travel(i,u)	if(!dep[e[i].to] && e[i].val) dep[e[i].to]=dep[u]+1,Q.push(e[i].to);
		}
		return dep[t];
	}
	inl int dfs(int u,int flow){
		if(u==t) return flow;int res=flow;
		for(int &i=cur[u];i;i=e[i].next){
			if(dep[e[i].to]==dep[u]+1 && e[i].val){
				int k=dfs(e[i].to,min(res,e[i].val));
				e[i].val-=k,e[i^1].val+=k,res-=k;
				//if(!res) break;
			}
		}
		//if(flow==res) dep[u]=-1;
		return flow-res;
	}
	inl int dinic(int res=0){
		while(bfs()) res+=dfs(s,inf);
		return res;
	}
}mjy;
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
int main(){
	//freopen("in.txt","r",stdin);
	read(n);
	read(p);rep(i,2,p) read(u),mjy.add(u,i,inf);
	rep(i,1,n) read(u),mjy.add(u,i+p,inf);
	read(q);rep(i,2,q) read(u),mjy.add(i+p+n,u+p+n,inf);
	rep(i,1,n) read(u),mjy.add(i+p,u+p+n,inf);
	mjy.s=n+p+q+1,mjy.t=n+p+q+2;
	rep(i,2,p) mjy.add(mjy.s,i,1); 
	rep(i,2,q) mjy.add(i+p+n,mjy.t,1);
	printf("%d\n",p+q-2-mjy.dinic());
	return 0;
}