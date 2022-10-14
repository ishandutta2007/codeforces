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
int T,n,a[N];
vector<int>t[N];
ll s[N],ans[N];
V input(){
	n=getint();
	FOR(i,1,n)t[getint()].push_back(i);
	FOR(i,1,n)a[i]=getint();
}
V init(){
	FOR(i,1,n)for(int&v:t[i])v=a[v];
	FOR(i,1,n)sort(t[i].begin(),t[i].end(),greater<int>());
	FOR(i,1,n){
		int m=t[i].size();
		FOR(j,1,m)s[j]=s[j-1]+t[i][j-1];
		FOR(j,1,m)ans[j]+=s[m/j*j];
		FOR(i,1,m)s[i]=0;
	}
	FOR(i,1,n)cout<<ans[i]<<" \n"[i==n],ans[i]=0,t[i].clear();
	
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