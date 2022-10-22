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
int T,n,col[MAXN],sum[MAXN];
map<int,int> Map; 
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
int main(){
	//freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		read(n);Map.clear();
		int ans=(n*2);
		rep(i,1,n*2) read(col[i]),sum[i]=0;
		sum[0]=sum[n*2+1]=0;Map[0]=0;
		rep(i,1,n) sum[i]=sum[i-1]+(col[i]==1?1:-1),Map[sum[i]]=i;
		per(i,n*2,n+1) {
			sum[i]=sum[i+1]+(col[i]==1?1:-1);
			if(Map.count(-sum[i]))ans=min(ans,n-Map[-sum[i]]+i-(n+1));
		}
		printf("%d\n",min(ans,n-Map[0]+n*2+1-(n+1)));
	}
	return 0;
}