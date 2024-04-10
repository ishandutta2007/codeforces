#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
V cmin(int&x,int y){if(y-x>>31)x=y;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
I gcd(int x,int y){return!y?x:gcd(y,x);}
const int N=1e6+1,mod=998244353;
int T,n,a[N],b[N],c[N],p[N];
V input(){
	n=getint();
	FOR(i,0,n-1)a[i]=getint();
	FOR(i,0,n-1)b[i]=getint();
	FOR(i,0,n-1)c[i]=getint();
	p[0]=0;
	FOR(i,1,n-1)
		if(a[i]==p[i-1])p[i]=b[i];
		else p[i]=a[i];
	if(a[0]!=p[1]&&a[0]!=p[n-1])p[0]=a[0];
	if(b[0]!=p[1]&&b[0]!=p[n-1])p[0]=b[0];
	if(c[0]!=p[1]&&c[0]!=p[n-1])p[0]=c[0];
	FOR(i,0,n-1)cout<<p[i]<<" \n"[i==n-1];
}
V init(){
	
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}