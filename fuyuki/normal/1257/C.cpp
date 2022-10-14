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
const int N=2e5+1;
int n,ans,a[N],b[N];
V input(){n=getint();FOR(i,1,n)a[i]=getint();}
V init(){FOR(i,1,n)b[i]=0;ans=N;}
V work(){
	FOR(i,1,n){
		if(b[a[i]])ans=min(ans,i-b[a[i]]+1);
		b[a[i]]=i;
	}
	if(ans==N)cout<<"-1\n";
	else cout<<ans<<'\n';
}
int main(){
	rnt T;T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}