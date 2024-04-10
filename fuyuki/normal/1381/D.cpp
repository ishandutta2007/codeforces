#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1e5+1;
int n,S,T,flag;
vector<int>e[N];
int a[N],c[N],d[N],in[N],out[N];
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
V add_edge(int x,int y){e[x].push_back(y),e[y].push_back(x);}
V input(){
	scanf("%d%d%d",&n,&S,&T),flag=0;
	FOR(i,1,n)a[i]=c[i]=d[i]=in[i]=out[i]=0,e[i].clear();
	for(int x,y;--n;add_edge(x,y))scanf("%d%d",&x,&y);
}
I dfs1(int u,int fa=0){
	if(u==T)return a[++n]=u,d[u]=1;
	for(int v:e[u])if(v!=fa&&dfs1(v,u))return a[++n]=u,d[u]=1;
	return 0;
}
V dfs2(int u,int fa=0){for(int v:e[u])if(v!=fa)dfs2(v,u),cmax(in[u],in[v]+1);}
V dfs3(int u,int fa=0){
	int w[3]={out[u],-1,-1},x;
	for(int v:e[u])if(v!=fa&&(x=in[v]+2))FOR(i,0,2)if(x>w[i])swap(x,w[i]);
	for(int v:e[u])if(v!=fa)out[v]=(w[0]==in[v]+2?w[1]:w[0])+1,dfs3(v,u);
	flag|=w[2]>=n;
}
I dfs4(int u,int fa=0,int out=0){
	for(int v:e[u])if(v!=fa&&!d[v])cmax(out,dfs4(v,u)+1);
	return out;
}
V init(){dfs1(S),dfs2(S),dfs3(S);}
V work(){
	if(!flag)
		return void(cout<<"NO\n");
	FOR(i,1,n)c[i]=dfs4(a[i]);
	for(int L=1,R=n,l=0,r=n+1;l<L||R<r;){
		if(l<L)l++,cmin(R,n-c[l]+l-1);
		if(R<r)r--,cmax(L,c[r]-n+r+1);
		if(l>=r)return void(cout<<"YES\n");
	}
	cout<<"NO\n";
}
int main(){
//	freopen("test.in","r",stdin);
	for(int T=scanf("%d",&T)*T;T--;){
		input();
		init();
		work();
	}
	return 0;
}