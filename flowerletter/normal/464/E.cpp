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
const int Mod = 1e9+7;
const int MAXN = 1e5+100;
int n,m,s,t,u,v,w,cnt,tot,lim,Root[MAXN],head[MAXN],pre[MAXN];ll Pow[MAXN]={1};
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
struct Node{int ls,rs;ll hash;}tree[MAXN*200];
inl bool update(int &root,int pre,int l,int r,int Pos){
	tree[root=++tot]=tree[pre];
	if(l==r) return tree[root].hash=tree[pre].hash^1,tree[pre].hash;
	int ok;
	if(Pos>Mid) ok=update(tree[root].rs,tree[pre].rs,Mid+1,r,Pos); 
	else if(ok=update(tree[root].ls,tree[pre].ls,l,Mid,Pos)) ok=update(tree[root].rs,tree[pre].rs,Mid+1,r,Mid+1);
	tree[root].hash=(tree[tree[root].rs].hash*Pow[Mid-l+1]+tree[tree[root].ls].hash)%Mod;
	return ok;
}
inl bool cmp(int u,int v,int l,int r){
	if(l==r) return tree[u].hash<tree[v].hash;
	return (tree[tree[u].rs].hash==tree[tree[v].rs].hash)?cmp(tree[u].ls,tree[v].ls,l,Mid):cmp(tree[u].rs,tree[v].rs,Mid+1,r);
}
struct NODE{
	int root,id;
	friend inl bool operator < (const NODE x,const NODE y){
		return !cmp(x.root,y.root,0,lim);
	} 
};
inl void dij(){
	priority_queue<NODE> Q;
	rep(i,1,n)Root[i]=-(i!=s); 
	Q.push((NODE){Root[s],s});
	while(!Q.empty()){
		NODE u=Q.top();Q.pop();
		if(u.root!=Root[u.id]) continue;
		travel(i,u.id){
			int New=0;
			update(New,u.root,0,lim,e[i].val);
			if(Root[e[i].to]==-1 || cmp(New,Root[e[i].to],0,lim)) {
				Root[e[i].to]=New,pre[e[i].to]=u.id;
				Q.push((NODE){Root[e[i].to],e[i].to});
			}
		}
	}
}
inl void dfs(int u,int quq){
	if(u==s)return printf("%d\n%d ",quq,u),void();
	dfs(pre[u],quq+1);
	printf("%d ",u);
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,m) read(u),read(v),read(w),add(u,v,w),add(v,u,w),ylmax(lim,w+100);
	read(s),read(t);
	rep(i,1,lim) Pow[i]=(Pow[i-1]<<1)%Mod;
	dij();
	if(Root[t]!=-1) printf("%d\n",tree[Root[t]].hash),dfs(t,1);
	else puts("-1");
	return 0;
}