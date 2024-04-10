#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(int deg=10){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*deg+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+3;
vector<int>e[N];
int n,d[N],a[N],b[N],pre[N];
V add_edge(int x,int y){
	e[x].push_back(y),e[y].push_back(x),d[x]++,d[y]++;
}
V input(){
	n=getint();
	for(int x,y;--n;add_edge(x,y))x=getint(),y=getint();
}
B cmp(int x,int y){return d[x]>d[y];}
V add(int x,int y){n++,a[n]=x,b[n]=y;}
V dfs(int u,int x){
	int deg=d[u]-(u!=1),p,flag=0;
	add(u,x);
	if(u==1)p=0;
	else if(deg<x)p=x-deg-1;
	else p=x,flag=1;
	if(p!=x)add(u,p);
	sort(e[u].begin(),e[u].end(),cmp);
	for(int v:e[u])if(v!=pre[u]){
		pre[v]=u,dfs(v,++p),deg--,add(u,p);
		if(deg<x&&flag)p=0,flag=0,add(u,p);
	}
}
V init(){
	dfs(1,n=0);
}
V work(){
	cout<<n<<'\n';
	FOR(i,1,n)cout<<a[i]<<' '<<b[i]<<'\n';
}
int main(){
	input();
	init();
	work();
	return 0;
}