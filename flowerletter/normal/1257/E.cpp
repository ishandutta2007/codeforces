/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
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
const int MAXN = 2e5+10;
const int inf = 1<<29;
int k1,k2,k3,n,type[MAXN],dp[MAXN][3],a[MAXN],b[MAXN],c[MAXN];
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
inl void upd(int &a,int b){a=a<b?a:b;}
int main(){
//	freopen("in.txt","r",stdin);
	read(k1),read(k2),read(k3);n=k1+k2+k3;
	rep(i,1,k1)read(a[i]),type[a[i]]=0;
	rep(i,1,k2)read(a[i]),type[a[i]]=1;
	rep(i,1,k3)read(a[i]),type[a[i]]=2;
	rep(i,1,n){
		dp[i][0]=dp[i][1]=dp[i][2]=inf;
		upd(dp[i][0],dp[i-1][0]+(type[i]!=0));
		upd(dp[i][1],dp[i-1][0]+(type[i]!=1));
		upd(dp[i][1],dp[i-1][1]+(type[i]!=1));
		upd(dp[i][2],dp[i-1][0]+(type[i]!=2));
		upd(dp[i][2],dp[i-1][1]+(type[i]!=2));
		upd(dp[i][2],dp[i-1][2]+(type[i]!=2));
	}printf("%d\n",min(min(dp[n][0],dp[n][1]),dp[n][2]));
	return 0;
}