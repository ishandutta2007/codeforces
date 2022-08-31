#include<bits/stdc++.h>
#define re register
using namespace std;
int ch[400002][2],val[400002],fa[400002],n,rev[400002],stk[400002],tp,mn[400002],f[400002],rt[400002],siz[8000002],ls[8000002],rs[8000002],tot,m,q,typ,a[400002],b[400002],s[400002],la;
inline int root(re int x){return x==f[x]?x:f[x]=root(f[x]);}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline bool ir(re int x){return ch[fa[x]][1]!=x&&ch[fa[x]][0]!=x;}
inline void Rev(re int x){rev[x]^=1;}
inline void pd(re int x){if(rev[x])swap(ch[x][0],ch[x][1]),Rev(ch[x][0]),Rev(ch[x][1]),rev[x]=0;}
inline void pu(re int x){
	mn[x]=x;
	if(val[mn[ch[x][0]]]<val[mn[x]])mn[x]=mn[ch[x][0]];
	if(val[mn[ch[x][1]]]<val[mn[x]])mn[x]=mn[ch[x][1]];
}
inline void rotate(re int x){
	re int y=fa[x],z=fa[y],R=(ch[y][1]==x);
	if(!ir(y))ch[z][ch[z][1]==y]=x;
	fa[x]=z,fa[y]=x,fa[ch[x][R^1]]=y,ch[y][R]=ch[x][R^1],ch[x][R^1]=y;
	pu(y),pu(x);
}
inline void splay(re int x){
	tp=0,stk[++tp]=x;
	for(re int y=x;!ir(y);y=fa[y])stk[++tp]=fa[y];
	for(re int i=tp;i;--i)pd(stk[i]);
	while(!ir(x)){
		re int y=fa[x],z=fa[y];
		if(!ir(y)){
			if((ch[z][1]==y)^(ch[y][1]==x))rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}
inline void access(re int x){for(re int y=0;x;y=x,x=fa[x])splay(x),ch[x][1]=y,pu(x);}
inline void makeroot(re int x){access(x),splay(x),Rev(x);}
inline void split(re int x,re int y){makeroot(x),access(y),splay(y);}
inline void link(re int x,re int y){makeroot(x),fa[x]=y;}
inline void cut(re int x,re int y){split(x,y),ch[y][0]=0,fa[x]=0,pu(y);}
inline void ins(re int &p,re int q,re int l,re int r,re int x){
	if(!p)p=++tot;
	siz[p]=siz[q]+1;
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)rs[p]=rs[q],ins(ls[p],ls[q],l,mid,x);
	else ls[p]=ls[q],ins(rs[p],rs[q],mid+1,r,x);
}
inline int ask(re int p,re int q,re int l,re int r,re int x){
	if(r<=x)return siz[p]-siz[q];
	re int mid=l+r>>1;
	if(x>mid)return siz[ls[p]]-siz[ls[q]]+ask(rs[p],rs[q],mid+1,r,x);
	else return ask(ls[p],ls[q],l,mid,x);
}
int main(){
	n=read(),m=read(),val[0]=1e9;
	for(re int i=1;i<=n;++i)f[i]=i,val[i]=1e9;
	for(re int i=1,x,y,pos;i<=m+m;++i){
		if(i<=m)a[i]=x=read(),b[i]=y=read();
		else a[i]=x=a[i-m],b[i]=y=b[i-m];
		val[i+n]=i,mn[i+n]=i+n;
		if(x==y){
			ins(rt[i],rt[i-1],0,m+m,m+m);continue;
		}
		if(root(x)^root(y))link(x,i+n),link(i+n,y),f[root(x)]=root(y);
		else{
			split(x,y),pos=mn[y];
			s[i]=pos-n,cut(pos,a[pos-n]),cut(pos,b[pos-n]);
			link(x,i+n),link(i+n,y);
		}
		ins(rt[i],rt[i-1],0,m+m,s[i]);
	}
	q=read();
	while(q--){
		re int y=read()+m-1,x=read()+1;
		printf("%d\n",n-ask(rt[y],rt[x-1],0,m+m,x-1));
	}
}