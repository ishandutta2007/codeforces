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
const int MAXN = 1e5 + 10;
int n,m,k,p,a[MAXN],h[MAXN],c[MAXN];
inl bool check(ll x){
	rep(i,1,n) c[i]=0;
	priority_queue<pii,vector<pii>,greater<pii>> Q;
	rep(i,1,n) if(x-1ll*m*a[i]<h[i]) Q.push({x/a[i],i});
	rep(i,1,m) rep(j,1,k){
		if(Q.empty()) return true;
		pii u=Q.top();Q.pop();
		if(u.fir<i) return false;
		if(x-1ll*m*a[u.sec]+1ll*(++c[u.sec])*p<h[u.sec]) Q.push({(x+1ll*c[u.sec]*p)/a[u.sec],u.sec});
	}
	return Q.empty();
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m),read(k),read(p);
	rep(i,1,n) read(h[i]),read(a[i]);
	ll l=1,r=1e9*(m+1),ans;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}