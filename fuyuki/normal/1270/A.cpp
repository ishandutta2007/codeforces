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
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=1e3+1;
int T,n,m,s1,s2;
V input(){
	getint();
	n=getint(),m=getint();
	s1=s2=0;
	while(n--)
		s1=max(s1,getint());
	while(m--)
		s2=max(s2,getint());
}
V init(){
	
}
V work(){
	if(s1>s2)cout<<"YES\n";
	else cout<<"NO\n";	
}
int main(){
//	freopen("test.in","r",stdin);
	T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}