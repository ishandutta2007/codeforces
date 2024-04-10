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
const int MAXN = 310;
int T,n,m,a[MAXN][MAXN];
int main(){
	//freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		read(n),read(m);
		rep(i,1,n) rep(j,1,m) read(a[i][j]);
		if(a[1][1]>2 || a[1][m]>2 || a[n][1]>2 || a[n][m]>2) puts("NO");
		else{
			int flag=0;
			rep(i,1,n) if(a[i][m]>3 || a[i][1]>3) {puts("NO");flag=1;break;}
			if(flag) continue;
			rep(i,1,m) if(a[1][i]>3 || a[n][i]>3) {puts("NO");flag=1;break;}
			if(flag) continue;
			rep(i,1,n) {
				rep(j,1,m) if(a[i][j]>4) {puts("NO");flag=1;break;}
				if(flag) break;
			}
			if(flag) continue;
			puts("YES");
			printf("2");
			rep(i,2,m-1) printf(" 3");
			printf(" 2\n");
			rep(i,2,n-1) {
				printf("3");
				rep(j,2,m-1) printf(" 4");
				printf(" 3\n");
			}
			printf("2");
			rep(i,2,m-1) printf(" 3");
			printf(" 2\n");
		}
	}
	return 0;
}