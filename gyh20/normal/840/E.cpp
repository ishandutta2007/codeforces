#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[50002],fa[50002],F[50002],mx[50002][256],rt,tot,ch[50002][2],dep[50002],head[50002],cnt;
struct edge{int to,next;}e[100002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void Ins(re int x){
	re int nw=rt;
	for(re int j=15;~j;--j){
		re int o=(x>>j)&1;
		if(!ch[nw][o])ch[nw][o]=++tot;
		nw=ch[nw][o];
	}
}
inline int ask(re int x){
	re int nw=rt,s=0;
	for(re int j=15;~j;--j){
		re int o=(x>>j)&1;
		if(ch[nw][o^1])s+=1<<j,nw=ch[nw][o^1];
		else nw=ch[nw][o];
	}return s;
}
inline void dfs(re int x,re int y){
	re int z=x;fa[x]=y,dep[x]=dep[y]+1;
	for(re int i=1;i<=tot;++i)ch[i][0]=ch[i][1]=0;rt=tot=1;
	for(re int j=0;j<256;++j)Ins(a[z]^j),z=fa[z];
	for(re int j=0;j<256;++j)mx[x][j]=ask(j<<8);
	F[x]=z;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x);
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs(1,0);
	while(m--){
		re int x=read(),y=read(),s=0,num=0;
		while(dep[F[y]]>=dep[x])s=max(s,mx[y][num]),y=F[y],++num;num<<=8;
		while(dep[y]>=dep[x])s=max(s,a[y]^num),y=fa[y],++num;
		printf("%d\n",s);
	}
}