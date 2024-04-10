#include<set>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define IT std::set<int>::iterator
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt _=h[u],v;v=e[_].t,_;_=e[_].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=(_ch=='-')?-1:1,_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e6+1,INF=1e9,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
int n,m,ans,p[N];
int fac[N],inv[N],s[N];
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)p[i]=getint();
}
set<int>mp;
I Pow(ll t,rnt x){
	ll s=1;
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
V init(){
	mp.insert(1),mp.insert(n+1);
	rnt x=Pow(100,mod-2);
	ans=fac[0]=inv[0]=1;
	FOR(i,1,n)p[i]=1ll*p[i]*x%mod;
	FOR(i,1,n)fac[i]=1ll*fac[i-1]*p[i]%mod;
	inv[n]=Pow(fac[n],mod-2);
	ROF(i,n-1,1)inv[i]=1ll*inv[i+1]*p[i+1]%mod;
	FOR(i,1,n)check(s[i]=s[i-1]+fac[i]);
}
I calc(rnt l,rnt r){
	return 1ll*((ll)s[r-1]-s[l-1]+fac[l-1]+mod)*inv[r]%mod;
}
V work(){
	IT i;
	ans=calc(1,n);
//	cout<<calc(1,n)<<'\n';
	while(m--){
		rnt x=getint(),l,r;
		if(mp.find(x)!=mp.end()){
			mp.erase(x);
			i=mp.lower_bound(x),l=*--i;
			i=mp.upper_bound(x),r=*i;
			check(ans+=mod-calc(l,x-1));
			check(ans+=mod-calc(x,r-1));
			check(ans+=calc(l,r-1));
		}
		else{
			mp.insert(x);
			i=mp.lower_bound(x),l=*--i;
			i=mp.upper_bound(x),r=*i;
			check(ans+=mod-calc(l,r-1));
			check(ans+=calc(l,x-1));
			check(ans+=calc(x,r-1));
		}
		cout<<ans<<'\n';
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}