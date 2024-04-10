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
const int MAXN = 1e5+10;
struct Node{
	int a,c[8];
}a[MAXN];
int n,p,k;
ll ans,dp[2][1<<7][8],f[MAXN][1<<7];
inl bool cmp(Node a,Node b){return a.a>b.a;}
int main(){
	read(n),read(p),read(k);
	rep(i,1,n) read(a[i].a);
	rep(i,1,n) rep(j,1,p) read(a[i].c[j]);
	sort(a+1,a+n+1,cmp);
	rep(i,0,1) rep(s,0,(1<<p)-1) rep(j,0,p) dp[i][s][j]=-1e18;
	rep(i,0,n) rep(s,0,(1<<p)-1) f[i][s]=-1e18;
	dp[0][0][0]=0,f[p+k][0]=0;
	rep(i,1,p+k){
		rep(s,0,(1<<p)-1){
			rep(j,0,p-__builtin_popcount(s)){
				//dp[i][s][p]=-1e18;
				//
				rep(k,1,p) if((s>>k-1)&1) ylmax(dp[i&1][s][j],dp[!(i&1)][s^(1<<k-1)][j]+a[i].c[k]);
				//
				if(j) ylmax(dp[i&1][s][j],dp[!(i&1)][s][j-1]);
				//
				ylmax(dp[i&1][s][j],dp[!(i&1)][s][j]+a[i].a); 
			}
		}
	}
	rep(i,p+k+1,n){
		rep(s,0,(1<<p)-1){
			f[i][s]=f[i-1][s];
			rep(j,1,p) if((s>>j-1)&1) ylmax(f[i][s],f[i-1][s^(1<<j-1)]+a[i].c[j]);
		}
	}
	rep(s,0,(1<<p)-1){
		ylmax(ans,dp[(p+k)&1][s][p-__builtin_popcount(s)]+f[n][((1<<p)-1)^s]);
	} 
	cout<<ans;
	return 0;
}