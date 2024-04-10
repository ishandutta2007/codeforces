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
const int MAXN = 1e6+10;
const int inf = 1<<27;
int n,k,l,a[MAXN];pii dp[MAXN];
char s[MAXN]; 
template<class T>inl void ylmin(T &a,T b){a=a<b?a:b;}
template<class T>inl void ylmax(T &a,T b){a=a>b?a:b;}
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
inl pii check(int x){
	rep(i,1,n) dp[i]={inf,inf};
	rep(i,1,n){
		ylmin(dp[i],{dp[i-1].fir+a[i],dp[i-1].sec});
		if(i-l>=0) ylmin(dp[i],{dp[i-l].fir+x,dp[i-l].sec+1});
	}
	return dp[n];
}
inl int solve(int type){
	rep(i,1,n) a[i]=type^(s[i]>='a' && s[i]<='z');
	int l=0,r=n,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid).sec<=k) r=mid-1,ans=mid;
		else l=mid+1;
	}
	if(ans==0 && check(ans).sec<=k) return 0;
	return check(ans).fir-k*ans;
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d%s",&n,&k,&l,s+1);
	printf("%d\n",min(solve(1),solve(0)));
	return 0;
}