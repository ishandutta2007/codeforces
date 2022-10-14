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
const int N=1e2+1;
int f[N][N][N],g[N][N][N];
I dp(rnt x,rnt y,rnt z){
	if(g[x][y][z])return f[x][y][z];
	g[x][y][z]=1;
	if(x>=1&&y>=2)f[x][y][z]=max(f[x][y][z],dp(x-1,y-2,z)+3);
	if(y>=1&&z>=2)f[x][y][z]=max(f[x][y][z],dp(x,y-1,z-2)+3);
	return f[x][y][z];
}
V input(){
	
}
V init(){
	
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
	int T,x,y,z;
	T=getint();
	while(T--){
		x=getint(),y=getint(),z=getint();
		cout<<dp(x,y,z)<<'\n';
	}
	input();
	init();
	work();
	return 0;
}