#include<cstdio>
#include<vector>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,dfn[2002],ist[2002],stk[2002],tp,tim,head[2002],m,cnt,low[2002],bl[2002],rd[2002],mx,rt,ans,lll;
vector<int>g[2002];
struct edge{int to,next;}e[200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]};head[x]=cnt;}
inline void tj(re int x,re int y){
	dfn[x]=low[x]=++tim,ist[stk[++tp]=bl[x]=x]=1;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y){if(!dfn[e[i].to])tj(e[i].to,x),low[x]=min(low[x],low[e[i].to]);else if(ist[e[i].to])low[x]=min(low[x],dfn[e[i].to]);}
	if(dfn[x]==low[x]){while(stk[tp]^x)bl[stk[tp--]]=x;--tp;}
}
inline void dfs(re int x,re int y,re int z){
	dfn[x]=lll;
	for(re int i=0;i<g[x].size();++i)if(g[x][i]^y)if(!dfn[g[x][i]])dfs(g[x][i],x,z+1);
	if(z>mx)mx=z,rt=x;
}
int main(){
	n=read(),m=read();re int ia=0;
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),add(x,y),add(y,x);
	for(re int i=1;i<=n;++i)if(!dfn[i])tj(i,i);
	for(re int i=1;i<=n;++i)for(re int j=head[i];j;j=e[j].next)if(bl[i]^bl[e[j].to])if(e[j].to>i)++rd[bl[i]],++rd[bl[e[j].to]],g[bl[i]].push_back(bl[e[j].to]),g[bl[e[j].to]].push_back(bl[i]);
	for(re int i=1;i<=n;++i)dfn[i]=0;
	for(re int i=1;i<=n;++i)
		if(bl[i]==i){
			if(rd[i]==1)--ans;
			if((!dfn[i])&&rd[i])lll=0,++ans,dfs(i,i,0),mx=0,lll=1,dfs(rt,rt,0),rt=0,ans-=mx-1,mx=0;
		}
	printf("%d",ans-1+n);
}