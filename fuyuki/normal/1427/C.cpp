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
const int N=2e5+1,mod=998244353,INF=0x3f3f3f3f;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
//int T,n,sum,a[N];
int n,r,t[N],X[N],Y[N],f[N];
V input(){
	r=getint(),n=getint(),r<<=1,X[0]=Y[0]=1;
	FOR(i,1,n)t[i]=getint(),X[i]=getint(),Y[i]=getint();
}
I dis(int x,int y){
	return abs(X[x]-X[y])+abs(Y[x]-Y[y]);
}
V init(){
	int maxn=-INF,ans=0;
	FOR(i,1,n){
		f[i]=maxn+1;
		FOR(j,max(0,i-r),i-1)if(dis(i,j)<=t[i]-t[j])
			cmax(f[i],f[j]+1);
		if(i>=r)cmax(maxn,f[i-r]);
		cmax(ans,f[i]);
	}
	cout<<ans;
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