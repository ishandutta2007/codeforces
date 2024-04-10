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
int T,n,m,k,tot,h[N],f[20][N],dep[N];
struct edge{int t,n;}e[N<<1];
V add_edge(int x,int y){
	e[++tot]=(edge){y,h[x]},h[x]=tot;
	e[++tot]=(edge){x,h[y]},h[y]=tot;
}
V input(){
	n=getint(),m=getint();
	int x,y;
	FOR(i,2,n)x=getint(),y=getint(),add_edge(x,y);
}
V dfs(int u,int fa=0){
	REP(u)if(v!=fa)
		f[0][v]=u,dep[v]=dep[u]+1,dfs(v,u);
}
V init(){
	dfs(dep[1]=1);
	FOR(i,1,19)FOR(j,1,n)f[i][j]=f[i-1][f[i-1][j]];
}
I lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	ROF(i,19,0)if(dep[f[i][x]]>=dep[y])x=f[i][x];
	if(x==y)return x;
	ROF(i,19,0)if(f[i][x]!=f[i][y])x=f[i][x],y=f[i][y];
	return f[0][x];
}
V work(){
	static int t[N],p,x;
	while(m--){
		k=getint(),p=0;
		FOR(i,1,k)t[i]=getint();
		FOR(i,1,k)if(dep[t[i]]>dep[p])p=t[i];
		FOR(i,1,k){
			x=lca(t[i],p);
			if(x==p||x==t[i])continue;
			if(x==f[0][t[i]])
				continue;
			cout<<"NO\n";
			goto end;
		}
		cout<<"YES\n";
		end:;
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}