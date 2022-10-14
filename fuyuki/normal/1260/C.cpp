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
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
int n;
V input(){
	n=getint();
}
V init(){
	
}
I gcd(rnt x,rnt y){return !y?x:gcd(y,x%y);}
V work(){
	rnt x,y,z,k,ans;
	while(n--){
		x=getint(),y=getint(),z=getint();
		k=gcd(x,y),x/=k,y/=k;
		if(x<y)swap(x,y);
		if(x-1<=1ll*y*(z-1))
			cout<<"OBEY\n";
		else cout<<"REBEL\n";
	}
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}