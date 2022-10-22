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
const int MAXM = 1e6 + 10;
int T,x,p,k;
int tot,prim[MAXM],mu[MAXM],vis[MAXM];
inl ll calc(ll n,int p){
	ll num=0;
	rep(i,1,sqrt(p)){
		if(p%i==0){
			num+=1ll*mu[i]*(n/i);
			if(i*i!=p) num+=1ll*mu[p/i]*(n/(p/i));
		}
	}
	return num;
}
inl void init(){
	mu[1]=1;
	rep(i,2,1e6){
		if(!vis[i]) prim[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot && i*prim[j]<=1e6;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0) break;
			mu[i*prim[j]]=-mu[i];
		}
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	init();
	for(read(T);T;T--){
		read(x),read(p),read(k);
		int nw=calc(x,p);
		ll l=x,r=1e9,ans=-1;
		while(l<=r) {
			ll mid=l+r>>1;
			if(calc(mid,p)-nw>=k) ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
rep(i,1,n) [gcd(i,p)==1]
rep(i,1,n) rep(d|i && d|p) mu[d]
rep(d|p) mu[d]*[n/d];
*/