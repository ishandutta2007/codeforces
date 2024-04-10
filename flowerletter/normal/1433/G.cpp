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
const int MAXN = 1010;
int n,m,k,u[MAXN],v[MAXN],w[MAXN],a[MAXN],b[MAXN],used[MAXN],low[MAXN][MAXN];
vector<pii> G[MAXN];
inl void spfa(int s){
	rep(i,1,n) used[i]=0,low[s][i]=1e9;
	queue<int> Q;Q.push(s);low[s][s]=0;used[s]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();used[u]=0;
		for(auto v:G[u]){
			if(low[s][v.fir]>low[s][u]+v.sec){
				low[s][v.fir]=low[s][u]+v.sec;
				if(!used[v.fir]) Q.push(v.fir),used[v.fir]=1;
			}
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(m),read(k);
	memset(low,0x3f,sizeof low);
	rep(i,1,n) low[i][i]=0;
	rep(i,1,m) read(u[i]),read(v[i]),read(w[i]),G[u[i]].pb({v[i],w[i]}),G[v[i]].pb({u[i],w[i]});
	rep(i,1,k) read(a[i]),read(b[i]);
	rep(i,1,n) spfa(i);
	int ans=1e9;
	rep(i,1,m){
		int sum=0;
		rep(j,1,k) sum+=min({low[a[j]][b[j]],low[a[j]][u[i]]+low[v[i]][b[j]],low[a[j]][v[i]]+low[u[i]][b[j]]});
		ylmin(ans,sum);
	}
	cout<<ans<<'\n';
	return 0;
}