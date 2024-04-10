#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define B inline bool
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
int n,p;
V input(){
	cin>>n>>p;
}
V init(){
}
I lowbit(rnt x){return x&-x;}
I count(rnt x){
	return !x?0:1+count(x^lowbit(x));
}
B check(rnt x,rnt k){
	return x>=k&&count(x)<=k;
}
V work(){
	FOR(k,0,100000){
//		cout<<k<<' '<<n<<' '<<count(n)<<'\n';
		if(check(n,k))
			return void(cout<<k);
		n-=p;
		if(n<0)
			return void(cout<<"-1");
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	input();
	init();
	work();
	return 0;
}