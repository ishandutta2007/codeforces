#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define I inline int
#define V inline void
#define ld long double
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int INF=0x7fffffff,N=1e6+1;
int n;
int x[N],y[N],mx,my;
V input(){
	n=getint();
	FOR(i,0,n-1)x[i]=getint(),y[i]=getint();
}
I nxt(int a){return (a+1)%n;}
V work(){
	if(n&1)return void(cout<<"NO");
	FOR(i,0,n/2-1)
		if(x[i]-x[nxt(i)]!=x[nxt(i+n/2)]-x[i+n/2]||
		   y[i]-y[nxt(i)]!=y[nxt(i+n/2)]-y[i+n/2])
		   return void(cout<<"NO");
	cout<<"YES";
}
int main(){
	input();
	work();
	return 0;
}