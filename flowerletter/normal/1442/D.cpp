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
const int MAXN = 3010;
int n,k,num[MAXN];
ll ans,dp[MAXN],tmp[MAXN],all[MAXN];
vector<int> a[MAXN];
inl void solve(int l,int r){
	if(l==r){
		ll sum=0;ylmax(ans,dp[k]);
		rep(i,0,min(num[l]-1,k-1)) sum+=a[l][i],ylmax(ans,dp[k-i-1]+sum);
		return ;
	}
	ll tmp[MAXN],mid=l+r>>1;
	rep(i,0,k) tmp[i]=dp[i];
	rep(i,mid+1,r) per(j,k,num[i]) ylmax(dp[j],dp[j-num[i]]+all[i]);
	solve(l,mid);
	rep(i,0,k) dp[i]=tmp[i];
	rep(i,l,mid) per(j,k,num[i]) ylmax(dp[j],dp[j-num[i]]+all[i]);
	solve(mid+1,r); 
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(k);
	rep(i,1,n) {
		read(num[i]);
		rep(j,1,num[i]) {
			int x;read(x);
			a[i].push_back(x);
			all[i]+=x;
		}
	}
	solve(1,n);
	cout<<ans<<'\n';
	return 0;
}