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
const int MAXN = 3e5+10;
ll n,a[MAXN],b[MAXN],ans,c[MAXN];
inl void solve(int dep,vector<vector<int>> S){
	if(dep==-1) return ;
	ll all=0;
	for(auto s:S){
		ll cnt0=0,cnt1=0,sum0=0,sum1=0;
		for(auto x:s){
			if(((x>>dep)&1)==1) cnt1++,sum1+=cnt0;
			else cnt0++,sum0+=cnt1;
		}
		all+=sum0-sum1;
	}
	vector<vector<int>> SS;
	for(auto s:S){
		vector<int> s0,s1;
		for(auto x:s){
			if(((x>>dep)&1)==0) s0.pb(x);
			else s1.pb(x);
		}
		if(size(s0)) SS.pb(s0);
		if(size(s1)) SS.pb(s1);
	}
	if(all>0) ans|=(1<<dep);
	solve(dep-1,SS);
}
inl void add(int x){
	for(;x<=n;x+=lb(x)) c[x]++;
}
inl int query(int x){
	ll ans=0;
	for(;x;x-=lb(x)) ans+=c[x];
	return ans;
}
inl bool cmp(int x,int y){
	return a[x]>=a[y];
}
int main(){
//	freopen("in.txt","r",stdin);
	vector<vector<int>> S;
	vector<int> t;
	read(n);
	rep(i,1,n) read(a[i]),t.pb(a[i]);
	S.pb(t);
	solve(30,S);
	ll sum=0;
	rep(i,1,n) a[i]^=ans,b[i]=i;
	stable_sort(b+1,b+n+1,cmp);
	rep(i,1,n) {
		add(b[i]);
		sum+=query(b[i]-1);
	}
	cout<<sum<<' '<<ans<<'\n';
	return 0;
}