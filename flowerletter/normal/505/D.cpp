/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
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
const int MAXN = 1e5 + 10;
int n,m,u,v,vis[MAXN],du[MAXN];
vector<int> G[MAXN],H[MAXN];
inl void dfs(int u,vector<int> &S){
	S.push_back(u);vis[u]=1;
	for(auto v:G[u]) if(!vis[v]) dfs(v,S);
}
inl bool topsort(vector<int> S){
	queue<int> Q;int cnt=0;
	for(auto u:S) for(auto v:H[u]) du[v]++;
	for(auto u:S) if(!du[u]) Q.push(u);
	while(!Q.empty()){
		int u=Q.front();Q.pop();cnt++;
		for(auto v:H[u]) if(!(--du[v])) Q.push(v);
	}
	return cnt==size(S);
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,m) read(u),read(v),G[u].push_back(v),G[v].push_back(u),H[u].push_back(v); 
	int ans=n;
	rep(i,1,n){
		if(vis[i]) continue;
		vector<int> S;dfs(i,S);
		ans-=topsort(S);
	}
	printf("%d\n",ans);
	return 0;
}