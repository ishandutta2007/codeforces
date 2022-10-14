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
ll getint(){
	ll _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=5e3+1,mod=998244353;
//V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
//ll W;
//int T,n,a[N];
char a[N],b[N];
int n,m,ans,f[N][N];
V input(){
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
}
V init(){
	a[0]='#',b[0]='$';
	FOR(i,0,n)FOR(j,0,m){
		if(i)cmax(f[i][j],f[i-1][j]-1);
		if(j)cmax(f[i][j],f[i][j-1]-1);
		if(a[i]==b[j])cmax(f[i][j],f[i-1][j-1]+2);
		cmax(ans,f[i][j]);
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