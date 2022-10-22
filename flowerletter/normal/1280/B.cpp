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
const int MAXN = 65;
int T,n,m;
char s[MAXN][MAXN];
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
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='A') return false;
	return true;
}
inl bool check1(){
	bool flag=1;
	rep(i,1,m) if(s[1][i]=='P') flag=0;
	if(flag) return flag;
	flag=1;
	rep(i,1,m) if(s[n][i]=='P') flag=0;
	if(flag) return flag;
	flag=1;
	rep(i,1,n) if(s[i][1]=='P') flag=0;
	if(flag) return flag;
	flag=1;
	rep(i,1,n) if(s[i][m]=='P') flag=0;
	return flag;
}
inl bool check2(){
	rep(i,2,n-1){
		bool flag=1;
		rep(j,1,m) if(s[i][j]=='P') flag=0;
		if(flag) return flag;
	}
	rep(i,2,m-1){
		bool flag=1;
		rep(j,1,n) if(s[j][i]=='P') flag=0;
		if(flag) return flag;
	}
	return s[1][1]=='A' || s[1][m]=='A' || s[n][1]=='A' || s[n][m]=='A';
}
inl bool check3(){
	rep(i,2,m-1) if(s[1][i]=='A' || s[n][i]=='A') return 1;
	rep(i,2,n-1) if(s[i][1]=='A' || s[i][m]=='A') return 1;
	return 0; 
}
inl bool check0(){
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='P') return false;
	return true;
}
int main(){
	//freopen("in.txt","r",stdin);
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n) scanf("%s",s[i]+1);
		if(check()) puts("MORTAL");
		else {
			if(check0()) puts("0");
			else if(check1()) puts("1");
			else if(check2()) puts("2");
			else if(check3()) puts("3");
			else puts("4");
		}
	}
	return 0;
}