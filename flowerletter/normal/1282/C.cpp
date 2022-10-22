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
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 2e5+10;
template<class T>inl void ylmin(T &a,T b){a=min(a,b);}
template<class T>inl void ylmax(T &a,T b){a=max(a,b);}
int T,n,m,a,b,ans,alla,allb,cnta,cntb;
pil t[MAXN];
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
inl bool cmp(pil a,pil b){
	return a.sec==b.sec?a.fir<b.fir:a.sec<b.sec;
}
int main(){
//	freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		ans=0;alla=allb=cnta=cntb=0;
		read(n),read(m),read(a),read(b);
		rep(i,1,n) read(t[i].fir),t[i].fir=(t[i].fir?b:a),alla+=t[i].fir==a,allb+=t[i].fir==b;
		rep(i,1,n) read(t[i].sec);
		sort(t+1,t+n+1,cmp);
		t[n+1].sec=m+1;
		rep(i,0,n) {
			if(i) cnta+=t[i].fir==a,cntb+=t[i].fir==b;
			if(i) t[i].fir+=t[i-1].fir;
			if(t[i].fir>m) break;
			if(t[i].fir<t[i+1].sec){
				int tmp=t[i+1].sec-1-t[i].fir;
				if(tmp>(alla-cnta)*a) ylmax(ans,i+alla-cnta+min((tmp-(alla-cnta)*a)/b,allb-cntb));
				else ylmax(ans,i+tmp/a);
			}
		}
		printf("%d\n",ans); 
	}
	return 0;
}