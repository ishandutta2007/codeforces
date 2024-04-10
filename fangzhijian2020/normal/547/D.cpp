#include<cstdio>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int cnt,*h;struct edge{int to,next;}*e;int *vis;
void add(int x,int y){e[++cnt]=(edge){y,h[x]};h[x]=cnt;}
void dfs(int x){
	int i,y;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;
		if(vis[y]==-1){
			vis[y]=vis[x]^1;dfs(y);
		}
	}
}
int main(){
	int n,x,y,pdx[200005]={0},pdy[200005]={0},_vis[200005]={0};
	int _h[200005]={0};edge _e[800005];
	n=read();h=_h,vis=_vis,e=_e;
	for(int i=1;i<=n;++i){
		x=read();y=read();vis[i]=-1;
		if(pdx[x]){add(pdx[x],i);add(i,pdx[x]);pdx[x]=0;}else pdx[x]=i;
		if(pdy[y]){add(pdy[y],i);add(i,pdy[y]);pdy[y]=0;}else pdy[y]=i;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]==-1)vis[i]=0,dfs(i);
		putchar(vis[i]?'r':'b');
	}
	return 0;
}