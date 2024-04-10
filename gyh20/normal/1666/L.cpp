#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1000002],b[1000002],ans,head[200002],cnt,fa[200002],rt,C,v[200002];
struct edge{
	int to,next;
}e[400002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
vector<int>Ansa,Ansb;
inline void Go(re int x){
	if(x^rt)Go(fa[x]);
	Ansb.push_back(x);
}
inline void dfs(re int x,re int y){
	if(fa[x]){
		Go(x),Ansa=Ansb,Ansb.clear();
		Go(y),Ansb.push_back(x);
		puts("Possible");
		printf("%d\n",Ansa.size());
		for(re int j=0;j<Ansa.size();++j)printf("%d ",Ansa[j]);
		puts("");
		printf("%d\n",Ansb.size());
		for(re int j=0;j<Ansb.size();++j)printf("%d ",Ansb[j]);
		puts("");
		exit(0);
	}
	fa[x]=y,v[x]=C;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			if(v[e[i].to]!=C&&e[i].to!=rt)dfs(e[i].to,x);
}
int main(){
	n=read(),m=read(),rt=read();
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),add(x,y);
	dfs(rt,rt);
	for(re int i=head[rt];i;i=e[i].next)
		C=e[i].to,dfs(e[i].to,rt);
	puts("Impossible");
}