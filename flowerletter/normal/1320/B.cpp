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
const int MAXN = 2e5+10;
int n,m,cnt,k,u,v,p[MAXN],dis[MAXN],head[MAXN];
vector<int> pre[MAXN];
struct Edge{
	int to,next;
}e[MAXN];
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

inl void add(int u,int v){
	e[++cnt]=(Edge){v,head[u]},head[u]=cnt;
}
inl void bfs(int s){
	queue<int> Q;dis[s]=1;Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		trv(i,u){
			int v=e[i].to;
			if(!dis[v]) pre[v].pb(u),dis[v]=dis[u]+1,Q.push(v);
			else if(dis[v]==dis[u]+1) pre[v].pb(u);
		}
	}
}
inl bool find(vector<int> s,int x){
	return lower_bound(all(s),x)!=s.end() && *lower_bound(all(s),x)==x;
}
int main(){
	read(n),read(m);
	rep(i,1,m) read(u),read(v),add(v,u);
	read(k);
	rep(i,1,k) read(p[i]);
	bfs(p[k]);
	rep(i,1,n) sort(all(pre[i]));
	int Min=0,Max=0;
	rep(i,1,k-1){
		if(!find(pre[p[i]],p[i+1])) Min++,Max++;
		else if(size(pre[p[i]])>1) Max++;
	}
	printf("%d %d\n",Min,Max);
	return 0;
}