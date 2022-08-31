#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,fa[200002],ch[200002][2],C[200002],c[400002],tot,siz[400002],rev[200002],tg[400002];
inline bool ir(re int x){return (!fa[x])||(ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x);}
inline void pu(re int x){if(!x)return;siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;}
inline void add(re int x,re int y){for(;x<=400000;x+=x&(-x))c[x]+=y;}
inline int ask(re int x,re int s=0){for(;x;x^=x&(-x))s+=c[x];return s;}
inline void rot(re int x){
	re int y=fa[x],z=fa[y],R=ch[y][1]==x;
	if(!ir(y))ch[z][ch[z][1]==y]=x;
	fa[x]=z,fa[ch[x][R^1]]=y,ch[y][R]=ch[x][R^1],ch[x][R^1]=y,fa[y]=x;
	pu(y),pu(x);
}
inline void Pd(re int x){
	if(!ir(x))Pd(fa[x]);
	if(rev[x])swap(ch[x][0],ch[x][1]),rev[ch[x][0]]^=1,rev[ch[x][1]]^=1,rev[x]=0;
	if(tg[x])C[ch[x][0]]=C[ch[x][1]]=tg[ch[x][0]]=tg[ch[x][1]]=tg[x],tg[x]=0;
}
inline void splay(re int x){
	Pd(x);
	while(!ir(x)){
		re int y=fa[x],z=fa[y];
		if(!ir(y)){
			if((ch[y][1]==x)^(ch[z][1]==y))rot(x);
			else rot(y);
		}rot(x);
	}
}
inline void ac(re int x){
	for(re int y=0;x;y=x,x=fa[x]){
		splay(x);
		ch[x][1]=0,pu(x);
		if(C[x])add(C[x],-siz[x]);
		add(tot,siz[x]);
		ch[x][1]=y,pu(x);
	}
}
char s[12];
inline void mr(re int x){
	++tot,ac(x),splay(x),C[x]=tg[x]=tot,rev[x]^=1;
}
inline int askk(re int x){
	splay(x);
	return ask(C[x]-1)+siz[ch[x][1]]+1;
}
basic_string<int>G[200002];
inline void dfs(re int x,re int y){
	fa[x]=y;
	for(auto z:G[x])if(z^y)dfs(z,x);
}
int main(){
	n=read(),m=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),G[x]+=y,G[y]+=x;
	dfs(1,0);
	for(re int i=1;i<=n;++i)mr(i);
	while(m--){
		scanf("%s",s+1);
		if(s[1]=='u')mr(read());
		else if(s[1]=='w')printf("%d\n",askk(read()));
		else{
			re int x=read(),y=read();
			printf("%d\n",askk(x)<askk(y)?x:y);
		}
	}
}