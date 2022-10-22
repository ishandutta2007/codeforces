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
const int MAXN = 4e5+10;
int T,n,a[MAXN];
vector<int> mjy;
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
	for(read(T);T;T--){
		mjy.clear();
		read(n);a[n+1]=-1;
		rep(i,1,n) read(a[i]);
		rep(i,2,n+1) if(a[i]!=a[i-1]) mjy.pb(i-1);
		int all=-1,quq;
		rep(i,0,size(mjy)-1) if(mjy[i]<=n/2) all=mjy[i],quq=i;else break;
		if(all==-1) {puts("0 0 0");continue;}
		int l=1,r=quq-1,ans=-1;
		while(l<=r){
			int mid=l+r>>1;
			if(mjy[mid]-mjy[0]>mjy[0]) ans=mid,r=mid-1;
			else l=mid+1; 
		}
		if(ans==-1) puts("0 0 0"); 
		else if(all-mjy[ans]>mjy[0]) printf("%d %d %d\n",mjy[0],mjy[ans]-mjy[0],all-mjy[ans]);
		else puts("0 0 0");
	}
	return 0;
}