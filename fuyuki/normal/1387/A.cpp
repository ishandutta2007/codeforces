#include<bits/stdc++.h>
using namespace std;
#define ld double
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
const int N=2e5+1;
ld now,ans[N];
int n,m,tot,flag;
int h[N],tmp[N],dfn[N];
struct edge{int t,n,w;}e[N<<1];
struct node{
	int x,v;
	ld val(){return now*x+v;}
	node operator+(const node&u)const{return(node){x+u.x,v+u.v};}
	node operator-(const node&u)const{return(node){x-u.x,v-u.v};}
}f[N],val[3];
V test(int x){if(!x)printf("NO\n"),exit(0);}
V add_edge(int x,int y,int w){
	e[++tot]=(edge){y,h[x],w},h[x]=tot;
	e[++tot]=(edge){x,h[y],w},h[y]=tot;
}
V input(){
	scanf("%d%d",&n,&m);
	for(int x,y,w;m--;add_edge(x,y,w))scanf("%d%d%d",&x,&y,&w);
}
V init(){FOR(i,1,2)val[i].v=i;}
V dfs1(int u){
	dfn[u]=1;
	REP(u)
		if(dfn[v]==0)f[v]=val[e[i].w]-f[u],dfs1(v);
		else if(f[u].x+f[v].x==0)test(f[u].v+f[v].v==e[i].w);
		else{
			ld x=1.*(e[i].w-f[u].v-f[v].v)/(f[u].x+f[v].x);
			if(flag)test(abs(x-now)<=1e-6);
			else now=x,flag=1;
		}
	tmp[++tot]=-f[u].x*f[u].v;
}
V dfs2(int u){
	dfn[u]=2,ans[u]=f[u].val();
	REP(u)if(dfn[v]==1)dfs2(v);
}
V work(){
	FOR(i,1,n)if(!dfn[i]){
		flag=tot=0,dfn[i]=1,f[i].x=1,dfs1(i);
		if(!flag)sort(tmp+1,tmp+1+tot),now=tmp[tot+1>>1];
		dfs2(i);
	}
	printf("YES\n");
	FOR(i,1,n)printf("%.2lf ",ans[i]);
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}