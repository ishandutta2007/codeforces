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
ll n;
inl bool ask(ll n){
	cout<<"? "<<n<<endl;
	int x;cin>>x;
	return x;
}
namespace Sub2{
	int id[100];
	inl void Work(){
		int cnt=0;
		for(int i=1;i<=n;i+=2) id[i]=++cnt;
		for(int i=n-(n&1);i>=1;i-=2) id[i]=++cnt;
		ask(id[1]);
		rep(i,2,n) if(!ask(id[i])) {
			cout<<"= "<<abs(id[i]-id[i-1])+1<<endl;
			return ;
		}
		cout<<"= 1"<<endl;
	}
}
inl void Case(){
	cin>>n;
	if(n<=64) {
		Sub2::Work();
		return ;
	}
	ll l=1,r=n-1,nw=0,Min=n,Max=0;
	bool flag=1;
	while(l<=r) {
		ll mid=l+r>>1;
		nw+=flag?mid:-mid;
		flag=!flag;l=mid+1;
		ylmax(Max,nw),ylmin(Min,nw);
	}
	assert(-Min <= n-Max);
	ll start=-Min+1,ans=n;
	l=1,r=n-1,flag=1;
	ask(start); 
	while(l<=r){
		ll mid=l+r>>1;
		start+=flag?mid:-mid;
		flag=!flag;
		if(ask(start)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	cout<<"= "<<ans<<'\n';
}
int main(){
	//freopen("in.txt","r",stdin);
	int T;
	for(cin>>T;T;T--) Case();
	return 0;
}