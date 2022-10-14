#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
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
const int N=1e2+1,mod=1e9+7;
V input(){
	
}
V init(){
	
}
V work(){
	
}
I Pow(ll t,rnt x){
	ll s=1;
	while(x){
		if(x&1)s=s*t%mod;
		t=t*t%mod,x>>=1;
	}
	return s;
}
int main(){
//	freopen("test.in","r",stdin);
	rnt n,m;
	n=getint(),m=getint();
	cout<<Pow(Pow(2,m)-1,n);
	input();
	init();
	work();
	return 0;
}