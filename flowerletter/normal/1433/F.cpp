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
const int MAXN = 80;
int n,m,k,a[MAXN][MAXN],dp[MAXN][MAXN][MAXN/2][MAXN];
int main(){
//	freopen("in.txt","r",stdin);
	read(n);read(m);read(k);
	rep(i,1,n) rep(j,1,m) read(a[i][j]);
	memset(dp,-0x3f,sizeof dp);
	dp[0][m][0][0]=0;
	rep(i,1,n) {
		rep(j,0,m/2) rep(l,0,k-1) ylmax(dp[i][0][0][l],dp[i-1][m][j][l]);
		rep(j,1,m){
			rep(l,0,min(j,m/2)) {
				rep(o,0,k-1) {
					dp[i][j][l][o]=max(dp[i][j-1][l-1][(o-a[i][j]%k+k)%k]+a[i][j],dp[i][j-1][l][o]);
				}
			}
		}
	} 
	int ans=0;
	rep(i,0,m/2) ylmax(ans,dp[n][m][i][0]);
	cout<<ans<<'\n';
	return 0;
}