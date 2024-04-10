#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=251,mod=1e9+7;
int n,m;
V input(){cin>>n>>m;}
I Pow(ll t,ll x){
	ll s=1;
	while(x){
		if(x&1)s=s*t%mod;
		t=t*t%mod,x>>=1;
	}
	return s;
}
int fac[N],fac_inv[N],pw0[N],pw1[N];
I C(rnt x,rnt y){
	if(x<y)return 0;
	return 1ll*fac[x]*fac_inv[x-y]%mod*fac_inv[y]%mod;
}
V init(){
	fac[0]=fac_inv[0]=pw0[0]=pw1[0]=1;
	FOR(i,1,n)fac[i]=1ll*fac[i-1]*i%mod,fac_inv[i]=Pow(fac[i],mod-2);
	FOR(i,1,n)pw0[i]=1ll*pw0[i-1]*m%mod;
	FOR(i,1,n)pw1[i]=1ll*pw1[i-1]*(m-1)%mod;
}
int f[N][N];
V check(int&x){x-=mod,x+=x>>31&mod;}
V work(){
	f[0][n]=1;
	FOR(i,1,n)FOR(j,0,n)FOR(k,0,j)
		if(k==0)check(f[i][j]+=1ll*f[i-1][j]%mod*pw1[j]%mod*(mod+pw0[n-j]-pw1[n-j])%mod);
		else check(f[i][j-k]+=1ll*f[i-1][j]%mod*C(j,k)%mod*pw1[j-k]%mod*pw0[n-j]%mod);
	cout<<f[n][0];
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}