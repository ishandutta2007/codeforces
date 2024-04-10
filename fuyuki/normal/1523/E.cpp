#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
ll getint(){
	ll _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,mod=1e9+7,INF=0x3f3f3f3f;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
ll a[N];
int T,n,k,m,ans,fac[N],inv[N],f[N];
V input(){
	n=getint(),k=getint(),m=(n+k-1)/k,ans=0;
}
V init(){
	fac[0]=inv[0]=inv[1]=1;
	FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,1,n)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
I C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
V work(){
	FOR(i,1,m)f[i]=1ll*C(n-(i-1)*(k-1),i)*fac[i]%mod*fac[n-i]%mod;
	FOR(i,1,m)check(f[i]=f[i]+mod-f[i+1]),check(ans+=1ll*i*f[i]%mod);
	ans=1ll*ans*inv[n]%mod+1,check(ans),cout<<ans<<'\n';
	FOR(i,1,m)f[i]=0;
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}