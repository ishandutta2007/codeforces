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
const int N=5e2+2,mod=998244353,INF=0x3f3f3f3f,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
ll ans;
int T,n,m,a[N][N],t[N][N],pos[N];
V input(){
	n=getint(),m=getint(),ans=0;
	FOR(i,1,n)FOR(j,1,m)a[i][j]=getint();
	FOR(i,1,n)sort(a[i]+1,a[i]+1+m),pos[i]=1;
	FOR(_,1,m){
		int p=0,val=INF;
		FOR(i,1,n)if(a[i][pos[i]]<val)val=a[i][pos[i]],p=i;
		FOR(i,1,n)
			if(i==p)t[i][_]=a[i][pos[i]++];
			else t[i][_]=a[i][m+pos[i]-_];
	}
	FOR(i,1,n)FOR(j,1,m)cout<<t[i][j]<<" \n"[j==m];
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