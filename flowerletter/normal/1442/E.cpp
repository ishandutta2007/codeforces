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
const int MAXN = 2e5 + 10;
const int inf = 1e9;
int t,n,u,v,ans,a[MAXN],dp[MAXN][2];
vector<int> G[MAXN];
inl void dfs(int u,int fa){
	int last0=1,last1=1;
	if(!a[u]){
		dp[u][0]=dp[u][1]=1;
		for(auto v:G[u]){
			if(v==fa) continue;
			dfs(v,u);
			if(!a[v]) 
				ylmax(dp[u][0],min(dp[v][0],dp[v][1]+1)),ylmax(dp[u][1],min(dp[v][0]+1,dp[v][1])),
				ylmax(ans,min(last0+min(dp[v][0],dp[v][1]+1)-1,last1+min(dp[v][0]+1,dp[v][1])-1));
			else if(a[v]==1) 
				ylmax(dp[u][0],dp[v][0]),ylmax(dp[u][1],dp[v][0]+1),
				ylmax(ans,min(last0+dp[v][0]-1,last1+dp[v][0]));
			else 
				ylmax(dp[u][0],dp[v][1]+1),ylmax(dp[u][1],dp[v][1]),
				ylmax(ans,min(last0+dp[v][1],last1+dp[v][1]-1));
			last0=dp[u][0],last1=dp[u][1];
		}
	}
	else if(a[u]==1){
		dp[u][0]=1,dp[u][1]=-inf;
		for(auto v:G[u]){
			if(v==fa) continue;
			dfs(v,u);
			if(!a[v]) ylmax(dp[u][0],min(dp[v][0],dp[v][1]+1)),ylmax(ans,last0+min(dp[v][0],dp[v][1]+1)-1);
			else if(a[v]==1) ylmax(dp[u][0],dp[v][0]),ylmax(ans,last0+dp[v][0]-1);
			else ylmax(dp[u][0],dp[v][1]+1),ylmax(ans,last0+dp[v][1]);
			last0=dp[u][0];
		}
	} 
	else {
		dp[u][0]=-inf,dp[u][1]=1;
		for(auto v:G[u]){
			if(v==fa) continue;
			dfs(v,u);
			if(!a[v]) ylmax(dp[u][1],min(dp[v][0]+1,dp[v][1])),ylmax(ans,last1+min(dp[v][0]+1,dp[v][1])-1);
			else if(a[v]==1) ylmax(dp[u][1],dp[v][0]+1),ylmax(ans,last1+dp[v][0]);
			else ylmax(dp[u][1],dp[v][1]),ylmax(ans,last1+dp[v][1]-1);
			last1=dp[u][1];
		}
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	for(read(t);t;t--){
		read(n);
		rep(i,1,n) read(a[i]);
		rep(i,2,n) read(u),read(v),G[u].push_back(v),G[v].push_back(u);
		dfs(1,1); 
		if(ans&1) cout<<(ans+1)/2<<'\n';
		else cout<<ans/2+1<<'\n';
		rep(i,1,n) G[i].clear(),dp[i][0]=dp[i][1]=0;
		ans=0;
	}
	return 0;
}