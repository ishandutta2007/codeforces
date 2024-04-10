#include<cstdio>
#include<iostream>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e3+5,mod=1e9+7;
int t[N][N],a[N],b[N];
int n,m;
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,m)b[i]=getint();
}
V work(){
	FOR(i,1,n)FOR(j,1,a[i])t[i][j]=1;
	FOR(i,1,m)FOR(j,1,b[i])t[j][i]=1;
	FOR(i,1,n)if(t[i][a[i]+1]==1)return void(cout<<0);
	FOR(i,1,m)if(t[b[i]+1][i]==1)return void(cout<<0);
	FOR(i,1,m)t[b[i]+1][i]=1;
	FOR(i,1,n)t[i][a[i]+1]=1;
	rnt ans=1;
	FOR(i,1,n)FOR(j,1,m)if(!t[i][j])ans=(ans<<1)%mod;
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	work();
	return 0;
}