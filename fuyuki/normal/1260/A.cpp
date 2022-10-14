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
V work(){
	rnt x,y,ans;
	while(n--){
		x=getint(),y=getint(),ans=0;
		FOR(i,1,y%x)ans+=(y/x+1)*(y/x+1);
		FOR(i,y%x+1,x)ans+=(y/x)*(y/x);
		cout<<ans<<'\n';
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}