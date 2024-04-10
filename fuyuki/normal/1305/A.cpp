#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
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
const int N=5e5+1;
int n,a[N],b[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,n)b[i]=getint();
	
}
V init(){
	sort(a+1,a+1+n),sort(b+1,b+1+n);
}
V work(){
	FOR(i,1,n)cout<<a[i]<<" \n"[i==n];
	FOR(i,1,n)cout<<b[i]<<" \n"[i==n];
	
}
int main(){
	for(int T=getint();T--;){
		input();
		init();
		work();
	}
	return 0;
}