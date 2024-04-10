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
const int MAXN = 2e6+10;
ll n,r1,r2,r3,d,a[MAXN],k1[MAXN],k2[MAXN],dp[MAXN];
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(r1),read(r2),read(r3),read(d);
	rep(i,1,n) read(a[i]),k1[i]=min(r2+r1,r1*(a[i]+2)),k2[i]=r1*a[i]+r3;
	dp[1]=k2[1];
	rep(i,2,n) {
		dp[i]=min(dp[i-2]+4*d-(i==2?d:0)+k1[i]+k1[i-1],dp[i-1]+d+k2[i]);
	}
	ll ans=dp[n],sum=min(k2[n],k1[n]+2*d);
	per(i,n-2,1) {
		sum+=k1[i+1];
		ylmin(ans,dp[i]+2*(n-i-1)*d+d+sum);
	}
	printf("%lld\n",min(ans,2*(n-1)*d+sum+k1[1]));
	return 0;
}