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
const int Mod = 1e9+7;
int T,x,n;ll f[MAXN];
char s[MAXN*5];
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
//	freopen("in.txt","r",stdin);
	for(scanf("%d",&T);T;T--){
		memset(s,'\0',sizeof(s));
		memset(f,0,sizeof(f));
		scanf("%d%s",&x,s+1);
		n=strlen(s+1);
		int now=1,N=n;
		while(n<x){
			int quq=s[now]-'0',m=n;
			rep(i,1,quq-1) rep(j,now+1,n) s[++m]=s[j];
			n=m;now++;
		}
		f[0]=N;
		rep(i,1,x){
			f[i]=1ll*(f[i-1]-i+Mod)*(s[i]-'0')%Mod+i;
			f[i]%=Mod;
		}
		printf("%lld\n",f[x]);
	}
	return 0;
}