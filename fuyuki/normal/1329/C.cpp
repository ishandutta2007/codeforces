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
//I min(const int&x,const int&y){return(x-y>>31)?x:y;}
//I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=1<<22|1;
int T,n,m,tot,a[N],opt[N];
ll ans;
V input(){
	n=1<<getint(),n--,m=getint(),ans=0;
	FOR(i,1,n)a[i]=getint(),ans+=a[i];
}
V init(){
	tot=0;
}
#define lc p<<1
#define rc p<<1|1
I getdep(int p,int dep){
	if(!a[lc]&&!a[rc])return dep;
	if(a[lc]>a[rc])return getdep(lc,dep+1);
	else return getdep(rc,dep+1);
}
V erase(int p){
	if(!a[lc]&&!a[rc])return void(a[p]=0);
	if(a[lc]>a[rc])a[p]=a[lc],erase(lc);
	else a[p]=a[rc],erase(rc);
}
V solve(int p,int dep){
	if(dep>m)return;
	while(getdep(p,dep)>m){
		opt[++tot]=p;
		ans-=a[p],erase(p);
	}
	solve(lc,dep+1),solve(rc,dep+1);
}
V work(){
	solve(1,1),cout<<ans<<'\n';
	FOR(i,1,tot)cout<<opt[i]<<" \n"[i==tot];
	FOR(i,1,n)a[i]=0;
}
int main(){
	for(T=getint();T--;){
		input();
		init();
		work();
	}
	return 0;
}