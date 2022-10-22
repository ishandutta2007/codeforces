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
const int MAXN = 1010;
int n,m,d,now,c[MAXN],ans[MAXN],pre[MAXN];
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
	read(n),read(m),read(d);
	rep(i,1,m)read(c[i]);
	per(i,m,1)pre[i]=pre[i+1]+c[i];
	rep(i,1,m){
		now+=d;
		if(pre[i]+now>n) now=n-pre[i]+1;
		rep(j,now,now+c[i]-1) ans[j]=i;
		now+=c[i]-1;
	} 
	if(now+d<=n) puts("NO");
	else {
		puts("YES");
		rep(i,1,n)printf("%d ",ans[i]);
	}
	return 0;
}