/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
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
const int MAXN = 110;
int n,a[MAXN],b[MAXN];
double f[2][MAXN][MAXN*MAXN*4],*dp[2][MAXN],ans[MAXN];
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(a[i]),read(b[i]);
	rep(i,0,1) rep(j,0,n) dp[i][j]=&f[i][j][2*MAXN*MAXN];
	rep(j,0,n) rep(k,-n*200,200*n) dp[0][j][k]=-1e9;
	dp[0][0][0]=0;
	rep(i,0,n-1) {
		int nw=1^i&1,last=i&1;
		rep(j,0,n) rep(k,-n*200,200*n) dp[nw][j][k]=-1e9;
		rep(j,0,i) {
			rep(k,-i*200,i*200) {
				ylmax(dp[nw][j][k-b[i+1]],dp[last][j][k]+b[i+1]/2.0);
				ylmax(dp[nw][j+1][k+(a[i+1]-b[i+1])*2],dp[last][j][k]+b[i+1]);
			}
		}
	}
	int nw=n&1;
	rep(j,1,n) {
		rep(k,0,n*200) ylmax(ans[j],dp[nw][j][k]);
		rep(k,-n*200,0) ylmax(ans[j],dp[nw][j][k]+k/2.0);
	}
	rep(i,1,n) printf("%.9lf ",ans[i]);
	return 0;
}