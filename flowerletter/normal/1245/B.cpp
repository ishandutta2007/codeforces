/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
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
const int MAXN = 110;
int T,n,a,b,c;
char s[MAXN],ans[MAXN];
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
int main(){
//	freopen("in.txt","r",stdin);
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s+1);
		int cnt=0;
		rep(i,1,n){
			if(s[i]=='P' && c) c--,cnt++,ans[i]='S';
			else if(s[i]=='R' && b) b--,cnt++,ans[i]='P';
			else if(s[i]=='S' && a) a--,cnt++,ans[i]='R';
			else ans[i]='#';
		}
		if(cnt>=(n+1)/2) {
			puts("Yes");
			rep(i,1,n)if(ans[i]=='#' && a) ans[i]='R',a--;else if(ans[i]=='#' && b)ans[i]='P',b--;else if(ans[i]=='#' && c)ans[i]='S',c--;
			rep(i,1,n)putchar(ans[i]);puts("");
		}else puts("No");
	}
	return 0;
}