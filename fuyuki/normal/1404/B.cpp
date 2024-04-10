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
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=5e5+1,INF=0x3f3f3f3f;
vector<int>e[N];
int T,n,ta,tb,da,db,ans,f[N],g[N];
V input(){n=getint(),ta=getint(),tb=getint(),da=getint(),db=getint();}
V add_edge(int x,int y){
	e[x].push_back(y);
	e[y].push_back(x);
}
V init(){
	ans=INF;
	FOR(i,1,n)e[i].clear(),f[i]=g[i]=0;
	for(int x,y;--n;add_edge(x,y))
		x=getint(),y=getint();
}
V dfs1(int u,int fa=0){
	for(int v:e[u])if(v!=fa)
		dfs1(v,u),f[u]=max(f[u],f[v]+1);
}
V dfs2(int u,int fa=0){
	ans=min(ans,max(f[u],g[u]));
	int maxn=0,minn=0;
	for(int v:e[u])if(v!=fa)
		if(f[v]+1>=maxn)minn=maxn,maxn=f[v]+1;
		else if(f[v]+1>=minn)minn=f[v]+1;
	for(int v:e[u])if(v!=fa){
		if(f[v]+1==maxn)
			g[v]=max(g[u],minn)+1;
		else g[v]=max(g[u],maxn)+1;
		dfs2(v,u);
	}
}
V dfs0(int u,int d=0,int fa=0){
	if(u==tb)ans=d;
	for(int v:e[u])if(v!=fa)
		dfs0(v,d+1,u);
}
V work(){
	ans=0,dfs0(ta);
	if(ans<=da)return void(cout<<"Alice\n");
	if(da*2>=db)return void(cout<<"Alice\n");
	ans=INF,dfs1(1),dfs2(1);
	if(ans<=da)return void(cout<<"Alice\n");
	cout<<"Bob\n";
}
int main(){
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}