#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re //register
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
const int N=1e6+1;
int n,m,x,y;
int a[N],b[N];
V input(){n=getint(),m=sqrt(n);}
V init(){x=y=0,a[++x]=0,a[0]=-1;}
V work(){
	FOR(i,1,m)a[++x]=i,b[++y]=n/i;
	while(y)a[++x]=b[y--];
	x=unique(a+1,a+1+x)-a-1;
	cout<<x<<'\n';
	FOR(i,1,x)cout<<a[i]<<' ';
	cout<<'\n';
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