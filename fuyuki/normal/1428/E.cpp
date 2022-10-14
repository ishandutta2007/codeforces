#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<ll,int>
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
const int N=2e5+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
ll ans;
priority_queue<P>q;
int T,n,k,a[N],c[N];
V input(){
	n=getint(),k=getint();
	FOR(i,1,n)a[i]=getint(),c[i]=1;
}
ll f(int x,int y){
	int d=x/y,w=x%y;
	return 1ll*w*(d+1)*(d+1)+1ll*(y-w)*d*d;
}
ll val(int p){return f(a[p],c[p])-f(a[p],c[p]+1);}
V init(){
//	cout<<val(1)<<'\n';
	FOR(i,1,n)ans+=1ll*a[i]*a[i],q.push(P(val(i),i));
}
V work(){
	for(int u;k>n;q.push(P(val(u),u))){
		k--,u=q.top().second;
		ans-=q.top().first;
		q.pop(),c[u]++;
	}
	cout<<ans<<'\n';
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