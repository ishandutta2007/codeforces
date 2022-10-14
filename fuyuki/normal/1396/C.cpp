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
const int N=1e6+2,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
int T,n,a[N];
ll s[N],f[N],g[N],r1,r2,r3,d,ans;
V input(){
	n=getint(),r1=getint(),r2=getint(),r3=getint(),d=getint();
	FOR(i,1,n)a[i]=getint();
}
V init(){
	s[n]=min(min(r1*(a[n]+1),r2)+r1+d+d,r1*a[n]+r3);
	ROF(i,n-1,1)s[i]=s[i+1]+min(min(r1*(a[i]+1),r2)+r1,r1*a[i]+r3)+d*2;
}
V work(){
	ans=1ll<<62,g[0]=1ll<<60;
	FOR(i,1,n){
		g[i]=f[i-1]+min(r2,r1*(a[i]+1))+r1+d+d;
		f[i]=min(f[i-1]+r1*a[i]+r3,g[i-1]+min(r2,r1*(a[i]+1))+r1);
		if(i!=1)f[i]+=d,g[i]+=d;
	}
	FOR(i,1,n)ans=min(ans,f[i]+d*(i<n)+s[i+1]);
	FOR(i,1,n)ans=min(ans,g[i]+s[i+1]);
	cout<<min(ans,s[1]);
}
int main(){
	input();
	init();
	work();
	return 0;
}