#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define cl(x) memset(x,0,l<<2)
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,A,B) for(rnt i(A);i<=B;i++)
#define ROF(i,A,B) for(rnt i(A);i>=B;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
const int N=1<<20|1,mod=998244353,G=3,inv3=332748118,inv2=499122177,lim=5e4;
I getint() {
	rnt _s=0;
	re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
I Pow(re ll t,rnt x){
	re ll s=1;
	while(x) {
		if(x&1)s=s*t%mod;
		x>>=1,t=t*t%mod;
	}
	return s;
}
int n,m,ans;
int a[N],b[N],t[N];
char op[N];
I max(const int&x,const int&y){return x>y?x:y;}
int main(){
//	freopen("test.in","r",stdin);
	n=getint();
	re char ch=gc;
	while(!isnum(ch))
		ch=gc;
	FOR(i,1,n)op[i]=ch,ch=gc;
	FOR(i,1,n)a[i]=getint(),b[i]=getint();
	FOR(i,1,n){
		rnt p=b[i],now=op[i]-'0';
		FOR(j,0,b[i]-1)t[j]+=now;
		while(p<=lim){
			now^=1;
			FOR(j,p,p+a[i]-1)t[j]+=now;
			p+=a[i];
		}
	}
	FOR(i,0,lim)ans=max(ans,t[i]);
	cout<<ans<<'\n';
	return 0;
}