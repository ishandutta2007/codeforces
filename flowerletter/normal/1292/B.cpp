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
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
ll x0,y0,ax,ay,bx,by,xs,ys,t,ans;
pll p[1000];
template<class T>inl void ylmin(T &a,T b){a=a<b?a:b;}
template<class T>inl void ylmax(T &a,T b){a=a>b?a:b;}
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
inl bool cmp(pll a,pll b){
	return abs(a.fir-xs)+abs(a.sec-ys)<abs(b.fir-xs)+abs(b.sec-ys);
}
int main(){
	//freopen("in.txt","r",stdin);
	read(p[0].fir),read(p[0].sec),read(ax),read(ay),read(bx),read(by);
	read(xs),read(ys),read(t);
	int lim=0;
	rep(i,1,999) {
		p[i]={p[i-1].fir*ax+bx,p[i-1].sec*ay+by};
		if(abs(p[i].fir-xs)+abs(p[i].sec-ys)>t && abs(p[i-1].fir-xs)+abs(p[i].sec-ys)<abs(p[i].fir-xs)+abs(p[i].sec-ys)) {lim=i;break;}
	}
	rep(i,0,lim) rep(j,i,lim){
		ll mx=max({xs,p[j].fir,p[i].fir})-min({xs,p[j].fir,p[i].fir}),my=max({ys,p[j].sec,p[i].sec})-min({ys,p[j].sec,p[i].sec});
		ll dis=mx+my;
		dis+=min(abs(xs-max({xs,p[j].fir,p[i].fir})),abs(xs-min({xs,p[j].fir,p[i].fir})));
		dis+=min(abs(ys-max({ys,p[j].sec,p[i].sec})),abs(ys-min({ys,p[j].sec,p[i].sec})));
		if(dis<0 || dis>t) {ylmax(ans,(ll)j-i);break;}
	}
	printf("%lld\n",ans);
	return 0;
}