#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int&i=h[u],p,v;v=e[p=i].t,i;i=e[i].n)
const int N=1<<20,sgn[]={1,-1};
int n,m,tot,h[N],d[N],a[N],b[N],out[N],vis[N];
struct edge{int t,n;}e[N<<1];
V input(){
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d%d",a+i,b+i);
}
V add_edge(int x,int y){
	e[++m]=(edge){y,h[x]},h[x]=m;
	e[++m]=(edge){x,h[y]},h[y]=m;
}
V dfs(int u){
	REP(u)if(!vis[i+1>>1])
		vis[i+1>>1]=1,dfs(v),out[++tot]=p-sgn[p&1],out[++tot]=p;
}
I check(int x){
	memset(h,0,x+1<<2),memset(vis,0,n+1<<2),tot=m=0;
	FOR(i,1,n)d[a[i]&=x]^=1,d[b[i]&=x]^=1,add_edge(a[i],b[i]);
	FOR(i,0,x)if(d[i])return memset(d,0,x+1<<2),0;
	return dfs(a[1]),tot==n*2;
}
V work(){
	ROF(i,20,0)if(check((1<<i)-1)){
		cout<<i<<'\n';
		FOR(j,1,tot)cout<<out[j]<<' ';
		return;
	}
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	work();
	return 0;
}