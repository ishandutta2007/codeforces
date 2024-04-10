#include<vector>
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
LL getint(){
	re ll _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e5+1;
int n,m,q,d[N];
ll ans;
vector<int>a[N];
V input(){
	n=getint(),m=getint();
	rnt x,y;
	while(m--){
		x=getint(),y=getint();
		if(x>y)swap(x,y);
		a[x].push_back(y);
		d[x]++,d[y]++;
	}
}
LL val(const int&x){return 1ll*(d[x]-a[x].size())*a[x].size();}
V init(){FOR(i,1,n)ans+=val(i);}
int tmp[N],top;
V work(){
	cout<<ans<<'\n',q=getint();rnt p;
	while(q--){
		p=getint(),ans-=val(p);
		for(int x:a[p])ans-=val(x),a[x].push_back(p),ans+=val(x);
		a[p].clear(),cout<<ans<<'\n';
	}
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}