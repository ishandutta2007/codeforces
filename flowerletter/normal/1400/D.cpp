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
const int MAXN = 3010;
int T,n,a[MAXN],cnt[MAXN][MAXN];
ll sum[MAXN][MAXN];
inl ll get(int l,int r){
	if(l>r) return 0;
	return sum[r][r]-sum[l-1][r]-sum[r][l-1]+sum[l-1][l-1];
}
int main(){
	//freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		read(n);
		rep(i,1,n)read(a[i]);
		ll ans=0;
		rep(i,1,n) rep(j,i+1,n) cnt[i][j]=(a[i]==a[j]);
		rep(i,1,n) rep(j,1,n) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+cnt[i][j];
		rep(i,1,n) rep(j,i+1,n) if(cnt[i][j]) ans+=sum[i-1][j-1]-sum[i-1][i];
		printf("%lld\n",ans);
	}
	return 0;
}