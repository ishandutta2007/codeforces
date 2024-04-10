#include<cstdio>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,dfn[600002],low[600002],bl[600002],cnt,st[600002],tp,q,head[600002],ist[600002],tot,tim,blk;
struct edge{int to,next;}e[1200002];
inline int min(re int x,re int y){return x<y?x:y;}
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void tj(re int x,re int y){
	dfn[x]=low[x]=++tim,ist[x]=1,st[++tp]=x;
	for(re int i=head[x];i;i=e[i].next)
		if(i^y){
			if(!dfn[e[i].to])tj(e[i].to,i^1),low[x]=min(low[x],low[e[i].to]);
			else if(ist[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
		}
	if(dfn[x]==low[x]){
		++blk;
		do{
			bl[st[tp]]=blk;
			ist[st[tp]]=0;
			--tp;
		}while(st[tp+1]^x);
	}
}
struct node{
	int x,y,tp;
}stk[600002];
namespace linkcuttree{
	int	ch[1200002][2],rev[1200002],fa[1200002],st[1200002],tp,mx[1200002],tg[1200002],sum[1200002],siz[1200002],a[1200002],val[1200002],C[1200002];
	inline bool ir(re int x){return !fa[x]||(ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x);}
	inline void cg(re int x,re int y){
		tg[x]=y--,val[x]=y,sum[x]=siz[x]*y;
	}
	inline void pd(re int x){
		if(rev[x]){
			ch[x][0]^=ch[x][1]^=ch[x][0]^=ch[x][1];
			rev[ch[x][0]]^=1,rev[ch[x][1]]^=1;
			rev[x]=0;
		}
		if(tg[x])cg(ch[x][0],tg[x]),cg(ch[x][1],tg[x]),tg[x]=0;
	}
	inline void pu(re int x){
		siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+a[x],sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+a[x]*val[x];
	}
	inline void rotate(re int x){
		re int y=fa[x],z=fa[y];re bool L=ch[y][1]==x,R=L^1;
		if(!ir(y))ch[z][ch[z][1]==y]=x;
		fa[x]=z,fa[y]=x;fa[ch[x][R]]=y,ch[y][L]=ch[x][R],ch[x][R]=y;
		pu(y);pu(x);
	}
	inline void splay(re int x){
		tp=1;st[1]=x;
		for(re int i=x;!ir(i);i=fa[i])st[++tp]=fa[i];
		for(re int i=tp;i;--i)pd(st[i]);
		while(!ir(x)){
			re int y=fa[x],z=fa[y];
			if(!ir(y)){
			if((ch[y][0]==x)^(ch[z][0]==y))rotate(x);
			else rotate(y);}rotate(x);
		}
	}
	inline void ac(re int x){for(re int y=0;x;y=x,x=fa[x])splay(x),ch[x][1]=y,pu(x);}
	inline void mr(re int x){ac(x);splay(x);rev[x]^=1;}
	inline void split(re int x,re int y){mr(x);ac(y);splay(y);}
	inline void link(re int x,re int y){mr(x);fa[x]=y;}
	inline int fr(re int x){ac(x),splay(x);while(ch[x][0])x=ch[x][0];return x;}
	inline void cut(re int x,re int y){split(x,y);if(ch[y][0]==x){fa[x]=0;ch[y][0]=0;}pu(y);}
	inline int ask(re int x,re int y){
		split(x,y);
		return sum[ch[y][0]];
	}
	inline void cg(re int x,re int y,re int z){
		split(x,y);
		cg(ch[y][0],z+1);
	}
};
long long R;
int rrr(int element){
   element=(element+R)%n;

   if (element==0) {
       element=n;
   }

   return element;
}
int main(){
using namespace linkcuttree;
	n=read(),m=read(),cnt=1;
	re int id=0;
	q=read();
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),add(x,y),add(y,x);
	for(re int i=1;i<=n;++i)if(!dfn[i])tj(i,0);tot=blk;
	for(re int i=1;i<=n;++i)for(re int j=head[i];j;j=e[j].next)if(bl[i]^bl[e[j].to])if(fr(bl[i])^fr(bl[e[j].to]))a[++tot]=1,val[tot]=1,link(bl[i],tot),link(bl[e[j].to],tot);
	while(q--){
		++id;
		re int A=read(),B=read();
		for(re int i=1;i<=A;++i)C[i]=rrr(read());
		for(re int i=1;i<=B;++i){
			stk[i].x=bl[rrr(read())],stk[i].y=bl[rrr(read())];
			if(fr(stk[i].x)==fr(stk[i].y))stk[i].tp=0,cg(stk[i].x,stk[i].y,0);
			else stk[i].tp=++tot,a[tot]=val[tot]=1,link(stk[i].x,tot),link(tot,stk[i].y);
		}
		re bool ia=1;
		for(re int i=1;i<A;++i)if(fr(bl[C[i]])^fr(bl[C[i+1]])||ask(bl[C[i]],bl[C[i+1]])>0)ia=0;
		puts(ia?"YES":"NO");
		if(ia)R+=id;
		for(re int i=B;i;--i){
			if(!stk[i].tp)cg(stk[i].x,stk[i].y,1);
			else cut(stk[i].x,stk[i].tp),cut(stk[i].tp,stk[i].y);
		}
	}
}