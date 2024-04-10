#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+100;
int n,r,a[N];
V input(){
	n=getint(),r=getint();
	FOR(i,1,n)
		a[i]=getint();
}
V init(){sort(a+1,a+1+n),n=unique(a+1,a+1+n)-a-1;}
V work(){
	rnt ans=0,cur=0;
	while(a[n]>cur)
		ans++,cur+=r,n--;
	cout<<ans<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	int T;T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}