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
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
int a,b,c,d,k,s1,s2;
V input(){
	a=getint(),b=getint(),c=getint(),d=getint(),k=getint();
}
V init(){
	s1=a/c+(a%c>0);
	s2=b/d+(b%d>0);
}
V work(){
	if(s1+s2>k)cout<<"-1\n";
	else cout<<s1<<' '<<s2<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	int T;T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}