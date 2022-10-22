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
const int MAXN = 110;
int T,n,a[MAXN]; 
int main(){
	//freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		read(n);
		rep(i,1,n) read(a[i]),a[i]=abs(a[i]);
		int cnt1=0,cnt2=0;
		rep(i,1,n-1) 
			if(a[i+1]-a[i]>0) cnt1++;
			else if(a[i+1]-a[i]<0) cnt2++;
			else  cnt1++,cnt2++;
		rep(i,2,n-1) {
			if(cnt1>=n/2) break;
			if(a[i]-a[i-1]<0 && a[i+1]-a[i]<0) a[i]=-a[i],cnt1++;
		}
		rep(i,2,n-1){
			if(cnt2>=n/2) break;
			if(a[i]-a[i-1]>0 && a[i+1]-a[i]>0) a[i]=-a[i],cnt2++;
		}
		rep(i,1,n) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}