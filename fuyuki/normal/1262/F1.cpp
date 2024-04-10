#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=2e5+1,mod=998244353;
int n,m,k,ans,sum;
int a[N],b[N],fac[N],inv[N];
V input(){
	n=getint(),k=getint();
	FOR(i,1,n)a[i]=getint(),b[i%n+1]=a[i];
}
I Pow(ll t,rnt x){
	if(x<0)return 0;
	ll s=1;
	for(;x;x>>=1,t=t*t%mod)if(x&1)
		s=s*t%mod;
	return s;
}
V init(){
	FOR(i,1,n)
		if(a[i]==b[i])m++;
	fac[0]=inv[0]=1;
	FOR(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=Pow(fac[n],mod-2);
	ROF(i,n-1,1)inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
I C(rnt x,rnt y){
	if(x<0||y<0||x<y)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
V check(int&x){x-=mod,x+=x>>31&mod;}
V work(){
	ans=0,sum=Pow(k,m),m=n-m;
	FOR(i,1,m)FOR(j,0,i-1){
		check(ans+=1ll*C(m,i)*C(m-i,j)%mod*Pow(k-2,m-i-j)%mod);
//		cout<<i<<' '<<j<<' '<<1ll*C(m,i)*C(m-i,j)%mod*Pow(k-2,m-i-j)%mod<<'\n';
	}
	cout<<1ll*ans*sum%mod;
	
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}