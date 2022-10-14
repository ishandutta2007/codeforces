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
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int T,n,m,pre[N],nxt[N];
char a[N];
V input(){
	scanf("%d%d%s",&n,&m,a+1);
	FOR(i,1,n)
		if(a[i]=='1')pre[i]=i;
		else pre[i]=pre[i-1];
	nxt[n+1]=n+1;
	ROF(i,n,1)
		if(a[i]=='1')nxt[i]=i;
		else nxt[i]=nxt[i+1];
}
V init(){
	FOR(i,1,n){
		if(a[i]=='1')cout<<1;
		else{
			int dx=i-pre[i],dy=nxt[i]-i;
			if(pre[i]==0)dx=INF;
			if(nxt[i]==n+1)dy=INF;
			if(dx==dy)cout<<0;
			else cout<<(min(dx,dy)<=m);
		}
	}
	cout<<'\n';
}
V work(){
	FOR(i,1,n+1)pre[i]=nxt[i]=0;
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