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
char t[N],x[N],y[N];
V input(){
	scanf("%d%s",&n,t+1);
	x[n+1]=y[n+1]='\000';
	int flag=0;
	FOR(i,1,n){
		switch(t[i]){
			case '0':{
				x[i]=y[i]='0';
				break;
			}
			case '1':{
				if(!flag)x[i]='1',y[i]='0',flag=1;
				else x[i]='0',y[i]='1';
				break;
			}
			case '2':{
				if(!flag)x[i]=y[i]='1';
				else x[i]='0',y[i]='2';
				break;
			}
		}
	}
	cout<<x+1<<'\n'<<y+1<<'\n';
}
V init(){
	
}
V work(){
	
}
int main(){
	scanf("%d",&T);
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}