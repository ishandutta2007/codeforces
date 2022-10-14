#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
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
int T,n;
V input(){
	T=getint();
	while(T--){
		n=getint();
		if(n==1){
			cout<<"-1\n";
		}
		else{
			if(n%3==1)cout<<4;
			else cout<<2;
			FOR(i,2,n-1)cout<<2;
			cout<<3<<'\n';
		}
	}
}
V init(){
	
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}