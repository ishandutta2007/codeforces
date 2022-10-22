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
int n,ans,now,a[MAXN],sub[MAXN],pre[MAXN];
template<class T>inl void ylmin(T &a,T b){a=min(a,b);}
template<class T>inl void ylmax(T &a,T b){a=max(a,b);}
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
inl bool check(){
	rep(i,2,n) if(a[i]<=a[i-1]) return false;
	return true;
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(a[i]);
	now=1;
	pre[0]=1;
	rep(i,1,n) {
		if(a[i]<=a[i-1]) now=i;
		pre[i]=now;
	}
	now=n;
	sub[n+1]=n;a[n+1]=2e9;
	per(i,n,1) {
		if(a[i]>=a[i+1]) now=i;
		sub[i]=now;
	}
	rep(i,1,n) if(a[i-1]<a[i+1]) ans=max(ans,(i-1)-pre[i-1]+1+sub[i+1]-(i+1)+1);
	rep(i,1,n) ans=max(ans,i-sub[i]+1),ans=max(ans,i-pre[i]+1);
	printf("%d\n",ans);
	return 0;
}