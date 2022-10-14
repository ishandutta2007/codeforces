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
const int N=2e5+1;
int T,n,tot,a[N],h[N];
struct edge{int t,n;}e[N<<1];
V add_edge(int x,int y){
	e[++tot]=(edge){y,h[x]},h[x]=tot;
	e[++tot]=(edge){x,h[y]},h[y]=tot;
}
V input(){
	int x,y;
	x=getint(),y=getint();
	cout<<(y-x%y)%y<<'\n';
//	n=getint();
//	FOR(i,1,n)a[i]=getint();
}
V init(){
	
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}