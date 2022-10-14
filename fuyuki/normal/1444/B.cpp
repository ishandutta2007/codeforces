#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=3e5+1,mod=998244353;
int n,ans;
int a[N],inv[N],fac[N];
V check(int&x){x-=mod,x+=x>>31&mod;}
V input(){
	n=getint(),n<<=1;
	FOR(i,1,n)a[i]=getint();
}
I C(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
V init(){
	sort(a+1,a+1+n),inv[0]=inv[1]=fac[0]=1;
	FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,1,n)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
V work(int s=0,int d=0){
	n>>=1;
	FOR(i,1,n)check(ans+=mod-a[i]);
	FOR(i,n+1,n+n)check(ans+=a[i]);
	cout<<1ll*C(n+n,n)*ans%mod;
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}