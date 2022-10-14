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
const int N=2e5+100,INF=0x3f3f3f3f;
int T,n,m,a[N],f[N];
V input(){
	n=getint(),f[0]=1,a[n*2+1]=INF;
	FOR(i,1,n*2)a[i]=getint(),f[i]=0;
}
V ins(int x){
//	cerr<<x<<'\n';
	ROF(i,n*2,x)f[i]|=f[i-x];
}
V init(){
	for(int l=1,r;l<=n*2;ins(r-l+1),l=r+1)
		for(r=l;a[r+1]<=a[l];r++);
}
V work(){
	if(f[n])cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}