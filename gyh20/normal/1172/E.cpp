#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct LCT{
	int fa[400002],siz[400002],ch[400002][2],V[400002];
	ll S[400002],SV[400002],SUM;
	inline bool ir(re int x){return !fa[x]||(ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x);}
	inline void pu(re int x){siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+V[x]+1,S[x]=SV[x]+1ll*siz[ch[x][0]]*siz[ch[x][0]]+1ll*siz[ch[x][1]]*siz[ch[x][1]];}
	inline void rot(re int x){
		re int y=fa[x],z=fa[y],R=ch[y][1]==x;
		if(!ir(y))ch[z][ch[z][1]==y]=x;
		fa[x]=z,fa[y]=x,fa[ch[x][R^1]]=y,ch[y][R]=ch[x][R^1],ch[x][R^1]=y;
		pu(y),pu(x);
	}
	inline void splay(re int x){
		while(!ir(x)){
			re int y=fa[x],z=fa[y];
			if(!ir(y)){
				if((ch[y][1]==x)^(ch[z][1]==y))rot(x);
				else rot(y);
			}rot(x);
		}
	}
	inline int fr(re int x){
		splay(x);
		while(ch[x][0])x=ch[x][0];
		return x;
	}
	inline void ac(re int x){for(re int y=0;x;y=x,x=fa[x])splay(x),V[x]-=siz[y],SV[x]-=1ll*siz[y]*siz[y],V[x]+=siz[ch[x][1]],SV[x]+=1ll*siz[ch[x][1]]*siz[ch[x][1]],ch[x][1]=y,pu(x);}
	inline void link(re int x,re int y){
		splay(x),SUM-=S[x];re int vv=siz[x];
		ac(y),splay(y),fa[x]=y,V[y]+=siz[x],SV[y]+=1ll*siz[x]*siz[x],pu(y);
		re int yy;ac(x),splay(yy=fr(x));SUM-=1ll*(siz[ch[yy][1]]-vv)*(siz[ch[yy][1]]-vv);
		SUM+=1ll*siz[ch[yy][1]]*siz[ch[yy][1]];
	}
	inline void cut(re int x,re int y){
		ac(x);re int yy=fr(x);splay(yy);SUM-=1ll*siz[ch[yy][1]]*siz[ch[yy][1]];re int vv=siz[ch[yy][1]];
		splay(y),ch[y][1]=fa[x]=0,pu(y);
		SUM+=S[x],SUM+=1ll*(vv-siz[x])*(vv-siz[x]);
	}
	inline int ask(re int x){
		ac(x),splay(x);
		while(ch[x][0])x=ch[x][0];
		splay(x);return siz[ch[x][1]];
	}
}T[2];
int c[400002],n,m,head[400002],fa[400002],cnt,a[400002];
ll ANS[400002];
struct node{int x,y,z;};
vector<node>V[400002];
struct edge{int to,next;}e[800002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	fa[x]=y;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			dfs(e[i].to,x);
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read(),V[a[i]].push_back((node){i,1,0});
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	for(re int i=1;i<=m;++i){
		re int x=read(),y=read();
		if(a[x]==y)continue;
		V[a[x]].push_back((node){x,0,i});
		V[y].push_back((node){x,1,i});
		a[x]=y;
	}
	dfs(1,n+1);
	for(re int i=1;i<=n+1;++i)T[0].siz[i]=T[1].siz[i]=1;
	for(re int i=1;i<=n;++i)T[0].link(i,fa[i]);
	for(re int i=1;i<=n;++i){
		re ll la=T[0].SUM;re int lp=0;
		int vv=V[i].size();
		for(re int j=0;j<vv;++j){
			if(V[i][j].y==1)T[V[i][j].y^1].cut(V[i][j].x,fa[V[i][j].x]);
			if(V[i][j].y==0)T[V[i][j].y].link(V[i][j].x,fa[V[i][j].x]);
			ANS[lp]+=la,ANS[V[i][j].z]-=la,la=T[0].SUM,lp=V[i][j].z;
		}
		ANS[lp]+=la;
		for(re int j=vv-1;j>=0;--j){
			if(V[i][j].y==0)T[V[i][j].y].cut(V[i][j].x,fa[V[i][j].x]);
			if(V[i][j].y==1)T[V[i][j].y^1].link(V[i][j].x,fa[V[i][j].x]);
		}
	}
	for(re int i=0;i<=m;++i){
		if(i)ANS[i]+=ANS[i-1];
		printf("%lld\n",1ll*n*n*n-ANS[i]);
	}
}