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
const int N=3e5+2,INF=0x3f3f3f3f;
vector<int>pos[N];
int T,n,a[N],ans[N];
V input(){
	n=getint();
	FOR(i,1,n)pos[i].clear();
	FOR(i,1,n)a[i]=getint(),pos[a[i]].push_back(i);
	FOR(i,1,n)pos[i].push_back(n+1);
}
V init(){
	FOR(i,0,n)ans[i]=INF;
	FOR(i,1,n){
		int p=0,d=0;
		for(int x:pos[i])d=max(x-p,d),p=x;
		ans[d]=min(ans[d],i);
	}
}
V work(){
	FOR(i,1,n)ans[i]=min(ans[i],ans[i-1]);
	FOR(i,1,n)
		if(ans[i]==INF)cout<<"-1 ";
		else cout<<ans[i]<<' ';
	cout<<'\n';
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