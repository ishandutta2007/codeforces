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
const int MAXN = 1010;
const int Mod = 1e9+7;
int n,x,pos,cnta,cntb;
// a:>x b:<=x 
ll fac[MAXN],inv[MAXN]; 
inl ll C(int n,int m){
	return fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(x),read(pos);
	int l=0,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(pos<mid) cnta++,r=mid;
		else cntb++,l=mid+1;
	}
	if(cntb>x || cnta>(n-x)) puts("0");
	else {
		n--,cntb--,x--;
		fac[1]=inv[1]=1;inv[0]=fac[0]=1;
		rep(i,2,n) fac[i]=fac[i-1]*i%Mod;
		rep(i,2,n) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
		rep(i,2,n) inv[i]=inv[i]*inv[i-1]%Mod;
		printf("%d\n",C(x,cntb)*C(n-x,cnta)%Mod*fac[cntb]%Mod*fac[cnta]%Mod*fac[n-cnta-cntb]%Mod);
	}
	return 0;
}