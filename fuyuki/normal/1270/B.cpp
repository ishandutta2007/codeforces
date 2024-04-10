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
const int INF=0x7fffffff,N=2e5+1;
int n,a[N],b[N];
V input(){
	n=getint();
	FOR(i,1,n)b[i]=getint();
}
V init(){
	
}
V work(){
	rnt x,p;
	x=INF,p=0;
	FOR(i,1,n)a[i]=b[i]-i;
	FOR(i,1,n){
		if(a[i]>x){
			cout<<"YES\n";
			cout<<p<<' '<<i<<'\n';
			return;
		}
		if(a[i]<x)x=a[i],p=i;
	}
	x=-INF,p=0;
	FOR(i,1,n)a[i]=b[i]+i;
	FOR(i,1,n){
		if(a[i]<x){
			cout<<"YES\n";
			cout<<p<<' '<<i<<'\n';
			return;
		}
		if(a[i]>x)x=a[i],p=i;
	}
	cout<<"NO\n";
}
int main(){
	int T;T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}