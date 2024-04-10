#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int _flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=_flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e5+1,mod=1e9+7;
int f[N],n,m;
V check(int&x){x-=mod,x+=x>>31&mod;}
V input(){
	f[0]=1,f[1]=1,n=getint(),m=getint();
	FOR(i,2,N-1)check(f[i]=f[i-1]+f[i-2]);
}
V init(){
	
}
V work(){
	cout<<2ll*((long long )mod-1+f[n]+f[m])%mod;
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	input();
	init();
	work();
	return 0;
}