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
const int MAXN = 1e5+10;
const int LOG = 60;
ll T,n,m,a[MAXN],cnt[LOG+10];
int main(){
	for(read(T);T;T--){
		rep(i,0,LOG) cnt[i]=0;
		ll ans=0,sum=0;
		read(n),read(m);
		rep(i,1,m) read(a[i]),sum+=a[i],a[i]=log2(a[i]),cnt[a[i]]++;
		if(sum<n) {puts("-1");continue;}
		rep(i,0,LOG){
			if(i) cnt[i]+=(cnt[i-1]>>1);
			if((n>>i)&1){
				if(!cnt[i]) {
					int pos=-1;
					rep(j,i+1,LOG) if(cnt[j]){pos=j;break;}
					cnt[pos]--;
					rep(j,i,pos-1) cnt[j]++;
					ans+=pos-i;
				}
				else cnt[i]--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}