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
const int N=5e3+1,mod=998244353,INF=0x3f3f3f3f;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int n,a[N],b[N];
ll ans,c[N<<1],s[N][N],pre[N],nxt[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,n)b[i]=getint();
}
V init(){
	FOR(i,1,n)pre[i]=pre[i-1]+1ll*a[i]*b[i];
	ROF(i,n,1)nxt[i]=nxt[i+1]+1ll*a[i]*b[i];
}
V work(){
	FOR(i,1,n){
		FOR(j,i,n)s[i][j]-=c[i+j];
		FOR(j,1,n)c[i+j]+=1ll*a[i]*b[j];
		FOR(j,1,i)s[j][i]+=c[i+j];
	}
//	FOR(i,1,n){
//		FOR(j,i,n)s[i][j]+=c[i+j];
//		FOR(j,1,i)c[i+j]+=1ll*a[i]*b[j]+1ll*a[j]*b[i];
//		c[i+i]-=1ll*a[i]*b[i];
//	}
//	FOR(i,1,n+n)c[i]=0;
//	FOR(i,1,n){
//		FOR(j,i,n)s[i][j]-=2ll*c[i+j];
//		FOR(j,1,n)c[i+j]+=1ll*a[i]*b[j];
//	}
//	FOR(i,1,n)FOR(j,i,n)s[i][j]+=c[i+j];
	FOR(i,1,n)FOR(j,i,n)ans=max(ans,s[i][j]+pre[i-1]+nxt[j+1]);
//	FOR(i,1,n)FOR(j,i,n){
//		ll tmp=0;
//		FOR(k,i,j)tmp+=1ll*a[k]*b[i+j-k];
//		cout<<i<<' '<<j<<' '<<tmp<<' '<<s[i][j]<<'\n';
//	}
	cout<<ans;
//	FOR(i,1,n){
//		FOR(j,1,i)c[i+j]+=1ll*a[i]*b[j];
//		
//	}
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