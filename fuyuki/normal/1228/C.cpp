#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
#define rnt re int
#define re register
//#define INT __int128
#define LL inline ll
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int mod=1e9+7;
ll x,n;
V input(){cin>>x>>n;}
I Pow(ll t,ll x){
	ll s=1;
	while(x){
		if(x&1)s=s*t%mod;
		t=t*t%mod,x>>=1;
	}
	return s;
}
int pri[1000];
int tot;
V init(){
	int lim=sqrt(x);
	FOR(i,2,lim){
		if(x%i==0)pri[++tot]=i;
		while(x%i==0)x/=i;
	}
	if(x!=1)pri[++tot]=x;
}
V work(){
	ll ans=1;
	FOR(i,1,tot){
		ll now=1;
		while(n/now/pri[i])
			now*=pri[i],ans=ans*Pow(pri[i],n/now)%mod;
	}
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}