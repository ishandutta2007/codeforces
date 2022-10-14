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
#define ld double
ld ans,tx,ty;
int T,n,a[N];
V input(){
	n=getint(),a[n+1]=getint(),ans=0,tx=0,ty=0;
	FOR(i,1,n)a[i]=getint();
	ld sx=1,sy=1,dis;
	int x=1,y=n;
	while(x<=y){
		if(tx+(a[x]-a[x-1])/sx<ty+(a[y+1]-a[y])/sy)
			tx+=(a[x]-a[x-1])/sx,sx+=1,x++;
		else ty+=(a[y+1]-a[y])/sy,sy+=1,y--;
	}
	if(tx<ty)dis=a[x]-a[y]-(ty-tx)*sx;
	else dis=a[x]-a[y]-(tx-ty)*sy;
	ans=max(tx,ty)+dis/(sx+sy);
	printf("%.9lf\n",ans);
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