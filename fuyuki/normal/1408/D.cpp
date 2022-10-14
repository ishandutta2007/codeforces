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
int n,m,ans;
int a[N],b[N],c[N],d[N],s[N];
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)a[i]=getint(),b[i]=getint();
	FOR(i,1,m)c[i]=getint(),d[i]=getint();
	FOR(i,1,n){
		int dx=0,dy=0;
		FOR(j,1,m)if(a[i]<=c[j]&&b[i]<=d[j])
			dx=c[j]-a[i],dy=d[j]-b[i],cmax(s[dx],dy+1);
	}
	n=N-1,ans=N<<3;
	ROF(i,n-1,0)cmax(s[i],s[i+1]);
	FOR(i,0,n)cmin(ans,i+s[i]);
	cout<<ans;
}
V init(){
	
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}