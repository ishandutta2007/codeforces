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
const int N=3e5+1,mod=998244353;
int tot,q,fac[N],inv[N];
ll n,p[N];
V input(){
	n=getint();
	int k=sqrt(n);
	FOR(i,2,k)if(n%i==0){
		p[++tot]=i;
		while(n%i==0)n/=i;
		k=sqrt(n);
	}
	if(n>1)p[++tot]=n;
}
V init(){
	int m=200;
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	FOR(i,1,m)fac[i]=1ll*fac[i-1]*i%mod;
	FOR(i,2,m)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,1,m)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
ll gcd(ll x,ll y){return!y?x:gcd(y,x%y);}
I solve(ll x,ll y){
	int out=1,cnt=0,now=0;
	FOR(i,1,tot){
		while(x%p[i]==0)
			x/=p[i],now--;
		while(y%p[i]==0)
			y/=p[i],now++;
		out=1ll*out*inv[now]%mod;
		cnt+=now,now=0;
	}
	return 1ll*out*fac[cnt]%mod;
}
V work(){
	ll x,y,z;
	q=getint();
	while(q--){
		x=getint(),y=getint();
		z=gcd(x,y);
		cout<<1ll*solve(z,x)*solve(z,y)%mod<<'\n';
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}