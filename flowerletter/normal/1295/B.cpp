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
int T,n,x,now,Max,Min;
char s[MAXN]; 
map<int,int> Map; 
int main(){
	for(scanf("%d",&T);T;T--){
		Map.clear(),now=0,Max=0,Min=0;
		scanf("%d%d",&n,&x);scanf("%s",s+1);
		rep(i,1,n) now+=s[i]=='0'?1:-1,Map[now]++,ylmax(Max,now),ylmin(Min,now);
		if(now==0){
			if(Map[x]) puts("-1");
			else puts("0");
		}else {
			int ans=(x==0);
			if(x>Max && now>0) x-=((x-Max)/now+((x-Max)%now!=0))*now;
			if(x<Min && now<0) x+=((Min-x)/now-((Min-x)%now!=0))*now; 
			while(x>=Min && x<=Max) ans+=Map[x],x-=now;
			printf("%d\n",ans);
		}
	}
	return 0;
}