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
#define next NEXT
const int MAXN = 410;
int T,n,m,dp[MAXN][MAXN],next[MAXN][26],now[26];
char s[MAXN],t[MAXN];
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
inl bool check(vector<int> a,vector<int> b){
	dp[0][0]=0;
	rep(i,0,size(a)-1) rep(j,0,size(b)-1) {
		if(i==0 && j==0) dp[i][j]=0;else dp[i][j]=1e9;
		if(i) ylmin(dp[i][j],next[dp[i-1][j]][a[i]]);
		if(j) ylmin(dp[i][j],next[dp[i][j-1]][b[j]]);
		if(dp[i][j]==n+1) return false;
	}
	return true;
}
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%s%s",s+1,t+1);
		int flag=1;
		n=strlen(s+1),m=strlen(t+1);
		rep(i,0,25) now[i]=n+1;
		per(i,n,0){
			rep(j,0,25) next[i][j]=now[j];
			now[s[i]-'a']=i;
		}
		rep(i,1,m){
			vector<int> s1,s2;s1.pb(0),s2.pb(0);
			rep(j,1,i) s1.pb(t[j]-'a');
			rep(j,i+1,m) s2.pb(t[j]-'a');
			if(check(s1,s2)) {puts("YES");flag=0;break;}
		}
		if(flag) puts("NO");
	}
	return 0;
}