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
const int N=1<<20|1,mod=998244353,G=3,inv3=332748118,inv2=499122177;
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
int a[N];
int main(){
//	freopen("test.in","r",stdin);
	n=getint();
	FOR(i,1,n)a[i]=getint();
	sort(a+1,a+1+n),m=n;
	rnt p=1;
	while(m){
		ans++;
		while(!a[p])p++;
		FOR(i,p+1,n)if(a[i]%a[p]==0&&a[i]!=0)
			a[i]=0,m--;
		a[p++]=0,m--;
	}
	cout<<ans;
	return 0;
}