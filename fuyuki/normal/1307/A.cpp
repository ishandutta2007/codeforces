#include<cstdio>
#include<iostream>
#include<algorithm>
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
const int N=1e5+1;
int n,m,ans,a[N];
V input(){
	n=getint(),m=getint(),ans=0;
	FOR(i,1,n)a[i]=getint();
}
V init(){
	FOR(i,1,n)
		while(a[i]&&m>=i-1)
			m-=i-1,ans++,a[i]--;
	cout<<ans<<'\n';
}
V work(){
	
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