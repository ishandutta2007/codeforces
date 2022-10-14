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
int T,n,k,tot,a[N],h[N];
struct edge{int t,n;}e[N<<1];
V add_edge(int x,int y){
	e[++tot]=(edge){y,h[x]},h[x]=tot;
	e[++tot]=(edge){x,h[y]},h[y]=tot;
}
char out[N];
V input(){
	n=getint(),k=getint();
	FOR(i,1,n)out[i]='a';
	out[n+1]='\000',k--;
	int p=n;
	while(k>=n-p)k-=n-p--;
	out[p]='b',p=n;
	while(k)k--,p--;
	out[p]='b';
	cout<<out+1<<'\n';
}
V init(){
	
}
V work(){
	
}
int main(){
	T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}