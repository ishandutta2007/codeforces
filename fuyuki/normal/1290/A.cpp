#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define I inline int
#define V inline void
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
I max(const int&x,int y){return x>y?x:y;}
I min(const int&x,int y){return x<y?x:y;}
const int N=4e3+1,INF=0x3f3f3f3f;
int n,m,k,a[N];
int f[N][N];
V input(){
	n=getint(),m=getint(),k=getint();
	if(k>=m)k=m-1;m=n-m+1;
	FOR(i,1,n)a[i]=getint();
}
V init(){
	FOR(i,0,n)FOR(j,0,n)f[i][j]=INF;
	FOR(i,1,n-m+1)
		f[i][i+m-1]=max(a[i],a[i+m-1]);
	FOR(i,m+1,n)FOR(j,1,n-i+1)
		f[j][j+i-1]=min(f[j+1][j+i-1],f[j][j+i-2]);
}
V work(){
	int ans=0;
	FOR(i,0,k)FOR(j,0,k-i)
		ans=max(ans,f[i+1][n-j]);
	cout<<ans<<'\n';
}
int main(){
	int T=1;
	T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}