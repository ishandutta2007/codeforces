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
#define REP(u) for(rnt _=h[u],v;v=e[_].t,_;_=e[_].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=(_ch=='-')?-1:1,_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e6+1,INF=1e9;
int n,a[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
	a[n+1]=INF,a[n+2]=INF+2;
}
V init(){
	
}
V work(){
	rnt g,s,b,x,y,z,p,X,Y,Z;
	x=y=z=g=s=b=1;
	while(a[x+1]==a[1]&&x<=n)
		g++,x++;
	y=x+1;
	while(g>=s&&y<=n){
		p=y+1;
		while(a[y+1]==a[p]&&y<=n)
			s++,y++;
	}
	z=y+1;
	while(g>=b&&z<=n){
		p=z+1;
		while(a[z+1]==a[p]&&z<=n)
			b++,z++;
	}
	if(g+s+b>n/2)return void(cout<<"0 0 0\n");
	while(g+s+b<=n/2&&z<n){
		p=z+1,X=b;
		while(a[z+1]==a[p]&&z<n)
			z++,b++;
	}
	cout<<g<<' '<<s<<' '<<X<<'\n';
}
V clean(){
}
int main(){
//	freopen("test.in","r",stdin);
	int T;T=getint();
	while(T--){
		input();
		init();
		work();
		clean();
	}
	return 0;
}