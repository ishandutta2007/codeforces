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
int n,m,now,ans,a[N],c[N],s[N],at[101][N];
V input(){
	n=getint(),m=min(n,100);
	FOR(i,1,n)a[i]=getint();
}
V init(){
	
}
V clean(){FOR(i,1,n)c[i]=s[i]=0;s[0]=n,now=0;}
V ins(int x){s[c[x]++]--,s[c[x]]++,now+=s[now+1];}
V work(){
	int l=0,x;
	FOR(i,1,n){
		ins(a[i]);
		if(s[now]>=2)l=i;
	}
	FOR(i,1,m)if(c[i]==now)x=i;
	ans=l,clean();
	FOR(i,1,m)FOR(j,1,n)at[i][j]=INF;
	FOR(i,1,n){
		ins(a[i]);
		FOR(j,1,m)if(j!=x&&c[x]-c[j]>=0)
			cmin(at[j][c[x]-c[j]],i);
		if(i>l){
//			FOR(j,1,m)
//				assert(c[x]>=c[j]);
			FOR(j,1,m)if(j!=x)
				cmax(ans,i-at[j][c[x]-c[j]]);
		}
	}
	cout<<ans;
	
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