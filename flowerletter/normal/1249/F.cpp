/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
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
const int MAXN = 210;
int n,k,u,v,cnt,w[MAXN],dp[MAXN][MAXN],mjy[MAXN],head[MAXN];
struct Edge{int to,next;}e[MAXN<<1];
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
inl void TreeDp(int now,int fa){
	dp[now][0]=w[now];
	travel(i,now){
		if(e[i].to==fa) continue;
		TreeDp(e[i].to,now);
		memcpy(mjy,dp[now],sizeof(mjy));
		dp[now][0]+=dp[e[i].to][k-1];
		rep(j,1,k){
			if(j+j<=k) dp[now][j]=max(mjy[j]+dp[e[i].to][k-j-1],mjy[k-j]+dp[e[i].to][j-1]);
			else dp[now][j]=mjy[j]+dp[e[i].to][j-1];
		}
		per(j,k,0)dp[now][j]=max(dp[now][j+1],dp[now][j]);
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(k);k++; 
	rep(i,1,n)read(w[i]);
	rep(i,2,n)read(u),read(v),add(u,v),add(v,u);
	TreeDp(1,1);
	printf("%d\n",dp[1][0]);
	return 0;
}